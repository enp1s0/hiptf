#include <iostream>
#include <cmath>
#include <hip/hip_runtime.h>
#include <hip/hip_runtime_api.h>
#include <hiptf/memory.hpp>
#include <hiptf/math.hpp>
#include <hiptf/error.hpp>

constexpr std::size_t N = 1 << 18;
constexpr std::size_t threads_per_block = 1 << 8;

using compute_t = float;

__global__ void sin_kernel(compute_t* const dst_ptr, const compute_t* const src_ptr) {
	const auto tid = hipThreadIdx_x + hipBlockIdx_x * hipBlockDim_x;

	dst_ptr[tid] = hiptf::math::sin<compute_t>(src_ptr[tid]);
}

int main(){
	auto dA = hiptf::memory::get_device_unique_ptr<compute_t>(N);
	auto dB = hiptf::memory::get_device_unique_ptr<compute_t>(N);
	auto hA = hiptf::memory::get_host_unique_ptr<compute_t>(N);
	auto hB = hiptf::memory::get_host_unique_ptr<compute_t>(N);

	for (std::size_t i = 0; i < N; i++) {
		hA.get()[i] = static_cast<compute_t>(i) / N * M_PI;
	}

	hiptf::memory::copy(dA.get(), hA.get(), N);
	hipLaunchKernelGGL(sin_kernel, dim3(N / threads_per_block, 1, 1), dim3(threads_per_block, 1, 1), 0, 0, dB.get(), dA.get());
	hiptf::memory::copy(hB.get(), dB.get(), N);

	double max_error = 0;
	for (std::size_t i = 0; i < N; i++) {
		max_error = std::max<double>(max_error, std::abs(hB.get()[i] - std::sin(hA.get()[i])));
	}
	std::printf("max_error = %e\n", max_error);
}
