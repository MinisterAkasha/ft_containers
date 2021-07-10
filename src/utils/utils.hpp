#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {
	template<bool Cond, class T = void>
	struct enable_if {};
	
    template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <bool is_integral, typename T>
	class is_integral_struct {
		public:
			typedef T type;
			static const bool value = is_integral;
	};

	template <typename>
	class is_integral : public is_integral_struct<false, bool> {};

	template <>
	class is_integral<bool> : public is_integral_struct<true, bool> {};

	template <>
	class is_integral<int> : public is_integral_struct<true, int> {};

	template <>
	class is_integral<char> : public is_integral_struct<true, char> {};

	template <>
	class is_integral<unsigned char> : public is_integral_struct<true, unsigned char> {};

	template <>
	class is_integral<signed char> : public is_integral_struct<true, signed char> {};

	template <>
	class is_integral<short int> : public is_integral_struct<true, short int> {};

	template <>
	class is_integral<long int> : public is_integral_struct<true, long int> {};

	template <>
	class is_integral<long long int> : public is_integral_struct<true, long long int> {};

	template <>
	class is_integral<unsigned int> : public is_integral_struct<true, unsigned int> {};

	template <>
	class is_integral<unsigned long int> : public is_integral_struct<true, unsigned long int> {};

	template <>
	class is_integral<unsigned long long int> : public is_integral_struct<true, unsigned long long int> {};

}

#endif