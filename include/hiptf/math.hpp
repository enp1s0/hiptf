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

// Unary functions
MATH_FUNC_1(acos);
MATH_FUNC_1(acosh);
MATH_FUNC_1(asin);
MATH_FUNC_1(asinh);
MATH_FUNC_1(atan);
MATH_FUNC_1(atanh);
MATH_FUNC_1(ceil);
MATH_FUNC_1(cbrt);
MATH_FUNC_1(cos);
MATH_FUNC_1(cosh);
MATH_FUNC_1(erfc);
MATH_FUNC_1(erf);
MATH_FUNC_1(exp10);
MATH_FUNC_1(exp2);
MATH_FUNC_1(exp);
MATH_FUNC_1(expm1);
MATH_FUNC_1(fabs);
MATH_FUNC_1(floor);
MATH_FUNC_1(log10);
MATH_FUNC_1(log1p);
MATH_FUNC_1(logb);
MATH_FUNC_1(log2);
MATH_FUNC_1(log);
MATH_FUNC_1(round);
MATH_FUNC_1(sin);
MATH_FUNC_1(sinh);
MATH_FUNC_1(sqrt);
MATH_FUNC_1(tan);
MATH_FUNC_1(tanh);
MATH_FUNC_1(trunc);
MATH_FUNC_1(erfcinv);
MATH_FUNC_1(erfcx);
MATH_FUNC_1(erfinv);
MATH_FUNC_1(j0);
MATH_FUNC_1(j1);
MATH_FUNC_1(lgamma);
MATH_FUNC_1(nextafter);
MATH_FUNC_1(normcdf);
MATH_FUNC_1(normcdfinv);
MATH_FUNC_1(rcbrt);
MATH_FUNC_1(rint);
MATH_FUNC_1(y0);
MATH_FUNC_1(y1);

// Binary functions
MATH_FUNC_2(atan2);
MATH_FUNC_2(copysign);
MATH_FUNC_2(fdim);
MATH_FUNC_2(fmax);
MATH_FUNC_2(fmin);
MATH_FUNC_2(fmod);
MATH_FUNC_2(hypot);
MATH_FUNC_2(pow);
MATH_FUNC_2(fdivide);
MATH_FUNC_2(rhypot);

} // namespace math
} // namespace hiptf

#endif /* end of include guard */
