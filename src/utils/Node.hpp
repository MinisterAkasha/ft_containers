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
		Node*		createNode(value_type value, ValueAlloc& valueAllocator, Node* parent) {
			Node* node = new Node<value_type>;

			node->left = nullptr;
			node->right = nullptr;
			node->parent = parent;

			node->data = valueAllocator.allocate(1);
			valueAllocator.construct(node->data, value);

			node->_color = RED;

			return node;
		};

		template <class ValueAlloc>
		void	clearTree(Node* node, ValueAlloc& valueAllocator) {
			if (node->right)
				clearTree(node->right, valueAllocator);
			else if (node->left)
				clearTree(node->left, valueAllocator);

			valueAllocator.destroy(node->data);
			valueAllocator.deallocate(node->data, 1);
			delete node;
		}

		static void		rotateLeft(Node* node);
		static void		rotateRight(Node* node);
		static void		swapColors(Node* parentNode);

		void			insert(value_type value);
		void			insertFixup(Node *x);
		void			deleteFixup(Node *x);
		Node*			find(value_type value);
};

#endif