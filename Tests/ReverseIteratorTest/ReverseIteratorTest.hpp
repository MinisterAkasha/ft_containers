#ifndef REVERSE_ITERATOR_TEST
# define REVERSE_ITERATOR_TEST

# include <iostream>
# include "testUtils.hpp"
# include "vector.hpp"
# include <vector>
# include <map>

class ReverseIteratorTest {
	private:
		void	testInitializationConstructor() const;
		void	testBase() const;

	public:
		ReverseIteratorTest();
		~ReverseIteratorTest();
		void	test() const;
};

#endif