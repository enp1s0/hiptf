#ifndef __HIPTF_RSMI_HPP__
#define __HIPTF_RSMI_HPP__
#include <stdexcept>
#include <sstream>
#include <rocm_smi/rocm_smi.h>
#include "error.hpp"

namespace hiptf {
namespace error {
void check(const rsmi_status_t state, const std::string filename, const std::size_t line, const std::string funcname, const std::string message = "") {
	if (state != RSMI_STATUS_SUCCESS) {
		const char *err_str;
		std::stringstream ss;
rsmi_status_string(state, &err_str);
		ss << err_str;
		if(message.length() != 0){
			ss<<" : "<<message;
		}
		ss<<" ["<<filename<<":"<<line<<" in "<<funcname<<"]";
		throw std::runtime_error(ss.str());
	}
}
} // namespace error
} // namespace hiptf
#endif
