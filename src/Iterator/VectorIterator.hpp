#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "IteratorTraits.hpp"


namespace ft {

	template < typename T >
	class VectorConstIterator;


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

  			VectorIterator(const VectorIterator& other) : _ptr(other._ptr) {};

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
		
		private:
			pointer _ptr;
	};


	template < typename T >
	class VectorConstIterator : public VectorIterator<const T> {
	public:
		typedef	T																				value_type;
		typedef T*																				pointer;
		typedef T&																				reference;
		typedef ptrdiff_t																		difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef VectorIterator< value_type >													VectorIterator;

		VectorConstIterator() : _ptr(nullptr) {}

		explicit VectorConstIterator(T * p) : _ptr(p) {}

		VectorConstIterator(const VectorConstIterator & other) : _ptr(other._ptr) {}

		~VectorConstIterator() {}

		VectorConstIterator&	operator= (const VectorConstIterator & other) {
			if (this != &other)
				_ptr = other._ptr;
			return *this;
		}

		VectorConstIterator&	operator= (const VectorIterator & other) {
			_ptr = other.operator->();
			return *this;
		}

		reference				operator* () const {
			return *_ptr;
		}
		pointer				operator->() const {
			return _ptr;
		}

		VectorConstIterator	operator+ (difference_type n) const {
			VectorConstIterator		it(*this);

			it += n;
			return it;
		}
		VectorConstIterator	operator- (difference_type n) const {
			return (*this + (-n));
		}
		VectorConstIterator&	operator-=(difference_type n) {
			*this += -n;
			return *this;
		}
		VectorConstIterator&	operator+=(difference_type n) {
			_ptr += n;
			return *this;
		}
		reference				operator[](difference_type n) const {
			return _ptr[n];
		}

		bool					operator==(const VectorConstIterator & other) const {
			return (_ptr == other._ptr);
		}
		bool					operator!=(const VectorConstIterator & other) const {
			return (_ptr != other._ptr);
		}
		bool					operator< (const VectorConstIterator & other) const {
			return (_ptr < other._ptr);
		}
		bool					operator> (const VectorConstIterator & other) const {
			return (_ptr > other._ptr);
		}
		bool					operator>=(const VectorConstIterator & other) const {
			return (_ptr >= other._ptr);
		}
		bool					operator<=(const VectorConstIterator & other) const {
			return (_ptr <= other._ptr);
		}

		VectorConstIterator&	operator++() {
			++_ptr;
			return *this;
		}
		VectorConstIterator&	operator--() {
			--_ptr;
			return *this;
		}
		VectorConstIterator	operator++(int) {
			pointer		tmp = _ptr;
			operator++();
			return VectorConstIterator(tmp);
		}
		VectorConstIterator	operator--(int) {
			pointer		tmp = _ptr;
			operator--();
			return VectorConstIterator(tmp);
		}

	private:
		pointer		_ptr;
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

#endif