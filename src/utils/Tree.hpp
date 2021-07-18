#ifndef NODE_HPP
# define NODE_HPP

typedef enum { BLACK, RED } nodeColor;

template <class value_type>
struct Node {
	value_type*	data;
	Node*		left;
	Node*		right;
	Node*		parent;
	bool		color;
};

template <class value_type, class ValueAlloc>
class Tree {
	private:
		typedef Node<value_type>*		NodePtr;

	private:
		ValueAlloc	_allocator;
		NodePtr		_root;
		NodePtr		_NIL;

	public:
		Tree() {
			_NIL = new Node<value_type>;
			_NIL->color = 0;
			_NIL->left = nullptr;
			_NIL->right = nullptr;
			_root = _NIL;
		}

		~Tree() {
			delete _NIL;
		}

	public:
		NodePtr		createNode(value_type& value, NodePtr parent) {
			NodePtr node = new Node<value_type>;

			node->left = _NIL;
			node->right = _NIL;
			node->parent = parent;

			node->data = _allocator.allocate(1);
			_allocator.construct(node->data, value);

			node->color = parent ? RED : BLACK;

			return node;
		};

		void		clearTree(NodePtr node) {
			if (node->right != _NIL)
				clearTree(node->right);
			if (node->left != _NIL)
				clearTree(node->left);

			clearNode(node);
		}

		void		clearNode(NodePtr node) {
			_allocator.destroy(node->data);
			_allocator.deallocate(node->data, 1);
			delete node;
		}

		NodePtr		getRoot() {
			return _root;
		}

		void		rotateLeft(NodePtr node) {
			NodePtr y = node->right;

			node->right = y->left;
			if (y->left != _NIL)
				y->left->parent = node;

			if (y != _NIL)
				y->parent = node->parent;

			if (node->parent) {
				if (node == node->parent->left)
					node->parent->left = y;
				else
					node->parent->right = y;
			} else {
				_root = y;
			}

			y->left = node;
			if (node != _NIL)
				node->parent = y;
		}

		void		rotateRight(NodePtr node) {
			NodePtr y = node->left;

			node->left = y->right;
			if (y->right != _NIL)
				y->right->parent = node;

			if (y != _NIL)
				y->parent = node->parent;
			if (node->parent) {
				if (node == node->parent->right)
					node->parent->right = y;
				else
					node->parent->left = y;
			} else {
				_root = y;
			}

			y->right = node;
			if (node != _NIL)
				node->parent = y;
		}

		void		swapColors(NodePtr node, NodePtr uncle) {
			node->parent->color = BLACK;
			if (uncle)
				uncle->color = BLACK;
			node->parent->parent->color = RED;
		}

		template <class Comp>
		void		insert(value_type data, Comp comp) {
			NodePtr node = find(data, comp);

			if (node != _NIL)
				updateNodeDate(node, data);
			else
				insertNewNode(data, comp);

			// return (newNode);
		}

		template <class Comp>
		void		deleteNode(value_type data, Comp& comp) {
			NodePtr tmp = find(data, comp);

			if (!tmp || tmp == _NIL)
				return;

			NodePtr successor = getSuccessor(tmp);
			NodePtr	successorChild;

			if (successor->left != _NIL)
				successorChild = successor->left;
			else
				successorChild = successor->right;

			successorChild->parent = successor->parent;

			if (successor->parent)
				if (successor == successor->parent->left)
					successor->parent->left = successorChild;
				else
					successor->parent->right = successorChild;
			else
				_root = successorChild;

			if (successor != tmp)
				swapNodeData(tmp, successor);

			if (successor->color == BLACK)
				deleteFixup(successorChild);

			clearNode(successor);
		}

		void		insertFixup(NodePtr node) {
			while (node != _root && node->parent->color == RED) {
				if (node->parent == node->parent->parent->left) {
					NodePtr uncle = node->parent->parent->right;

					if (uncle && uncle->color == RED) {
						swapColors(node, uncle);
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							rotateLeft(node);
						}
						swapColors(node, nullptr);
						rotateRight(node->parent->parent);
					}
				} else {
					NodePtr uncle = node->parent->parent->left;

					if (uncle && uncle->color == RED) {
						swapColors(node, uncle);
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							rotateRight(node);
						}
						swapColors(node, nullptr);
						rotateLeft(node->parent->parent);
					}
				}
			}
			_root->color = BLACK;
		};

		void		deleteFixup(NodePtr node) {
			while (node != _root && node->color == BLACK) {
				if (node == node->parent->left) {
					NodePtr sibling = node->parent->right;

					if (sibling->color == RED) {
						sibling->color = BLACK;
						node->parent->color = RED;
						rotateLeft(node->parent);
						sibling = node->parent->right;
					}
					if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
						sibling->color = RED;
						node = node->parent;
					} else {
						if (sibling->right->color == BLACK) {
							sibling->left->color = BLACK;
							sibling->color = RED;
							rotateRight(sibling);
							sibling = node->parent->right;
						}
						sibling->color = node->parent->color;
						node->parent->color = BLACK;
						sibling->right->color = BLACK;
						rotateLeft(node->parent);
						node = _root;
					}
				} else {
					NodePtr sibling = node->parent->left;

					if (sibling->color == RED) {
						sibling->color = BLACK;
						node->parent->color = RED;
						rotateRight(node->parent);
						sibling = node->parent->left;
					}
					if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
						sibling->color = RED;
						node = node->parent;
					} else {
						if (sibling->left->color == BLACK) {
							sibling->right->color = BLACK;
							sibling->color = RED;
							rotateLeft(sibling);
							sibling = node->parent->left;
						}
						sibling->color = node->parent->color;
						node->parent->color = BLACK;
						sibling->left->color = BLACK;
						rotateRight(node->parent);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}

		template <class Comp>
		NodePtr		find(value_type data, Comp comp) {
			NodePtr tmp = _root;

			while (tmp != _NIL && getNodeData(tmp).first != data.first) {
				if (comp(data, getNodeData(tmp)))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}

			return tmp;
		}

	private:
		void								updateNodeDate(NodePtr& node, value_type data) {
			node->data->second = data.second;
		}

		value_type& 						getNodeData(const NodePtr& node) {
			return *(node->data);
		}

		typename value_type::first_type&	getNodeKey(const NodePtr& node) {
			return node->data->first;
		}

		typename value_type::first_type&	getNodeValue(const NodePtr& node) {
			return node->data->second;
		}

		template <class Comp>
		NodePtr								getNewNodeParent(value_type data, Comp comp) {
			NodePtr current;
			NodePtr parent;

			current = _root;
			parent = nullptr;

			while (current != _NIL) {
				if (getNodeKey(current) == data.first)
					return nullptr;
				parent = current;
				current = comp(data, getNodeData(current)) ?
					current->left : current->right;
			}
			
			return parent;
		}

		template <class Comp>
		void								insertNewNode(value_type data, Comp comp) {
			NodePtr parent = getNewNodeParent(data, comp);
				NodePtr newNode = createNode(data, parent);

				if (parent) {
					if (comp(data, getNodeData(parent)))
						parent->left = newNode;
					else
						parent->right = newNode;
				} else {
					_root = newNode;
				}

				insertFixup(newNode);
		}

		NodePtr								getSuccessor(NodePtr node) {
			NodePtr successor;

			if (node->left == _NIL || node->right == _NIL) {
				successor = node;
			} else {
				successor = node->right;
				while (successor->left != _NIL)
					successor = successor->left;
			}

			return successor;
		}

		void								swapNodeData(NodePtr& node1, NodePtr& node2) {
			value_type* copy = node1->data;
			node1->data = node2->data;
			node2->data = copy;
		}

	public://!DELETE
		void printTree(const std::string& prefix, const NodePtr node, bool isLeft) {
			if (node != _NIL) {
				std::cout << prefix;

				if (prefix.length())
					std::cout << (isLeft ? "├─L─" : "└─R─" );

				if (node->color == RED)
					std::cout << " \033[1;31m{\033[0;0m" << getNodeKey(node) << ": " << getNodeValue(node) << "\033[1;31m}\033[0;0m" << std::endl;
				else
					std::cout << " \033[1;30m{\033[0;0m" << getNodeKey(node) << ": " << getNodeValue(node) << "\033[1;30m}\033[0;0m" << std::endl;

				printTree( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printTree( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}

		void printTree() {
			printTree("", _root, false);
		}

};

#endif