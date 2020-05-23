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
constexpr float PI = 3.f;
constexpr std::size_t N = 15;

using compute_t = float;
int main(){
	auto dA = hiptf::memory::get_device_unique_ptr<compute_t>(N);
	auto dB = hiptf::memory::get_device_unique_ptr<compute_t>(N);
}
```

## Namespace structure
```
hiptf
├─ memory
├─ hip
├─ type
└─ error
```

## Smart pointers
[Smart pointers Reference](./docs/smart_ptr.md)

## CUDA Functions

## License
Copyright (c) 2018 - 2019 tsuki (enp1s0)  
Released under the MIT license  
<img src="http://momo86.net/ipsolab.svg" width="120">
