#ifndef __HIPTF_DEBUG_MATRIX_HPP__
#define __HIPTF_DEBUG_MATRIX_HPP__
#include <cstddef>
#include <stdio.h>
#include "../type.hpp"
#include "../macro.hpp"
#include "../memory.hpp"

namespace hiptf {
namespace debug {
namespace print {

template <class T>
HIPTF_DEVICE_HOST_FUNC inline void print_matrix(const T* const ptr, const std::size_t m, const std::size_t n, const std::size_t ldm, const char* const name = nullptr) {
	if(name != nullptr) printf("%s = \n", name);
	for(std::size_t i = 0; i < m; i++) {
		for(std::size_t j = 0; j < n; j++) {
			const auto val = hiptf::type::cast<float>(ptr[j * ldm + i]);
			printf("%+e ", val);
		}
		printf("\n");
	}
}

template <class T>
HIPTF_DEVICE_HOST_FUNC inline void print_matrix(const T* const ptr, const std::size_t m, const std::size_t n, const char* const name = nullptr) {
	print_matrix(ptr, m, n, m, name);
}

template <class T>
HIPTF_DEVICE_HOST_FUNC inline void print_numpy_matrix(const T* const ptr, const std::size_t m, const std::size_t n, const std::size_t ldm, const char* const name = nullptr) {
	if(name != nullptr) printf("%s = ", name);
	printf("[");
	for(std::size_t i = 0; i < m; i++) {
		printf("[");
		for(std::size_t j = 0; j < n; j++) {
			const auto val = hiptf::type::cast<float>(ptr[j * ldm + i]);
			printf("%+e,", val);
		}
		printf("],\n");
	}
	printf("]\n");
}

template <class T>
HIPTF_DEVICE_HOST_FUNC inline void print_numpy_matrix(const T* const ptr, const std::size_t m, const std::size_t n, const char* const name = nullptr) {
	print_numpy_matrix(ptr, m, n, m, name);
}

// For device moery
template <class T>
inline void print_matrix_from_host(const T* const ptr, const std::size_t m, const std::size_t n, const std::size_t ldm, const char* const name = nullptr) {
	HIPTF_CHECK_ERROR(hipDeviceSynchronize());
	auto host_uptr = hiptf::memory::get_host_unique_ptr<T>(ldm * n);
	HIPTF_CHECK_ERROR(hiptf::memory::copy(host_uptr.get(), ptr, ldm * n));

	print_matrix(host_uptr.get(), m, n, ldm, name);
}

template <class T>
inline void print_matrix_from_host(const T* const ptr, const std::size_t m, const std::size_t n, const char* const name = nullptr) {
	HIPTF_CHECK_ERROR(hipDeviceSynchronize());
	auto host_uptr = hiptf::memory::get_host_unique_ptr<T>(m * n);
	HIPTF_CHECK_ERROR(hiptf::memory::copy(host_uptr.get(), ptr, m * n));

	print_matrix(host_uptr.get(), m, n, name);
}

template <class T>
inline void print_numpy_matrix_from_host(const T* const ptr, const std::size_t m, const std::size_t n, const std::size_t ldm, const char* const name = nullptr) {
	HIPTF_CHECK_ERROR(hipDeviceSynchronize());
	auto host_uptr = hiptf::memory::get_host_unique_ptr<T>(ldm * n);
	HIPTF_CHECK_ERROR(hiptf::memory::copy(host_uptr.get(), ptr, ldm * n));

	print_numpy_matrix(host_uptr.get(), m, n, ldm, name);
}

template <class T>
inline void print_numpy_matrix_from_host(const T* const ptr, const std::size_t m, const std::size_t n, const char* const name = nullptr) {
	HIPTF_CHECK_ERROR(hipDeviceSynchronize());
	auto host_uptr = hiptf::memory::get_host_unique_ptr<T>(m * n);
	HIPTF_CHECK_ERROR(hiptf::memory::copy(host_uptr.get(), ptr, m * n));

	print_numpy_matrix(host_uptr.get(), m, n, name);
}
} // namespace print
} // namespace debug
} // namespace hiptf

#endif /* end of include guard */
