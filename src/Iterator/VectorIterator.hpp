#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>


namespace ft {

	template <typename T>
	class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {
		private:
			typedef	T			value_type;
			typedef T*			pointer;
			typedef T&			reference;
			typedef ptrdiff_t	difference_type;

			pointer _ptr;

		public:
			VectorIterator(T* ptr);
  			VectorIterator(const VectorIterator& other);

			~VectorIterator();

			VectorIterator& 	operator=(const VectorIterator& other);

			bool 				operator==(const VectorIterator& other) const;
        	bool 				operator!=(const VectorIterator& other) const;

			reference			operator*();
			pointer				operator->();

			VectorIterator& 	operator++();
			VectorIterator& 	operator--();
			VectorIterator 		operator++(int);
			VectorIterator 		operator--(int);

        	bool 				operator>(const VectorIterator& other) const;
        	bool 				operator>=(const VectorIterator& other) const;
        	bool 				operator<(const VectorIterator& other) const;
        	bool 				operator<=(const VectorIterator& other) const;

			VectorIterator 		operator-=(int value);
			VectorIterator 		operator+=(int value);
			
			VectorIterator 		operator-(int value) const;
			VectorIterator 		operator+(int value) const;
			difference_type 	operator-(const VectorIterator& other) const;

			reference			operator[](int value) const;
	};
}

# include "VectorIterator.inl"

#endif