#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include <memory>
# include "IteratorTraits.hpp"

namespace ft {

	template <typename Iter>
	class reverse_iterator {
		public:
			typedef Iter														iterator_type;
			typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename	ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename	ft::iterator_traits<Iter>::reference			reference;

			/*
			** Constructors
			*/

			reverse_iterator() : _base() {};															// defoult

			explicit reverse_iterator(iterator_type it) : _base(it) {};									// initialization

			template <class Itererator>
			reverse_iterator(const reverse_iterator<Itererator>& rev_it) :  _base(rev_it.base()) {}; 	// copy

			/*
			** Destructors
			*/
			
			~reverse_iterator() {};

			/*
			** Member functions
			*/

			iterator_type		base() const {
				return _base;
			};

			reference			operator*() const {
				Iter ite(_base);
				--ite;
				return *ite;
			};

			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(_base - n);
			};

			reverse_iterator& 	operator++() {
				_base--;
				return *this;
			};

			reverse_iterator  	operator++(int) {
				reverse_iterator temp = *this;
				++(*this);
				return temp;
			};

			reverse_iterator& 	operator+=(difference_type n) {
				_base -= n;
				return (*this);
			};

			reverse_iterator 	operator-(difference_type n) const {
				return reverse_iterator(_base + n);
			};

			reverse_iterator& 	operator--() {
				_base++;
				return *this;
			};

			reverse_iterator  	operator--(int) {
				reverse_iterator temp = *this;
				--(*this);
				return temp;
			};

			reverse_iterator& 	operator-=(difference_type n) {
				_base += n;
				return (*this);
			};

			reference			operator[](difference_type n) const {
				return (this->base()[-n - 1]);
			};

		private:
			iterator_type _base;
	};

	/*
	** Non-member functions
	*/

	template <class Iterator>
  	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	};

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return !operator==(lhs, rhs);
	};

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	};

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	};

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it);
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs);
};

#endif