#ifndef __HIPTF_STREAM_HPP__
#define __HIPTF_STREAM_HPP__
#include <memory>
#include "hip.hpp"

namespace hiptf{
namespace stream{
struct stream_deleter{
	void operator()(hipStream_t *stream){
		hipStreamDestroy(*stream);
		delete stream;
	}
};

using stream_unique_ptr = std::unique_ptr<hipStream_t, stream_deleter>;

inline stream_unique_ptr get_stream_unique_ptr(const int device_id = 0){
	int original_device_id;
	hiptf::error::check(hipGetDevice(&original_device_id), __FILE__, __LINE__, __func__, "@ Creating stream for device " + std::to_string(device_id));
	hiptf::error::check(hipSetDevice(device_id), __FILE__, __LINE__, __func__, "@ Creating stream for device " + std::to_string(device_id));
	stream_unique_ptr stream(new hipStream_t);
	hiptf::error::check(hipStreamCreate(stream.get()), __FILE__, __LINE__, __func__, "@ Creating stream for device " + std::to_string(device_id));
	hiptf::error::check(hipSetDevice(original_device_id), __FILE__, __LINE__, __func__, "@ Creating stream for device " + std::to_string(device_id));
	return stream;
}
} // stream
} // hiptf

#endif // __HIPTF_STREAM_HPP__
