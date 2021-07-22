namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _size(0), _keyComp(comp), _valueComp(comp), _tree(alloc) {
		// _tree.deleteNode(ft::make_pair(key_type(9), mapped_type(9)), _valueComp, _allocator);
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
	typename map<Key, T, Compare, Alloc>::iterator 					map<Key, T, Compare, Alloc>::begin() {
		return iterator(_tree.min(_tree.getRoot()), _tree, _keyComp);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 					map<Key, T, Compare, Alloc>::end() {
		return iterator(_tree.getEnd(), _tree, _keyComp);
	}

	/*
	** Capacity
	*/

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type					map<Key, T, Compare, Alloc>::size() const {
		return _tree.getSize();
	}


	/*
	** Modifiers
	*/

	template <class Key, class T, class Compare, class Alloc>
	ft::pair<typename map<Key, T, Compare, Alloc>::iterator,bool> 	map<Key, T, Compare, Alloc>::insert(const value_type& val) {
		ft::pair<typename Tree<value_type>::NodePtr, bool> pair = _tree.insert(val, _valueComp, _allocator);

		return (ft::make_pair(iterator(pair.first, _tree, _keyComp), pair.second));
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 					map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val) {
		ft::pair<typename Tree<value_type>::NodePtr, bool> pair = _tree.insert(val, _valueComp, _allocator);

		return (iterator(pair.first, _tree, _keyComp));
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	void 					map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
		while (first != last)
			insert(*first++);
	}

	template <class Key, class T, class Compare, class Alloc>
	void 					map<Key, T, Compare, Alloc>::erase(iterator position) {
		_tree.deleteNode(*position, _valueComp, _allocator);
	}

	
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type 				map<Key, T, Compare, Alloc>::erase(const key_type& k) {
		_tree.deleteNode(ft::make_pair(k, mapped_type()), _valueComp, _allocator);
		return 1;
	}

	/*
	** Operations
	*/

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 				map<Key, T, Compare, Alloc>::find(const key_type& k) {
		return iterator(_tree.find(ft::make_pair(k, mapped_type()), _valueComp), _tree, _keyComp);
	}

	/*
	** Private
	*/
}