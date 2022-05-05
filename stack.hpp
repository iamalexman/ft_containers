#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft {
	template <typename T, class Container = ft::vector <T> >
	class stack {
	public:
		typedef T				value_type;
		typedef size_t			size_type;
		typedef Container		container_type;

	protected:
		container_type c;

	public:
		explicit stack(const container_type& x = container_type()) : c(x) {};

	//	************ funcs **********

		bool empty() const {
			return c.empty();
		}

		size_type size() const {
			return c.size();
		}

		value_type& top() {
			return c.back();
		}

		const value_type& top() const {
			return c.back();
		}

		void push(const value_type& x) {
			c.push_back(x);
		}

		void pop() {
			c.pop_back();
		}

		friend bool operator==(const stack <T, Container>& x, const stack <T, Container>& y) {
			return x.c == y.c;
		}

		friend bool operator<(const stack <T, Container>& x, const stack <T, Container>& y) {
			return x.c < y.c;
		}

		friend bool operator!=(const stack <T, Container>& x, const stack <T, Container>& y) {
			return x.c != y.c;
		}

		friend bool operator>(const stack <T, Container>& x, const stack <T, Container>& y) {
			return x.c > y.c;
		}

		friend bool operator>=(const stack <T, Container>& x, const stack <T, Container>& y) {
			return x.c >= y.c;
		}

		friend bool operator<=(const stack <T, Container>& x, const stack <T, Container>& y) {
			return x.c <= y.c;
		}
	};
}
