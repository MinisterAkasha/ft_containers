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

template <class ftMap, class stlMap>
void	createRandomMap(ftMap& ft, stlMap& stl, size_t size) {
	int	rand = std::rand();

	for (size_t i = 0; i < size; i++) {
		ft.insert(ft::make_pair(rand, rand));
		stl.insert(std::make_pair(rand, rand));
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

template <class List>
void	createRandomList(List& list1, List& list2, size_t size) {
	int	rand = std::rand();

	for (size_t i = 0; i < size; i++) {
		list1.push_back(rand);
		list2.push_back(rand);
		rand = std::rand();
	}
}

template <class ftStack, class stlStack>
void	createRandomStack(ftStack& stack1, stlStack& stack2, size_t size) {
	int	rand = std::rand();

	for (size_t i = 0; i < size; i++) {
		stack1.push(rand);
		stack2.push(rand);
		rand = std::rand();
	}
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

template <class M1, class M2>
bool	TO_EQUAL_MAP(M1& ftMap, M2& stlMap) {
	typename M1::iterator		myIterator = ftMap.begin();
	typename M2::iterator		stlIterator = stlMap.begin();
	
	if (ftMap.size() != stlMap.size()) {
		std::cout << "[Current size: " << ftMap.size() << " Should be " << stlMap.size() << "] ";
		return false;
	}

	while (stlIterator != stlMap.end()) {
		if (myIterator->first != stlIterator->first) {
			std::cout << "[Current key: " << myIterator->first << " Should be " << stlIterator->first << "] ";
			return false;
		} else if (myIterator->second != stlIterator->second) {
			std::cout << "[Current value: " << myIterator->second << " Should be " << stlIterator->second << "] ";
			return false;
		}
		myIterator++;
		stlIterator++;
	}
	return true;
}

template <class S1, class S2>
bool	TO_EQUAL_STACK(S1& ftStack, S2& stlStack) {
	if (ftStack.size() != stlStack.size())
		return false;

	while (!ftStack.empty() && !stlStack.empty()) {
		if (ftStack.top() != stlStack.top())
			return false;
		ftStack.pop();
		stlStack.pop();
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