#include <iostream> //!DEL

namespace ft
{
	/*
	** Constructors
	*/

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const allocator_type& alloc)
		: _arr(nullptr), _size(0), _capacity(0), _allocator(alloc) {
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
		pointer start = _arr;
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

	template <class T, class Allocator>
	bool	vector<T, Allocator>::empty() const {
		return _size == 0;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity() const{
		return _capacity;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::max_size() const{
		return _allocator.max_size();
	}

	template <class T, class Allocator>
	void	vector<T, Allocator>::reserve(size_type size) {
		if (size > _capacity) {
			pointer newArr = _allocator.allocate(size);
			pointer prevArr = _arr;
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(newArr + i, *prevArr);
				prevArr++;
			}
			this->~vector();
			_arr = newArr;
			_capacity = size;
		}
	}

	/*
	** Modifiers
	*/

	template <class T, class Allocator>
	void	vector<T, Allocator>::push_back(const value_type& val) {
		if (_size == _capacity)
				reserve(_capacity * 2 ? _capacity * 2 : 1);
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
		size_type index = 0;

		while (begin() + index != position && index < _size)
			index++;

		if (_size == _capacity)
			reserve(_capacity * 2 ? _capacity * 2 : 1);

		pointer newArr = _allocator.allocate(_capacity);
		size_type oldArrIndex = 0;
		for (size_type i = 0; i < _size + 1; i++) {
			if (i == index)
				_allocator.construct(newArr + index, val);
			else
				_allocator.construct(newArr + i, _arr[oldArrIndex++]);
		}
		this->~vector();
		_arr = newArr;
		_size++;
		return &_arr[index];
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val) {
		while (n--)
			position = insert(position, val);
	}

	template <class T, class Allocator>
	template <class InputIterator>
    void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
		while (first != last) {
			position = insert(position, *first) + 1;
			first++;
		}
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::clear() {
		for (size_type i = 0; i < _size; i++)
			_allocator.destroy(_arr + i);
		_size = 0;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position) {
		size_type index = 0;

		while (begin() + index != position && index < _size)
			index++;
		
		pointer newArr = _allocator.allocate(_capacity);
		size_type oldArrIndex = 0;
		for (size_type i = 0; i < _size; i++) {
			if (i == index)
				oldArrIndex++;
			_allocator.construct(newArr + i, _arr[oldArrIndex++]);
		}
		this->~vector();
		_arr = newArr;
		_size--;
		return &_arr[index];
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
		if (_size != 0) {
			pointer end = _arr + _size - 1;

			while (end >= _arr) {
				_allocator.destroy(end);
				end--;
			}
		}
	}
}