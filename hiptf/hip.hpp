#ifndef __HIPTF_HIP_HPP__
#define __HIPTF_HIP_HPP__
#include <stdexcept>
#include <sstream>
#include <hip/hip_runtime.h>

namespace hiptf {
namespace error {

void check(const hipError_t state, const std::string filename, const std::size_t line, const std::string funcname, const std::string message = "") {
	if (state != hipSuccess) {
		std::stringstream ss;
		ss<< hipGetErrorString(state);
		if(message.length() != 0){
			ss<<" : "<<message;
		}
		ss<<" ["<<filename<<":"<<line<<" in "<<funcname<<"]";
		throw std::runtime_error(ss.str());
	}
}

} // namespace hip
} // namespace hiptf

#endif /* end of include guard */
