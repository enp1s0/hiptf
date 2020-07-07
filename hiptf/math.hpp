#ifndef __HIPTF_MATH_HPP__
#define __HIPTF_MATH_HPP__
#include <hip/hip_runtime.h>

#define DEF_TEMPLATE_MATH_FUNC_1(func) \
template<class T>  __device__ inline T func(const T a);

#define SPEC_MATH_FUNC_1_f( func ) \
template<>  __device__ inline float func<float>(const float a){return func##f(a);}
#define SPEC_MATH_FUNC_1_d( func ) \
template<>  __device__ inline double func<double>(const double a){return func(a);}

#define MATH_FUNC_1(func) \
	DEF_TEMPLATE_MATH_FUNC_1(func) \
	SPEC_MATH_FUNC_1_f(func) \
	SPEC_MATH_FUNC_1_d(func)

#define DEF_TEMPLATE_MATH_FUNC_2(func) \
template<class T>  __device__ inline T func(const T a, const T b);

#define SPEC_MATH_FUNC_2_f( func ) \
template<>  __device__ inline float func<float>(const float a, const float b){return func##f(a, b);}
#define SPEC_MATH_FUNC_2_d( func ) \
template<>  __device__ inline double func<double>(const double a, const double b){return func(a, b);}

#define MATH_FUNC_2(func) \
	DEF_TEMPLATE_MATH_FUNC_2(func) \
	SPEC_MATH_FUNC_2_f(func) \
	SPEC_MATH_FUNC_2_d(func)

namespace hiptf {
namespace math {

} // namespace math
} // namespace hiptf

#endif /* end of include guard */
