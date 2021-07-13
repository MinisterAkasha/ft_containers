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
	: _arr(nullptr), _size(0), _capacity(0), _allocator(other._allocator){
		operator=(other);
	}

	template <class T, class Allocator>
	template <class InputIterator>
    vector<T, Allocator>::vector(InputIterator first, InputIterator last, const allocator_type& alloc,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
	: _arr(nullptr), _size(0), _capacity(0), _allocator(alloc) {
		size_type size = 0;
		InputIterator position = first;
		while (position != last) {
			size++;
			position++;
		}
		_capacity = size;
		_arr = _allocator.allocate(0);

		insert(_arr, first, last);
	}

	/*
	** Destructor
	*/

	template <class T, class Allocator>
	vector<T, Allocator>::~vector() {
		pointer start = _arr;
		this->destroyAllElems();
		_allocator.deallocate(start, _capacity);
		_arr = nullptr;
	}

	/*
	** Iterators
	*/

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::begin() {
		return _arr;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::begin() const {
		return _arr;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator	vector<T, Allocator>::end() {
		return _arr + _size;
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_iterator	vector<T, Allocator>::end() const {
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

	template <class T, class Allocator>
	void vector<T, Allocator>::resize(size_type n, value_type val) {
		if (n < _size)
			erase(_arr + n, end());
		else
			insert(end(), n - _size, val);
	}

	/*
	** Element access
	*/

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type pos) {
		return _arr[pos];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type pos) const {
		return _arr[pos];
	}
	
	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos) {
		if (pos >= _size)
			throw std::out_of_range("Out of bounds position");
		return _arr[pos];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type pos) const {
		if (pos >= _size)
			throw std::out_of_range("Out of bounds position");
		return _arr[pos];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::front() {
		return _arr[0];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const {
		return _arr[0];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::reference vector<T, Allocator>::back() {
		return _arr[_size - 1];
	}

	template <class T, class Allocator>
	typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
		return _arr[_size - 1];
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
		size_type index = getIndexFromPosition(position);

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
		size_type index = getIndexFromPosition(position);
		
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

	template <class T, class Allocator>
	typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last) {
		iterator begin = first;
		iterator position = first;
		while (first != last) {
			position = erase(position);
			first++;
		}
		return position;
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::swap(vector& x) {
		if (x == *this)
			return ;

		pointer			arrTmp = x._arr;
		size_type 		sizeTmp = x._size;
		size_type 		capacityTmp = x._capacity;
		allocator_type	allocatorTmp = x._allocator;

		x._arr = _arr;
		x._size = _size;
		x._capacity = _capacity;
		x._allocator = _allocator;

		_arr = arrTmp;
		_size = sizeTmp;
		_capacity = capacityTmp;
		_allocator = allocatorTmp;
	}

	template <class T, class Allocator>
	void vector<T, Allocator>::assign(size_type n, const value_type& val) {
		this->~vector();
		_size = n;
		if (!_capacity)
			_capacity = n;
		_arr = _allocator.allocate(n);
		for (size_type i = 0; i < n; i++)
			_allocator.construct(_arr + i, val);
	}

	template <class T, class Allocator>
	template <class InputIterator>
	void vector<T, Allocator>::assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*) {
		size_type newSize = 0;
		InputIterator position = first;
		while (position != last) {
			newSize++;
			position++;
		}

		this->~vector();
		_size = newSize;

		if (newSize > _capacity)
			_capacity = newSize;

		_arr = _allocator.allocate(_capacity);
		for (size_type i = 0; i < newSize; i++) {
			_allocator.construct(_arr + i, *first);
			first++;
		}

	}

	/*
	** 	Allocator
	*/

	template <class T, class Allocator>
	typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const {
		return _allocator;
	}

	/*
	** Overload
	*/

	template <class T, class Allocator>
	vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector& other) {
		if (&other != this) {
			this->~vector();
			_size = other._size;
			_capacity = other._capacity;
			_allocator = other._allocator;
			_arr = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(_arr + i, other._arr[i]);
			}
		}
		return *this;
	}

	/*
	** Non-member overloads
	*/

	template <class T, class Alloc>
  	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
		  	return false;

		typedef typename vector<T,Alloc>::const_iterator const_iterator;
		
		const_iterator lBegin = lhs.begin();
		const_iterator rBegin = rhs.begin();
		const_iterator lEnd = lhs.end();
		const_iterator rEnd = rhs.end();

		while (lBegin != lEnd && rBegin != rEnd) {
			if (*lBegin != *rBegin)
				return false;
			lBegin++;
			rBegin++;
		}
		return true;
	}

	template <class T, class Alloc>
  	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !operator==(lhs, rhs);  
	}

	template <class T, class Alloc>
  	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
  	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !operator<(rhs, lhs);  
	}

	template <class T, class Alloc>
  	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class T, class Alloc>
  	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!operator>(rhs, lhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
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

	template <class T, class Allocator>
	typename vector<T, Allocator>::size_type	vector<T, Allocator>::getIndexFromPosition(iterator position) {
		size_type index = 0;

		while (begin() + index != position && index < _size)
			index++;
		return index;
	}
}