#ifndef __HIPTF_ERROR_HPP__
#define __HIPTF_ERROR_HPP__

#ifndef HIPTF_HANDLE_ERROR
#define HIPTF_HANDLE_ERROR(status) hiptf::error::check(status, __FILE__, __LINE__, __func__)
#endif
#ifndef HIPTF_HANDLE_ERROR_M
#define HIPTF_HANDLE_ERROR_M(status, message) hiptf::error::check(status, __FILE__, __LINE__, __func__, message)
#endif

#endif /* end of include guard */
