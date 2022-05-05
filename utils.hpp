#pragma once

#include "traits.hpp"

namespace ft {
    template <class T>
	struct switch_const {
		typedef T type;
	};

    template <class T>
	struct switch_const<const T> {
		typedef T type;
	};

	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T>
	struct less : binary_function <T, T, bool> {
		bool operator()(const T& x, const T& y) const {
			return x < y;
		}
	};

//	Creates an integer constant from type and value.
    template <class T, bool val>
    struct integral_constant {
        static const bool value = val; // refers not to an instance but to the class itself, don't need to create an instance to refer to the parameter, const is at compile time and cannot be changed
        typedef T					value_type;
        typedef integral_constant	type;

        operator value_type() const {
			return value;
		}
    };

//	An instance of a type predicate has the value true if type T is a form of one of the integer types, otherwise it has the value false.
    template <class T>
	struct is_integral : public ft::integral_constant<T, false> {};

	template <>
	struct is_integral<bool> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<signed char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<short> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned short> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<long long> : public ft::integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long long> : public ft::integral_constant<bool, true> {};

//	"Metaprogramming" - compile-time programming
//	SFINAE  — substitution failure is not an error
    template <bool Condition, class T = void> // compile time error is not an error
    struct enable_if {};

//	Specialisation enable_if
    template <class T>
    struct enable_if<true, T> {
		typedef T type;
	};

//	Compares corresponding pairs of elements from two sequences bounded by ranges [first1, last1] and [first2, last2]. The comparison continues until the first pair of different elements is found, the pair [last1,last2] is reached, or at least one of the elements last1 or last2 (if the sequences have different lengths).
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
        for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
        for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
            if (comp(*first1 < *first2))
                return true;
            if (comp(*first2 < *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
        for(; first1 != last1; ++first1, ++first2) {
            if(!(*first1 == *first2)) {
                return false;
            }
        }
        return true;
    }

    template <class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate predicate) {
        for(; first1 != last1; ++first1, ++first2) {
            if(!predicate(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }

//	Distance between two iterators in size_type value.
	template <class InputIt1, class InputIt2>
	size_t distance(InputIt1 first, InputIt2 last) {
		size_t distance = 0;

		for(; first != last; ++first)
			distance++;
		return distance;
	}
}
