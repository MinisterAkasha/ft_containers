#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {
	template <typename T>
	class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {
		private:
			T* _ptr;
		public:
			VectorIterator(T* ptr);
  			VectorIterator(const VectorIterator& other);

			/*
			** VectorIterator(T* ptr) : _ptr(ptr) {};
			** VectorIterator(const VectorIterator& other) : _p(other._p) {};
			*/
			~VectorIterator();
	};
}

#endif