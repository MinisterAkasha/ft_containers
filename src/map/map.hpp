#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "utils.hpp"
# include "MapIterator.hpp"
# include "reverseIterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {
		public:
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef	ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare;
			typedef	Alloc													allocator_type;

			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;

			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;

			typedef MapIterator<Key, T>										iterator;
			typedef MapIterator<Key, const T>								const_iterator;
			typedef	ft::reverse_iterator<iterator>							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef	size_t													size_type;

			class value_compare;


		private:
	};


	template <class Key, class T, class Compare, class Alloc>
	class map< Key, T, Compare, Alloc >::value_compare {
		public:
			typedef bool												result_type;
			typedef typename map<Key, T, Compare, Alloc>::value_type	first_argument_type;
			typedef typename map<Key, T, Compare, Alloc>::value_type	second_argument_type;

			value_compare(Compare c) : comp(c) {}

			result_type operator()(const first_argument_type & x,
								const second_argument_type & y) const {
				return comp(x.first, y.first);
			}
		protected:
			Compare	comp;
	};
}
#endif