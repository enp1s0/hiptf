#include <iostream>
#include <hiptf/memory.hpp>

constexpr std::size_t N = 1 << 17;
constexpr std::size_t threads_per_block = 1 << 8;

template <class T, std::size_t N>
__global__ void pow2_kernel(T* const C){
	const auto tid = blockIdx.x * blockDim.x + threadIdx.x;
	if(tid >= N) return;

	const auto c = __ldg(C + tid);

	C[tid] = c * c;
}

using compute_t = float;
int main(){
	auto dA = hiptf::memory::get_device_unique_ptr<compute_t>(N);
	auto dB = hiptf::memory::get_device_unique_ptr<compute_t>(N);
	auto hA = hiptf::memory::get_host_unique_ptr<compute_t>(N);
	auto hB = hiptf::memory::get_host_unique_ptr<compute_t>(N);

	auto streamA = hiptf::stream::get_stream_unique_ptr();
	auto streamB = hiptf::stream::get_stream_unique_ptr();


	for(auto i = decltype(N)(0); i < N; i++){
		hA.get()[i] = hiptf::type::cast<compute_t>(1.0f * i / N);
		hB.get()[i] = hiptf::type::cast<compute_t>(1.0f * (N - i) / N);
	}

	hiptf::memory::copy_async(dA.get(), hA.get(), N, *streamA.get());
	hiptf::memory::copy_async(dB.get(), hB.get(), N, *streamB.get());

	pow2_kernel<compute_t, N><<<(N + threads_per_block - 1) / threads_per_block, threads_per_block, 0, *streamA.get()>>>(dA.get());
	pow2_kernel<compute_t, N><<<(N + threads_per_block - 1) / threads_per_block, threads_per_block, 0, *streamB.get()>>>(dB.get());

	hiptf::memory::copy_async(dA.get(), hA.get(), N, *streamA.get());
	hiptf::memory::copy_async(dB.get(), hB.get(), N, *streamB.get());
}
