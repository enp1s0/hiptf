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
		HIPTF_HANDLE_ERROR(hipFree(ptr));
	}
};
template <class T>
class host_deleter {
public:
	void operator()(T* ptr){
		delete [] ptr;
	}
};

// unique pointer type for c++ 11
template <class T>
using device_unique_ptr = std::unique_ptr<T, device_deleter<T>>;
template <class T>
using host_unique_ptr = std::unique_ptr<T, host_deleter<T>>;

} // namespace memory
} // namespace hiptf

#endif /* end of include guard */
