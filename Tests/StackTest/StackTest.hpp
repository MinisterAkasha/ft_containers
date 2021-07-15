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
		void	testEmpty() const;


	public:
		StackTest();
		~StackTest();
	
	public:
		void	test() const;
};

#endif