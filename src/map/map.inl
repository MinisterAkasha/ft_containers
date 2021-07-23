namespace ft {
	
	/*
	** Constructors
	*/

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
	: _allocator(alloc), _keyComp(comp), _valueComp(comp), _tree(alloc) {}

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
	typename map<Key, T, Compare, Alloc>::const_iterator 			map<Key, T, Compare, Alloc>::begin() const {
		return const_iterator(_tree.min(_tree.getRoot()), _tree, _keyComp);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 					map<Key, T, Compare, Alloc>::end() {
		return iterator(_tree.getEnd(), _tree, _keyComp);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator 					map<Key, T, Compare, Alloc>::end() const {
		return const_iterator(_tree.getEnd(), _tree, _keyComp);
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

	template <class Key, class T, class Compare, class Alloc>
	void 					map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
		if (!size())
			return ;
	
		while (first != last)
			erase(first++);
	}

	template <class Key, class T, class Compare, class Alloc>
	void 					map<Key, T, Compare, Alloc>::swap(map& x) {
		if (x == *this)
			return ;
		
		allocator_type		allocatorTmp = x._allocator;
		key_compare			keyCompareTMP = x._keyComp;
		value_compare		valueCompareTMP = x._valueComp;
		Tree<value_type>	treeTmp = x._tree;

		x._allocator = _allocator;
		x._keyComp = _keyComp;
		x._valueComp = _valueComp;
		x._tree = _tree;

		_allocator = allocatorTmp;
		_keyComp = keyCompareTMP;
		_valueComp = valueCompareTMP;
		_tree = treeTmp;
	}

	/*
	** Operations
	*/

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator 				map<Key, T, Compare, Alloc>::find(const key_type& k) {
		return iterator(_tree.find(ft::make_pair(k, mapped_type()), _valueComp), _tree, _keyComp);
	}

	/*
	** Non-member overloads
	*/

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
		  	return false;

		typedef typename ft::map<Key,T,Compare,Alloc>::const_iterator const_iterator;

		const_iterator lBegin = lhs.begin();
		const_iterator rBegin = rhs.begin();
		const_iterator lEnd = lhs.end();
		const_iterator rEnd = rhs.end();

		while (lBegin != lEnd && rBegin != rEnd) {
			if (lBegin->first != rBegin->first) {
				return false;
			} else if (lBegin->second != rBegin->second) {
				return false;
			}
			lBegin++;
			rBegin++;
		}
		return true;
	}
}