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
		pointer	_ptr;
	
	public:
		MapIterator() : _ptr(nullptr) {}

		MapIterator(const pointer ptr) : _ptr(ptr) {}

		MapIterator(const MapIterator &other) : _ptr(other._ptr) {}

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
			return *this;
		}
		MapIterator&		operator--() {
			return *this;
		}
		// MapIterator		operator++(int) {
		// 	_tree *	tmp = _ptr;
		// 	operator++();
		// 	return MapIterator(tmp);
		// }
		// MapIterator		operator--(int) {
		// 	_tree *	tmp = _ptr;
		// 	operator--();
		// 	return MapIterator(tmp);
		// }

};


#endif