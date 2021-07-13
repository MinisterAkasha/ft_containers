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

			reverse_iterator(); 										// defoult

			explicit reverse_iterator (iterator_type it);				// initialization

			template <class Itererator>
			reverse_iterator (const reverse_iterator<Itererator>& rev_it); 	// copy

			/*
			** Destructors
			*/
			
			~reverse_iterator();

			/*
			** Member functions
			*/

			iterator_type		base() const;

			reference			operator*() const;
			reverse_iterator	operator+(difference_type n) const;
			reverse_iterator& 	operator++();
			reverse_iterator  	operator++(int);
			reverse_iterator& 	operator+=(difference_type n);
			reverse_iterator 	operator-(difference_type n) const;
			reverse_iterator& 	operator--();
			reverse_iterator  	operator--(int);
			reverse_iterator& 	operator-=(difference_type n);
			reference			operator[](difference_type n) const;
	};

	template <class Iterator>
  	bool operator== (const reverse_iterator<Iterator>& lhs,
                   	const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs);

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it);
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs);
};

# include "reverseIterator.inl"

#endif