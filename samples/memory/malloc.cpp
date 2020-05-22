#include <iostream>
#include <hiptf/memory.hpp>

constexpr std::size_t N = 1 << 17;
constexpr std::size_t threads_per_block = 1 << 8;

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
}
