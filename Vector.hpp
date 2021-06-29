#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include "Iterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class Vector {
		public:
			typedef Allocator							allocator_type;
			typedef T									value_type;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::size_type		size_type; // size_type -> typedef size_t
			typedef typename Allocator::difference_type	difference_type; // difference_type -> typedef  ptrdiff_t

			typedef VectorIterator<T>	iterator;// iterator
			
			// const_iterator
			// reverse_iterator
			// const_reverse_iterator
			// difference_type

			/*
			** Constructors
			*/
			Vector();

			explicit Vector(const allocator_type &alloc = allocator_type());

			explicit Vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type());

			template <class InputIterator>
        	Vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());

			Vector (const Vector& other);

			/*
			** Destructor
			*/
			~Vector();

			/*
			** Overload operators
			*/
			Vector& operator=(const Vector& other);


		private:
	};
}

#endif