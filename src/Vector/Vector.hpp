#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include "VectorIterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef Allocator							allocator_type;
			typedef T									value_type;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::size_type		size_type; 			// size_type -> typedef size_t
			typedef typename Allocator::difference_type	difference_type; 	// difference_type -> typedef  ptrdiff_t

			typedef VectorIterator<T>					iterator;
			typedef VectorIterator<const T>				const_iterator;
			
			// reverse_iterator //TODO
			// const_reverse_iterator //TODO

			/*
			** Member functions
			*/
			explicit vector(const allocator_type& alloc = allocator_type());		// default

			explicit vector(size_type n, const value_type& val = value_type(),		// fill
							const allocator_type& alloc = allocator_type());

			// template <class InputIterator>
        	// vector(InputIterator first, InputIterator last,				  			// range
            //      const allocator_type& alloc = allocator_type());

			vector(const vector& other);											// copy

			~vector();

			vector&						operator=(const vector& other);

			/*
			** Iterators
			*/

			iterator					begin();
			// const_iterator 				begin() const;
			// iterator					end();
			// const_iterator				end() const;
			// // reverse_iterator			rbegin();//TODO
			// // const_reverse_iterator	rbegin() const;//TODO

			// /*
			// ** Capacity
			// */

			// size_type 					size() const;
			// size_type 					max_size() const;
			// void 						resize(size_type n, value_type val = value_type());
			// size_type					capacity() const;
			// bool						empty() const;
			// void						reserve(size_type n);

			// /*
			// ** Element access
			// */

			// reference					operator[](size_type pos);
			// const_reference				operator[](size_type pos) const;
			// reference 					at(size_type n);
			// const_reference 			at(size_type n) const;
			// reference 					front();
			// const_reference 			front() const;
			// reference 					back();
			// const_reference				back() const;

			// /*
			// ** Modifiers
			// */
			// template <class InputIterator>
			// void						assign(InputIterator first, InputIterator last); // range
			// void						assign(size_type n, const value_type& val); // fill
			// void 						push_back(const value_type& val);
			// void						pop_back();
			// iterator					insert(iterator position, const value_type& val); // single element
		    // void 						insert(iterator position, size_type n, const value_type& val); // fill
			// template <class InputIterator>
    		// void 						insert(iterator position, InputIterator first, InputIterator last); // range
			// iterator 					erase(iterator position);
			// iterator 					erase(iterator first, iterator last);
			// void 						swap(vector& x);
			// void						clear();

			// /*
			// ** Allocator
			// */
		
			// allocator_type				get_allocator() const;

			private:
				value_type*		_arr;
				size_type		_size;
				size_type		_capacity;
				allocator_type	_allocator;
	};
}

# include "vector.inl"

#endif