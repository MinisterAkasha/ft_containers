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
		void	testOperatorPlus() const;
		void	testOperatorMinus() const;
		void	testOperatorDecrement() const;
		void	testOperatorIncrement() const;
		void	testOperatorMinusEq() const;
		void	testOperatorPlusEq() const;
		void	testOperatorAt() const;
		void	testNonMemberEqual() const;
		void	testNonMemberNotEqual() const;
		void	testNonMemberLess() const;
		void	testNonMemberLessOrEqual() const;
		void	testNonMemberMore() const;
		void	testNonMemberMoreOrEqual() const;

	public:
		ReverseIteratorTest();
		~ReverseIteratorTest();
		void	test() const;
};

#endif