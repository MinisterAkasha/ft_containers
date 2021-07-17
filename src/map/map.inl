namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _comp(comp) {
		_initTree(ft::make_pair(key_type(10), mapped_type()));
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last,
		const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _comp(comp) {

	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map (const map& x) {

	}

	/*
	** Destructor
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map() {
		
	}

	/*
	** Private
	*/

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::_initTree(value_type value) {
		_root = tree::createNode(value, _allocator, nullptr);
	}
}