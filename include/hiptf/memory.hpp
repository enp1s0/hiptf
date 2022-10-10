#ifndef __HIPTF_MEMORY_HPP__
#define __HIPTF_MEMORY_HPP__
#include <memory>
#include "hip.hpp"
#include "error.hpp"

namespace hiptf {
namespace memory {
// deleter
template <class T>
class device_deleter {
public:
	void operator()(T* ptr){
		HIPTF_CHECK_ERROR(hipFree(ptr));
	}
};
template <class T>
class host_deleter {
public:
	void operator()(T* ptr){
		HIPTF_CHECK_ERROR(hipHostFree(ptr));
	}
};

// unique pointer type for c++ 11
template <class T>
using device_unique_ptr = std::unique_ptr<T, device_deleter<T>>;
template <class T>
using host_unique_ptr = std::unique_ptr<T, host_deleter<T>>;

// allocater
template <class T>
inline device_unique_ptr<T> get_device_unique_ptr(const std::size_t size){
	T* ptr;
	HIPTF_CHECK_ERROR_M(hipMalloc((void**)&ptr, sizeof(T) * size), "Failed to allocate " + std::to_string(size * sizeof(T)) + " Bytes of device memory");
	return std::unique_ptr<T, device_deleter<T>>{ptr};
}
template <class T>
inline host_unique_ptr<T> get_host_unique_ptr(const std::size_t size){
	T* ptr;
	HIPTF_CHECK_ERROR_M(hipHostMalloc((void**)&ptr, sizeof(T) * size), "Failed to allocate " + std::to_string(size * sizeof(T)) + " Bytes of host memory");
	return std::unique_ptr<T, host_deleter<T>>{ptr};
}

// copy
template <class T>
inline hipError_t copy(T* const dst, const T* const src, const std::size_t size){
	return hipMemcpy(dst, src, sizeof(T) * size, hipMemcpyDefault);
}

// asynchronous copy
template <class T>
inline hipError_t copy_async(T* const dst, const T* const src, const std::size_t size, hipStream_t stream = 0){
	return hipMemcpyAsync(dst, src, sizeof(T) * size, hipMemcpyDefault, stream);
}

} // namespace memory
} // namespace hiptf

#endif /* end of include guard */
