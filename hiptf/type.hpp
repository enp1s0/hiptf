#ifndef __HIPTF_TYPE_HPP__
#define __HIPTF_TYPE_HPP__

#define CAST(from_t, to_t, func, val) \
	 template <> __host__ __device__ inline to_t cast<to_t>(const from_t val){return func;}
#define REINTERPRET(src_type, src_ty, dst_type, dst_ty) \
	 template <> __device__ inline dst_type reinterpret<dst_type>(const src_type a){return __##src_ty##_as_##dst_ty(a);}

namespace hiptf {
namespace type {

// cast
template <class T>  __host__ __device__ inline T cast(const int a);
template <class T>  __host__ __device__ inline T cast(const half a);
template <class T>  __host__ __device__ inline T cast(const float a);
template <class T>  __host__ __device__ inline T cast(const double a);

CAST(int, int, a, a);
CAST(int, half, __float2half(static_cast<float>(a)), a);
CAST(int, float, static_cast<float>(a), a);
CAST(int, double, static_cast<double>(a), a);

CAST(half, int, static_cast<int>(__half2float(a)), a);
CAST(half, half, a, a);
CAST(half, float, __half2float(a), a);
CAST(half, double, static_cast<double>(__half2float(a)), a);

CAST(float, int, static_cast<int>(a), a);
CAST(float, half, __float2half(a), a);
CAST(float, float, a, a);
CAST(float, double, static_cast<double>(a), a);

CAST(double, int, static_cast<int>(a), a);
CAST(double, half, __half2float(static_cast<float>(a)), a);
CAST(double, float, static_cast<float>(a), a);
CAST(double, double, a, a);


} // namespace type
} // namespace hiptf

#endif /* end of include guard */
