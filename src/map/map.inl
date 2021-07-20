namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _size(0), _keyComp(comp), _valueComp(comp), _tree(alloc) {
		// _initTree(ft::make_pair(key_type(), mapped_type()));

		for (int i = 0; i < 10; i++) {
			if (i % 2)
				_tree.insert(ft::make_pair(key_type(i), mapped_type(i)), _valueComp, _allocator);
			else
				_tree.insert(ft::make_pair(key_type(-i), mapped_type(-i)), _valueComp, _allocator);
		}
		// _tree.insert(ft::make_pair(key_type(20), mapped_type(20)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(25), mapped_type(25)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(23), mapped_type(23)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(30), mapped_type(30)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(10), mapped_type(10)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(4), mapped_type(4)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(2), mapped_type(2)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(5), mapped_type(5)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(3), mapped_type(3)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(16), mapped_type(16)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(17), mapped_type(17)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(19), mapped_type(19)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(14), mapped_type(14)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(15), mapped_type(15)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(12), mapped_type(12)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(11), mapped_type(11)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(-6), mapped_type(-6)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(-8), mapped_type(-8)), _valueComp);
		// _tree.insert(ft::make_pair(key_type(2), mapped_type(2)), _valueComp);


		// _tree.deleteNode(ft::make_pair(key_type(9), mapped_type(9)), _valueComp, _allocator);
		// _tree.deleteNode(ft::make_pair(key_type(10), mapped_type(10)), _valueComp);
		// _tree.deleteNode(ft::make_pair(key_type(4), mapped_type(4)), _valueComp);


		// _tree.printTree();
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
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin() {
		return iterator(_tree.min(), _tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end() {
		return iterator(_tree.max()->right, _tree);
	}

	/*
	** Private
	*/
}