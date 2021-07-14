# include "vector.hpp"

namespace ft {

	/*
	** Constructor
	*/

	template <class T, class Container>
	stack<T, Container>::stack(const container_type& ctnr) : _c(ctnr) {}

	template <class T, class Container>
	bool stack<T, Container>::empty() const {
		return _c.empty();
	}

	template <class T, class Container>
	typename stack<T, Container>::size_type	stack<T, Container>::size() const {
		return _c.size();
	}

	template <class T, class Container>
	typename stack<T, Container>::value_type&	stack<T, Container>::top() {
		return _c.back();
	}

	template <class T, class Container>
	const typename stack<T, Container>::value_type&	stack<T, Container>::top() const {
		return _c.back();
	}
	
	template <class T, class Container>
	void stack<T, Container>::push(const value_type& val) {
		_c.push_back(val);
	}
	
	template <class T, class Container>
	void stack<T, Container>::pop() {
		_c.pop_back(val);
	}
	
}