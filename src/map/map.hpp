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

			/*
			** Constructor
			*/

			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type());	// empty

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());			// range

			map (const map& x);												// copy

			map& operator= (const map& x);

			/*
			** Destructor
			*/

			~map();

			/*
			** Iterators
			*/

			iterator				begin();
			const_iterator			begin() const;
			iterator 				end();
			const_iterator 			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			/*
			** Iterators
			*/

			bool 					empty() const;
			size_type				size() const;
			size_type				max_size() const;

			/*
			** Element access
			*/

			mapped_type& 			operator[](const key_type& k);

			/*
			** Modifiers
			*/

			pair<iterator,bool> 	insert(const value_type& val);						// single element
			iterator 				insert(iterator position, const value_type& val);	// with hint
			template <class InputIterator>
			void 					insert(InputIterator first, InputIterator last);	// range
			void 					erase(iterator position);
			size_type 				erase(const key_type& k);
			void 					erase(iterator first, iterator last);
			void 					swap(map& x);
			void					clear();

			/*
			** Observers
			*/

			key_compare				key_comp() const;
			value_compare 			value_comp() const;

			/*
			** Operations
			*/

			iterator 				find(const key_type& k);
			const_iterator			find(const key_type& k) const;
			size_type 				count(const key_type& k) const;
			iterator				lower_bound(const key_type& k);
			const_iterator			lower_bound(const key_type& k) const;
			iterator 				upper_bound(const key_type& k);
			const_iterator			upper_bound(const key_type& k) const;
			pair<const_iterator,
			const_iterator>			equal_range (const key_type& k) const;
			pair<iterator,iterator> equal_range (const key_type& k);

			/*
			** Allocator
			*/

			allocator_type 			get_allocator() const;

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