namespace ft
{

	template <class T, class Allocator>
	vector<T, Allocator>::vector(const allocator_type &alloc)
		: _arr(nullptr), _size(0), _capacity(1), _allocator(alloc)
	{
		_arr = _allocator.allocate(_capacity);
	};

	template <class T, class Allocator>
	vector<T, Allocator>::vector(size_type n, const value_type &val, const allocator_type &alloc)
		: _arr(nullptr), _size(n), _capacity(n), _allocator(alloc) {
		_arr = _allocator.allocate(_capacity);
		for (int i = 0; i < n; i ++) {
			_allocator.construct(_arr + i, val);
		}
	}

	template <class T, class Allocator>
	vector<T, Allocator>::~vector() {
		
	}
}