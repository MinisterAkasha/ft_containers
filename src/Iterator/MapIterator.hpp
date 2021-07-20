#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Tree.hpp"

template <class value_type>
class MapIterator : public ft::iterator<ft::bidirectional_iterator_tag, value_type> {
	public:
		typedef value_type&						reference;
		typedef Node<value_type>*				pointer;
		typedef ptrdiff_t						difference_type;
		typedef typename ft::iterator<
			ft::bidirectional_iterator_tag,
			value_type>::iterator_category		iterator_category;

	private:
		pointer				_ptr;
		Tree<value_type>	_tree;
	
	public:
		MapIterator() : _ptr(nullptr), _tree(nullptr) {}

		MapIterator(const pointer& ptr, const Tree<value_type>& tree) : _ptr(ptr), _tree(tree) {}

		MapIterator(const MapIterator &other) : _ptr(other._ptr), _tree(other._tree) {
			_ptr = other._ptr;
			_tree = other._tree;
		}

		MapIterator &operator=(const MapIterator &other) {
			_ptr = other._ptr;
			return (*this);
		};

		~MapIterator() {}

		bool operator==(const MapIterator &other) {
			return _ptr == other._ptr;
		};
		bool operator!=(const MapIterator &other) {
			return !operator==(other);
		};

		reference			operator*() const {
			return *(_ptr->data);
		}

		value_type*			operator->() const {
			return _ptr->data;
		}

		MapIterator&		operator++() {
			this->next();
			return *this;
		}
		MapIterator&		operator--() {
			return *this;
		}
		MapIterator		operator++(int) {
			pointer	tmp = _ptr;
			operator++();
			return tmp;
		}
		// MapIterator		operator--(int) {
		// 	_tree *	tmp = _ptr;
		// 	operator--();
		// 	return MapIterator(tmp);
		// }

		private:
			void	next() {
				std::cout << _ptr->data->first << std::endl;
				if (_ptr->right != _tree.getNil()) {
					_ptr = _ptr->right;
					while (_ptr->left != _tree.getNil())
						_ptr = _ptr->left;
				} else {
					pointer	tmp = _ptr;
					_ptr = _ptr->parent;
					while (tmp != _ptr->left) {
						if (!_ptr->parent)
							return ;
						_ptr = _ptr->parent;
					}
				}
			}

			void	prev() {
				// if (_ptr != _NIL) {

				// } else {

				// }
			}
};


#endif