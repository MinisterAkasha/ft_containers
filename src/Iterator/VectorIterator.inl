/*
** Constructors
*/

template <typename T>
VectorIterator<T>::VectorIterator(T* ptr) : _ptr(ptr) {};

template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator& other) : _ptr(other._ptr) {};

/*
** Destructors
*/

template <typename T>
VectorIterator<T>::~VectorIterator() {};