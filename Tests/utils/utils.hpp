#ifndef UTILS
# define UTILS

# include "vector.hpp"

# define OK "\033[1;92m\u2713\033[0;0m"
# define KO "\033[1;31m\u2718\033[0;0m"

template <class ftIterator, class stlIterator, class size_type, class T>
void createBeginIterators(ftIterator& myIterator, stlIterator& defoultIterator, size_type size, T value) {
	ft::vector<T>	myVector(size, value);
	std::vector<T>	stlVector(size, value);

	myIterator = myVector.begin();
	defoultIterator = stlVector.begin();
}

template <class T1, class T2>
void	IS_EQUIL(T1& value1, T2& value2) {
	if (value1 == value2)
		std::cout << OK << " ";
	else
		std::cout << KO << " ";
}

#endif