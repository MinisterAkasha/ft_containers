namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _keyComp(comp), _valueComp(comp) {
		// _initTree(ft::make_pair(key_type(), mapped_type()));

		_tree.insert(ft::make_pair(key_type(0), mapped_type(0)), _valueComp);
		_tree.insert(ft::make_pair(key_type(-2), mapped_type(-2)), _valueComp);
		_tree.insert(ft::make_pair(key_type(2), mapped_type(2)), _valueComp);


		// tree::deleteNode(ft::make_pair(key_type(2), mapped_type(2)), _root, _valueComp, _allocator);

		_tree.printTree();
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
		// _tree.clearTree(_tree.getRoot());
	}

	/*
	** Private
	*/

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::_initTree(value_type value) {
		// _root = _root->createNode(value, _allocator, nullptr);
	}
}