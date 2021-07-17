namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _keyComp(comp), _valueComp(comp) {
		_initTree(ft::make_pair(key_type(), mapped_type()));

		
		tree::insert(ft::make_pair(key_type(-2), mapped_type(-2)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(2), mapped_type(2)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(1), mapped_type(1)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(4), mapped_type(4)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(4), mapped_type(4)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(-3), mapped_type(-3)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(-7), mapped_type(-7)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(10), mapped_type(10)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(3), mapped_type(3)), _root, _valueComp, _allocator);
		tree::insert(ft::make_pair(key_type(-1), mapped_type(-1)), _root, _valueComp, _allocator);


		tree::deleteNode(ft::make_pair(key_type(2), mapped_type(2)), _root, _valueComp, _allocator);

		tree::printTree(_root);
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
		_root->clearTree(_root, _allocator);
	}

	/*
	** Private
	*/

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::_initTree(value_type value) {
		_root = _root->createNode(value, _allocator, nullptr);
	}
}