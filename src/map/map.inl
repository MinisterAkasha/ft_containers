namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _size(0), _keyComp(comp), _valueComp(comp), _tree(alloc) {
	}

	// template <class Key, class T, class Compare, class Alloc>
	// template <class InputIterator>
	// map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last,
	// 	const key_compare& comp, const allocator_type& alloc)
	// : _allocator(alloc), _keyComp(comp) {

	// }

	// template <class Key, class T, class Compare, class Alloc>
	// map<Key, T, Compare, Alloc>::map (const map& x) {

	// }

	/*
	** Destructor
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map() {
		_tree.clearTree(_allocator);
	}

	/*
	** Iterators
	*/

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 				map<Key, T, Compare, Alloc>::begin() {
		return iterator(_tree.min(_tree.getRoot()), _tree, _keyComp);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 				map<Key, T, Compare, Alloc>::end() {
		return iterator(_tree.max(_tree.getRoot())->right, _tree, _keyComp);
	}

	/*
	** Capacity
	*/

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::size() const {
		return _size;
	}

	/*
	** Private
	*/
}