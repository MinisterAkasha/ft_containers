namespace ft {
	/*
	** Constructors
	*/

	template <typename T>
	VectorIterator<T>::VectorIterator() : _ptr(nullptr) {};

	template <typename T>
	VectorIterator<T>::VectorIterator(T* ptr) : _ptr(ptr) {};

	template <typename T>
	VectorIterator<T>::VectorIterator(const VectorIterator& other) : _ptr(other._ptr) {};

	/*
	** Destructors
	*/

	template <typename T>
	VectorIterator<T>::~VectorIterator() {};

	/*
	** Overloads
	*/

	template <typename T>
	VectorIterator<T>& 	VectorIterator<T>::operator=(const VectorIterator& other) {
		if (&other == this)
			return *this;
	
		_ptr = other._ptr;
		return *this;
	}

	template <typename T>
	typename VectorIterator<T>::reference 	VectorIterator<T>::operator*() {
		return *_ptr;
	}

	template <typename T>
	typename VectorIterator<T>::pointer 	VectorIterator<T>::operator->() {
		return _ptr;
	}

	// Prefix

	template <typename T>
	VectorIterator<T>& 	VectorIterator<T>::operator++() {
		_ptr++;
		return *this;
	}

	template <typename T>
	VectorIterator<T>& 	VectorIterator<T>::operator--() {
		_ptr--;
		return *this;
	}

	// Postfix

	template <typename T>
	VectorIterator<T> 	VectorIterator<T>::operator++(int) {
		VectorIterator tmp = VectorIterator(*this);

		_ptr++;
		return tmp;
	}

	template <typename T>
	VectorIterator<T> 	VectorIterator<T>::operator--(int) {
		VectorIterator tmp = VectorIterator(*this);

		_ptr--;
		return tmp;
	}

	template <typename T>
	bool	VectorIterator<T>::operator==(const VectorIterator& other) const {
		return _ptr == other._ptr;
	}

	template <typename T>
	bool	VectorIterator<T>::operator!=(const VectorIterator& other) const {
		return _ptr != other._ptr;
	}

	template <typename T>
	bool	VectorIterator<T>::operator>(const VectorIterator& other) const {
		return _ptr > other._ptr;
	}

	template <typename T>
	bool	VectorIterator<T>::operator>=(const VectorIterator& other) const {
		return _ptr >= other._ptr;
	}

	template <typename T>
	bool	VectorIterator<T>::operator<(const VectorIterator& other) const {
		return _ptr < other._ptr;	
	}

	template <typename T>
	bool	VectorIterator<T>::operator<=(const VectorIterator& other) const {
		return _ptr <= other._ptr;
	}

	template <typename T>
	VectorIterator<T>& 		VectorIterator<T>::operator-=(ptrdiff_t n) {
		_ptr -= n;
		return *this;
	}

	template <typename T>
	VectorIterator<T>& 		VectorIterator<T>::operator+=(ptrdiff_t n) {
		_ptr += n;
		return *this;
	}

	template <typename T>
	VectorIterator<T> 		VectorIterator<T>::operator-(ptrdiff_t n) const {
		return _ptr - n;
	}

	template <typename T>
	VectorIterator<T> 		VectorIterator<T>::operator+(ptrdiff_t n) const {
		return _ptr + n;
	}

	template <typename T>
	typename VectorIterator<T>::reference 	VectorIterator<T>::operator[](ptrdiff_t n) const {
		return (*(operator+(n)));
	}
}