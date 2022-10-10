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
}
