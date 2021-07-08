#ifndef UTILS
# define UTILS

# include "vector.hpp"
# include <vector>

# define OK "\033[1;92m\u2713\033[0;0m"
# define KO "\033[1;31m\u2718\033[0;0m"

template <class ftIterator, class stlIterator, class size_type, class T>
void createBeginIterators(ftIterator& myIterator, stlIterator& defoultIterator, size_type size, T value) {
	ft::vector<T>	myVector(size, value);
	std::vector<T>	stlVector(size, value);

	myIterator = myVector.begin();
	defoultIterator = stlVector.begin();
}

template <class T1>
void	TO_EQUAL(T1& value1, T1& value2) {
	if (value1 == value2)
		std::cout << OK << " ";
	else
		std::cout << KO << " ";
}

template <class ftVectorContainer, class stlVectorContainer, class T>
void	TO_EQUAL_VECTOR(ftVectorContainer& ftVector, stlVectorContainer& stlVector, T type = T()) {
	typename ft::vector<T>::iterator		myIterator = ftVector.begin();
	typename std::vector<T>::iterator		stlIterator = stlVector.begin();

	if (ftVector.size() != stlVector.size()) {
		std::cout << KO << " ";
		return ;
	}
	
	while (myIterator != ftVector.end() || stlIterator != stlVector.end()) {
		if (*myIterator != *stlIterator) {
			std::cout << KO << " ";
			return ;
		}
		myIterator++;
		stlIterator++;
	}
	std::cout << OK << " ";
}

#endif