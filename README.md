<img src="./docs/hiptf-logo.png" width="150">


# hiptf - HIP Template Functions
*The library of the HIP/C++ Otaku, by the HIP/C++ Otaku(?), for the HIP/C++ Otaku shall not perish from the earth.*

## Introduction
cutf is a tiny HIP template library.

- header file only
- at least C++11

## Development
- release/devel : [GitLab momo86.net - mutsuki/hiptf](https://gitlab.momo86.net/mutsuki/hiptf)

## Example
```cpp
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
```

## Namespace structure
```
hiptf
├─ hip
├─ math
├─ memory
├─ rsmi
├─ stream
├─ type
└─ error
```

## Smart pointers
[Smart pointers Reference](./docs/smart_ptr.md)

## HIP Functions
[hiptf HIP Functions Reference](./docs/hip.md)

## License
Copyright (c) 2018 - 2020 tsuki (enp1s0)  
Released under the MIT license  
<img src="http://momo86.net/ipsolab.svg" width="120">
