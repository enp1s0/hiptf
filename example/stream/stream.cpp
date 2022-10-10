#include <iostream>
#include <hiptf/memory.hpp>
#include <hiptf/stream.hpp>

constexpr std::size_t N = 1 << 17;

using compute_t = float;
int main(){
	auto dA = hiptf::memory::get_device_unique_ptr<compute_t>(N);
	auto hA = hiptf::memory::get_host_unique_ptr<compute_t>(N);

	auto stream = hiptf::stream::get_stream_unique_ptr();

	hiptf::memory::copy_async(dA.get(), hA.get(), N, *stream.get());
}
