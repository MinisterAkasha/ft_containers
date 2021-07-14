#ifndef STACK_HPP
# define STACK_HPP

# include "utils.hpp"
# include "vector.hpp"
# include <memory>

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		explicit stack(const container_type& ctnr = container_type());

		/*
		** Member functions
		*/

		bool 					empty() const;
		size_type 				size() const;
		value_type& 			top();
		const value_type& 		top() const;
		void 					push(const value_type& val);
		void 					pop();
	
		private:
			container_type _c;
	};

	/*
	** Non-member functions
	*/

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

# include "stack.inl"

#endif