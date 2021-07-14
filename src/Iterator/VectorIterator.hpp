#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "IteratorTraits.hpp"


namespace ft {

	template <typename T>
	class VectorIterator : public ft::iterator<ft::random_access_iterator_tag, T> {
		public:
			typedef	T																				value_type;
			typedef T*																				pointer;
			typedef T&																				reference;
			typedef ptrdiff_t																		difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		public:
			VectorIterator() : _ptr(nullptr) {};

			VectorIterator(T* ptr) : _ptr(ptr) {};

			template <class _U>
			VectorIterator(const VectorIterator<_U>& other) : _ptr(other._ptr) {};

			~VectorIterator() {};

			VectorIterator& 	operator=(const VectorIterator& other)  {
				if (this != &other)
					_ptr = other._ptr;
				return *this;
			}

			reference			operator*() const {
				return *_ptr;
			}
			pointer				operator->() const {
				return _ptr;
			}

			VectorIterator& 	operator++() {
				_ptr++;
				return *this;
			}
			VectorIterator& 	operator--() {
				_ptr--;
				return *this;
			}
			VectorIterator 		operator++(int) {
				VectorIterator tmp = VectorIterator(*this);

				_ptr++;
				return tmp;
			}
			VectorIterator 		operator--(int) {
				VectorIterator tmp = VectorIterator(*this);

				_ptr--;
				return tmp;
			}

			bool 				operator==(const VectorIterator& other) const {
				return _ptr == other._ptr;
			}
        	bool 				operator!=(const VectorIterator& other) const {
				return _ptr != other._ptr;
			}

        	bool 				operator>(const VectorIterator& other) const {
				return _ptr > other._ptr;
			}
        	bool 				operator>=(const VectorIterator& other) const {
				return _ptr >= other._ptr;
			}
        	bool 				operator<(const VectorIterator& other) const {
				return _ptr < other._ptr;	
			}
        	bool 				operator<=(const VectorIterator& other) const {
				return _ptr <= other._ptr;
			}

			VectorIterator&		operator-=(difference_type n) {
				_ptr -= n;
				return *this;
			}
			VectorIterator&		operator+=(difference_type n) {
				_ptr += n;
				return *this;
			}
			
			VectorIterator 		operator-(difference_type n) const {
				return _ptr - n;
			}
			VectorIterator 		operator+(difference_type n) const {
				return _ptr + n;
			}

			reference			operator[](difference_type n) const {
				return (*(operator+(n)));
			}
		
			// private:
				pointer _ptr;
	};
	/*
	** Non member overloads
	*/

	// template <typename T>
	// ptrdiff_t operator-(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs) {
	// 	return lhs.operator->() - rhs.operator->();
	// }

	// template <typename T>
	// VectorIterator<T> operator+(const VectorIterator<T> &iter, size_t n) {
	// 	VectorIterator<T> res = iter;
	// 	return res += n;
	// }

	// template <typename T>
	// VectorIterator<T> operator+(size_t n, const VectorIterator<T> &iter) {
	// 	return iter + n;
	// }
	
}

# include "VectorIterator.inl"

#endif