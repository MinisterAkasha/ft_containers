#ifndef NODE_HPP
# define NODE_HPP

typedef enum { BLACK, RED } nodeColor;

template <class value_type>
class Node {
	public:
		value_type*	data;
	
	private:
		Node*		left;
		Node*		right;
		Node*		parent;
		bool		_color;

	public:
		template <class ValueAlloc>
		static Node*		createNode(value_type& value, ValueAlloc& alloc, Node* parent) {
			Node* node = new Node<value_type>;

			node->left = nullptr;
			node->right = nullptr;
			node->parent = parent;

			node->data = alloc.allocate(1);
			alloc.construct(node->data, value);

			node->_color = RED;

			return node;
		};

		template <class ValueAlloc>
		void	clearTree(Node* node, ValueAlloc& alloc) {
			if (node->right)
				clearTree(node->right, alloc);
			else if (node->left)
				clearTree(node->left, alloc);

			alloc.destroy(node->data);
			alloc.deallocate(node->data, 1);
			delete node;
		}

		static void		rotateLeft(Node* x, Node* root) {
			Node *y = x->right;

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
				root = y;
			}

			/* link x and y */
			y->left = x;
			if (x != nullptr)
				x->parent = y;
		}

		static void		rotateRight(Node* x, Node* root) {
			Node *y = x->left;

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
				root = y;
			}

			/* link x and y */
			y->right = x;
			if (x != nullptr)
				x->parent = y;
		}

		static void		swapColors(Node* parentNode);

		template <class Comp, class ValueAlloc>
		static void			insert(value_type data, Node* root, Comp& comp, ValueAlloc& alloc) {
			Node *current;
			Node *parent;
			Node *newNode;

			current = root;
			parent = nullptr;

			while (current != nullptr) {
				if (getNodeData(current).first == data.first)
					return ;
					// return (current); //TODO
				parent = current;
				current = comp(data, getNodeData(current)) ?
					current->left : current->right;
			}

			newNode = createNode(data, alloc, parent);

			if (parent) {
				if (comp(data, getNodeData(parent)))
					parent->left = newNode;
				else
					parent->right = newNode;
			} else {
				root = newNode;
			}

			// insertFixup(newNode); //TODO
			// return (newNode);
		}

		void			insertFixup(Node *x) {

		};

		void			deleteFixup(Node *x);
		Node*			find(value_type value);

	private:
		static value_type&	getNodeData(const Node* node) {
			return *(node->data);
		}

	public://!DELETE
		static void printTree(const std::string& prefix, const Node* node, bool isLeft) {
			if (node != nullptr) {
				std::cout << prefix;

				if (prefix.length())
					std::cout << (isLeft ? "├─L─" : "└─R─" );

				// print the value of the node
				std::cout << " {" << node->data->first << ": " << node->data->second << "}" << std::endl;

				// enter the next tree level - left and right branch
				printTree( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printTree( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
		}

		static void printTree(const Node* node) {
			printTree("", node, false);    
		}

};

#endif