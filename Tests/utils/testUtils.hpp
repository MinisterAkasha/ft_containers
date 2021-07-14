#ifndef UTILS
# define UTILS

# include "vector.hpp"
# include <vector>

# define OK "\033[1;92m\u2713\033[0;0m"
# define KO "\033[1;31m\u2718\033[0;0m"

template <class Vector>
void	printVector(Vector& v) {
	typename Vector::iterator itr = v.begin();

	while (itr != v.end()) {
		std::cout << *itr << " " << std::endl;
		itr++;
	}
	std::cout << std::endl;
}

template <class ftVector, class stlVector>
void	createRandomVectors(ftVector& ft, stlVector& stl, size_t size) {
	int	rand = std::rand();

	for (size_t i = 0; i < size; i++) {
		ft.push_back(rand);
		stl.push_back(rand);
		rand = std::rand();
	}
}

template <class ftVector, class stlVector>
void	createOrderedVectors(ftVector& ft, stlVector& stl, size_t size) {
	for (size_t i = 0; i < size; i++) {
		ft.push_back(i);
		stl.push_back(i);
	}
}

template <class Vector>
void	removeElemsFromVector(Vector& vector, size_t size) {
	for (size_t i = 0; i < size; i++) {
		vector.pop_back();
	}
}

template <class ftIterator, class stlIterator, class size_type, class T>
void createBeginIterators(ftIterator& myIterator, stlIterator& defoultIterator, size_type size, T value) {
	ft::vector<T>	myVector(size, value);
	std::vector<T>	stlVector(size, value);

	myIterator = myVector.begin();
	defoultIterator = stlVector.begin();
}

template <class T1>
bool	TO_EQUAL(T1 value1, T1 value2) {
	if (value1 == value2)
		return true;
	std::cout << "[Current value: " << value1 << " Should be " << value2 << "] ";
	return false;
}

template <class V1, class V2>
bool	TO_EQUAL_VECTOR(V1& ftVector, V2& stlVector) {
	typename V1::iterator		myIterator = ftVector.begin();
	typename V2::iterator		stlIterator = stlVector.begin();

	if (ftVector.size() != stlVector.size()) {
		std::cout << "[Current size: " << ftVector.size() << " Should be " << stlVector.size() << "] ";
		return false;
	}
	
	while (myIterator != ftVector.end() || stlIterator != stlVector.end()) {
		if (*myIterator != *stlIterator) {
			std::cout << "[Current value: " << *myIterator << " Should be " << *stlIterator << "] ";
			return false;
		}
		myIterator++;
		stlIterator++;
	}
	return true;
}

template<class Bool>
void	PRINT_RESULT(Bool res) {
	if (res)
		std::cout << OK << " ";
	else
		std::cout << KO << " ";
}

#endif