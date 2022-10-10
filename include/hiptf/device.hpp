#ifndef __HIPTF_DEVICE_HPP__
#define __HIPTF_DEVICE_HPP__
#include <cstddef>
#include <functional>
#include <vector>
#include <hip/hip_runtime.h>

namespace hiptf {
namespace device {
inline std::vector<hipDeviceProp_t> get_properties_vector(){
	int n;
	hipGetDeviceCount(&n);
	std::vector<hipDeviceProp_t> properties_vector;
	for(int i = 0; i < n; i++){
		hipDeviceProp_t property;
		hipGetDeviceProperties(&property, i);
		properties_vector.push_back(property);
	}

	return properties_vector;
}

inline std::size_t get_num_devices() {
	int n;
	hipGetDeviceCount(&n);
	return static_cast<std::size_t>(n);
}

inline hipError_t use_device(const int device_id, const std::function<void(void)> function){
	int current_device_id;
	hipError_t result;
	result = hipGetDevice(&current_device_id);
	if(result != hipSuccess) {return result;}
	result = hipSetDevice(device_id);
	if(result != hipSuccess) {return result;}
	function();
	result = hipSetDevice(current_device_id);
	if(result != hipSuccess) {return result;}

	return hipSuccess;
}
} // namespace device
} // namespace hiptf

#endif /* end of include guard */
