#ifndef NODE_HPP
# define NODE_HPP

typedef enum { BLACK, RED } nodeColor;

template <class value_type, class ValueAlloc>
class Tree {
	private:
		// template <class value_type>
		struct Node {
			value_type*	data;
			Node*		left;
			Node*		right;
			Node*		parent;
			bool		color;
		};

		typedef Node*		NodePtr;

	private:
		ValueAlloc	_allocator;
		NodePtr		_root;
		NodePtr		_NIL;

	public:
		Tree() {
			_NIL = new Node;
			_NIL->color = 0;
			_NIL->left = nullptr;
			_NIL->right = nullptr;
			_root = _NIL;
		}

		~Tree() {
			delete _NIL;//TODO
		}

	public:
		NodePtr		createNode(value_type& value, NodePtr parent) {
			NodePtr node = new Node;

			node->left = _NIL;
			node->right = _NIL;
			node->parent = parent;

			node->data = _allocator.allocate(1);
			_allocator.construct(node->data, value);

			node->color = parent ? RED : BLACK;

			return node;
		};

		void			clearTree(NodePtr node) {
			if (node->right != _NIL)
				clearTree(node->right);
			if (node->left != _NIL)
				clearTree(node->left);

			clearNode(node);
		}

		void			clearNode(NodePtr node) {
			_allocator.destroy(node->data);
			_allocator.deallocate(node->data, 1);
			delete node;
		}

		NodePtr	getRoot() {
			return _root;
		}

		void		rotateLeft(NodePtr x) {
			NodePtr y = x->right;

			/* establish x->right link */
			x->right = y->left;
			if (y->left != nullptr)
				y->left->parent = x;

			/* establish y->parent link */
			if (y != nullptr)
				y->parent = x->parent;

			if (x->parent) {
				if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
			} else {
				_root = y;
			}

			/* link x and y */
			y->left = x;
			if (x != nullptr)
				x->parent = y;
		}

		void		rotateRight(NodePtr x) {
			NodePtr y = x->left;

			/* establish x->left link */
			x->left = y->right;
			if (y->right != nullptr)
				y->right->parent = x;

			/* establish y->parent link */
			if (y != nullptr)
				y->parent = x->parent;
			if (x->parent) {
				if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
			} else {
				_root = y;
			}

			/* link x and y */
			y->right = x;
			if (x != nullptr)
				x->parent = y;
		}

		void		swapColors(NodePtr node, NodePtr uncle) {
			node->parent->color = BLACK;
			if (uncle)
				uncle->color = BLACK;
			node->parent->parent->color = RED;
		}

		template <class Comp>
		void		insert(value_type data, Comp comp) {
			NodePtr current;
			NodePtr parent;
			NodePtr newNode;

			current = _root;
			parent = nullptr;

			while (current != _NIL) {
				if (getNodeKey(current) == data.first)
					return ;
					// return (current); //TODO
				parent = current;
				current = comp(data, getNodeData(current)) ?
					current->left : current->right;
			}

			newNode = createNode(data, parent);


			if (parent) {
				if (comp(data, getNodeData(parent)))
					parent->left = newNode;
				else
					parent->right = newNode;
			} else {
				_root = newNode;
			}

			insertFixup(newNode); //TODO
			// return (newNode);
		}

	// 	template <class Comp, class ValueAlloc>
	// 	static void		deleteNode(value_type data, Node* root, Comp& comp, ValueAlloc& alloc) {
	// 		Node* tmp = root;

	// 		while (getNodeData(tmp).first != data.first) {
	// 			if (comp(data, getNodeData(tmp)))
	// 				tmp = tmp->left;
	// 			else
	// 				tmp = tmp->right;
	// 		}

	// 		// std::cout << tmp->data->first << std::endl;

	// 		if (!tmp->left && !tmp->right) {
	// 			if (tmp == root)
	// 				root = nullptr;
	// 			else {
	// 				if (tmp->parent->left == tmp)
	// 					tmp->parent->left = nullptr;
	// 				else
	// 					tmp->parent->right = nullptr;
	// 			}
	// 			return ;
	// 		}

	// 		// Node y = nullptr;
	// 		// Node q = nullptr;

	// 		Node *x, *y;

	// 		if (!tmp || tmp == nullptr)
	// 			return;

	// 		if (tmp->left == nullptr || tmp->right == nullptr) {
	// 			/* y has a nullptr tmp as a child */
	// 			y = tmp;
	// 		} else {
	// 			/* find min(right) node */
	// 			y = tmp->right;
	// 			while (y->left != nullptr)
	// 				y = y->left;
	// 		}
	// 		std::cout << y->data->first << std::endl;
	// 		/* x is y's only child */

	// 		if (y->left != nullptr)
	// 			x = y->left;
	// 		else if (y->right != nullptr)
	// 			x = y->right;

	// 		// if (y->right)
	// 		// 	x = y->right;

	// 		/* remove y from the parent chain */
	// 		std::cout << "/* message */" << std::endl;
	// 		x->parent = y->parent;
	// 		std::cout << "/* message */" << std::endl;

	// 		if (y->parent)
	// 			if (y == y->parent->left)
	// 				y->parent->left = x;
	// 			else
	// 				y->parent->right = x;
	// 		else
	// 			root = x;

	// 		if (y != tmp)
	// 			tmp->data = y->data;

	// 		if (y->color == BLACK)
	// 			deleteFixup(x);

	// 		// clearNode(y, alloc);
	// 	}

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

	// 	static void		deleteFixup(Node *x) {

	// 	}

	// 	Node*			find(value_type value);

	private:
		value_type& 						getNodeData(const NodePtr node) {
			return *(node->data);
		}

		typename value_type::first_type&	getNodeKey(const NodePtr node) {
			return node->data->first;
		}

		typename value_type::first_type&	getNodeValue(const NodePtr node) {
			return node->data->first;
		}

	public://!DELETE
		void printTree(const std::string& prefix, const NodePtr node, bool isLeft) {
			if (node != _NIL) {
				std::cout << prefix;

				if (prefix.length())
					std::cout << (isLeft ? "├─L─" : "└─R─" );

				if (node->color == RED)
					std::cout << " \033[1;31m{\033[0;0m" << node->data->first << ": " << node->data->second << "\033[1;31m}\033[0;0m" << std::endl;
				else
					std::cout << " \033[1;30m{\033[0;0m" << node->data->first << ": " << node->data->second << "\033[1;30m}\033[0;0m" << std::endl;

				printTree( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printTree( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}

		void printTree() {
			printTree("", _root, false);    
		}

};

#endif