namespace ft {

	/*
	** Constructors
	*/

	template <typename Iter>
	reverse_iterator<Iter>::reverse_iterator() : _base() {}

	template <typename Iter>
	reverse_iterator<Iter>::reverse_iterator(iterator_type it) : _base(it) {}

	template <typename Iter>
	template <class Itererator>
	reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<Itererator>& rev_it) :  _base(rev_it.base()) {}

	/*
	** Destructors
	*/

	template <typename Iter>
	reverse_iterator<Iter>::~reverse_iterator() {}

	/*
	** Member functions
	*/

	template <typename Iter>
	typename reverse_iterator<Iter>::iterator_type		reverse_iterator<Iter>::base() const {
		return _base;
	}

	template <typename Iter>
	typename reverse_iterator<Iter>::reference			reverse_iterator<Iter>::operator*() const {
		Iter ite(_base);
		--ite;
		return *ite;
	}

	template <typename Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator+(difference_type n) const {
		return reverse_iterator(_base - n);
	}

	template <typename Iter>
	reverse_iterator<Iter>&	reverse_iterator<Iter>::operator++() {
		_base--;
		return *this;
	}

	template <typename Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator++(int) {
		reverse_iterator temp = *this;
		++(*this);
		return temp;
	}

	template <typename Iter>
	reverse_iterator<Iter>& 	reverse_iterator<Iter>::operator+=(difference_type n) {
		_base -= n;
		return (*this);
	}

	template <typename Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator-(difference_type n) const {
		return reverse_iterator(_base + n);
	}

	template <typename Iter>
	reverse_iterator<Iter>&	reverse_iterator<Iter>::operator--() {
		_base++;
		return *this;
	}

	template <typename Iter>
	reverse_iterator<Iter>	reverse_iterator<Iter>::operator--(int) {
		 reverse_iterator temp = *this;
		--(*this);
		return temp;
	}

	template <typename Iter>
	reverse_iterator<Iter>& 	reverse_iterator<Iter>::operator-=(difference_type n) {
		_base += n;
		return (*this);
	}

	template <typename Iter>
	typename reverse_iterator<Iter>::reference			reverse_iterator<Iter>::operator[](difference_type n) const {
		return (this->base()[-n - 1]);
	}

	/*
	** Non-member functions
	*/

};