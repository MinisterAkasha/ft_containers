#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "Tree.hpp"
# include "IteratorTraits.hpp"

template <class value_type, class Compare>
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
		pointer				_NIL;
		Compare				_comp;
	
	public:
		MapIterator() : _ptr(nullptr), _tree(nullptr), _comp() {}

		MapIterator(const pointer& ptr, const Tree<value_type>& tree, const Compare& comp) : _ptr(ptr), _tree(tree), _comp(comp) {
			_NIL = _tree.getNil();
		}

		MapIterator(const MapIterator &other) : _ptr(other._ptr), _tree(other._tree) {
			_ptr = other._ptr;
			_tree = other._tree;
			_NIL = other._NIL;
			_comp = other._comp;
		}

		MapIterator &operator=(const MapIterator &other) {
			_ptr = other._ptr;
			_tree = other._tree;
			_NIL = other._NIL;
			_comp = other._comp;
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
			this->prev();
			return *this;
		}
		MapIterator		operator++(int) {
			MapIterator	tmp = *this;
			operator++();
			return tmp;
		}
		MapIterator		operator--(int) {
			MapIterator	tmp = *this;
			operator--();
			return tmp;
		}

		private:
			void	next() {
				if (_ptr->right != _NIL) {
					_ptr = _tree.min(_ptr->right); //find the minimum relative to _ptr->left
				} else if (_ptr == _tree.max(_tree.getRoot())) {
					_ptr = _ptr->right; // if _ptr == max of Tree
				} else {
					if (_ptr->parent) {
						while (_comp(_ptr->parent->data->first, _ptr->data->first)) {
							_ptr = _ptr->parent;
						}
						_ptr = _ptr->parent;
					}
				}
			}

			void	prev() {
				if (_ptr == _NIL) {
					_ptr = _tree.max(_tree.getRoot()); // if _ptr == end
				} else if (_ptr->left != _NIL) {
					_ptr = _tree.max(_ptr->left); // find the maximum relative to _ptr->left
				} else {
					if (_ptr->parent) {
						while (_comp(_ptr->data->first, _ptr->parent->data->first)) {
							_ptr = _ptr->parent;
						}
						_ptr = _ptr->parent;
					}
				}
			}
};


#endif