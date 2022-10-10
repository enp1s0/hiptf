#include <iostream>
#include <hip/hip_runtime.h>
#include <hip/hip_runtime_api.h>
#include <hiptf/memory.hpp>
#include <hiptf/type.hpp>

constexpr std::size_t N = 1 << 17;
constexpr std::size_t threads_per_block = 1 << 8;

__global__ void type_cast_kernel(float* const dst_ptr, const double* const src_ptr) {
	const auto tid = hipThreadIdx_x + hipBlockIdx_x * hipBlockDim_x;

	dst_ptr[tid] = hiptf::type::cast<float>(src_ptr[tid]);
}

int main(){
	auto dA = hiptf::memory::get_device_unique_ptr<float>(N);
	auto dB = hiptf::memory::get_device_unique_ptr<double>(N);

	hipLaunchKernelGGL(type_cast_kernel, dim3(N / threads_per_block, 1, 1), dim3(threads_per_block, 1, 1), 0, 0, dA.get(), dB.get());
}
