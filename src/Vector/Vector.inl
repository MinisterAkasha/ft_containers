#include <iostream> //!DEL

namespace ft
{
	/*
	** Constructors
	*/

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const allocator_type& alloc)
		: _arr(nullptr), _size(0), _capacity(1), _allocator(alloc) {
		_arr = _allocator.allocate(_capacity);
	};

	template <class T, class Allocator>
	vector<T, Allocator>::vector(size_type n, const value_type& val, const allocator_type& alloc)
		: _arr(nullptr), _size(n), _capacity(n), _allocator(alloc) {
		_arr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < n; i++) {
			_allocator.construct(_arr + i, val);
		}
	}

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const vector& other)
	: _arr(nullptr), _size(other._size), _capacity(other._capacity), _allocator(other._allocator) {
		operator=(other);
	}

	template <class T, class Allocator>
	vector<T, Allocator>::~vector() {
		value_type *start = _arr;
		this->destroyAllElems();
		_allocator.deallocate(start, _capacity);
	}

	/*
	** Iterators
	*/

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::begin() {
		return _arr;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::end() {
		return _arr + _size;
	}

	/*
	** Capacity
	*/

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::size() const {
		return _size;
	}

	/*
	** Modifiers
	*/

	template <class T, class Allocator>
	void	vector<T, Allocator>::push_back(const value_type& val) {
		if (_size == _capacity)
			this->reserve(_capacity * 2);
		_allocator.construct(_arr + _size, val);
		_size++;
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::pop_back() {
		_allocator.destroy(_arr + _size - 1);
		_size--;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::insert(iterator position, const value_type& val) {
		if (val)
			return position;
		return position;
	}

	/*
	** Overload
	*/

	template <class T, class Allocator>
	vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector& other) {
		if (&other != this) {
			this->~vector();
			_arr = nullptr;
			_size = other._size;
			_capacity = other._capacity;
			_allocator = other._allocator;
			_arr = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_arr + i, other._arr[i]);
		}
		return *this;
	}

	/*
	** Private
	*/

	template <class T, class Allocator>
	void	vector<T, Allocator>::destroyAllElems() {
		value_type* end = _arr + _size;

		while (end >= _arr) {
			_allocator.destroy(end);
			end--;
		}
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::reserve(size_type size) {
		if (size > _capacity) {
			value_type* new_arr;
			new_arr = _allocator.allocate(size);
			for (size_type i; i < _size; i++)
				_allocator.construct(new_arr + i, _arr[i]);
			this->~vector();
			_arr = new_arr;
			_capacity = size;
		}
	}
}