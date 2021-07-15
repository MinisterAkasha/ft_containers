#ifndef STACK_TEST
# define STACK_TEST

# include "stack.hpp"
# include <stack>
# include <list>
# include <iostream>
# include "testUtils.hpp"

class StackTest {
	private:
		void	testConstructor() const;
		void	testPush() const;
		void	testPop() const;
		void	testEmpty() const;
		void	testSize() const;
		void	testTop() const;
		void	testNonMemberEqualOperator() const;
		void	testNonMemberNotEqualOperator() const;
		void	testNonMemberLessOperator() const;
		void	testNonMemberLessOrEqualOperator() const;
		void	testNonMemberMoreOperator() const;
		void	testNonMemberMoreOrEqualOperator() const;


	public:
		StackTest();
		~StackTest();
	
	public:
		void	test() const;
};

#endif