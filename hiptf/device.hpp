#ifndef __HIPTF_DEVICE_HPP__
#define __HIPTF_DEVICE_HPP__
#include <cstddef>
#include <hip/hip_runtime.h>

namespace hiptf {
namespace device {
inline std::size_t get_num_devices() {
	int n;
	hipGetDeviceCount(&n);
	return static_cast<std::size_t>(n);
}
} // namespace device
} // namespace hiptf

#endif /* end of include guard */
