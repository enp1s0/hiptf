#ifndef __HIPTF_MACRO_HPP__
#define __HIPTF_MACRO_HPP__

#if !defined(HIPTF_DEVICE_HOST_FUNC) && defined(__HIPCC__)
#define HIPTF_DEVICE_HOST_FUNC __device__ __host__
#elif !defined(HIPTF_DEVICE_HOST_FUNC)
#define HIPTF_DEVICE_HOST_FUNC
#endif

#if !defined(HIPTF_DEVICE_FUNC) && defined(__HIPCC__)
#define HIPTF_DEVICE_FUNC __device__
#elif !defined(HIPTF_DEVICE_FUNC)
#define HIPTF_DEVICE_FUNC
#endif

// This macro prevents a warning "Unused variable"
#define HIPTF_UNUSED(a) do {(void)(a);} while (0)

#endif // __HIPTF_MACRO_HPP__
