#include "StackTest.hpp"

StackTest::StackTest() {
	test();
};

StackTest::~StackTest() {};

void	StackTest::test() const {
	std::cout << std::endl << "<-- Stack test -->" << std::endl << std::endl;
	testConstructor();
	testEmpty();
}

void	StackTest::testConstructor() const {
	std::cout << "* constructor: ";
	{
		ft::vector<int> 	ftV;
		std::vector<int>	stlV;

		createRandomVectors(ftV, stlV, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> 	ftV;
		std::vector<int>	stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> 	ftV;
		std::vector<int>	stlV;

		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> 	list1;
		std::list<int>	list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> 	list1;
		std::list<int>	list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> 	list1;
		std::list<int>	list2;

		ft::stack<int, std::list<int> > ftS;
		std::stack<int, std::list<int> > stlS;

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> 	list1;
		std::list<int>	list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	std::cout << std::endl;
}

void	StackTest::testEmpty() const {
	std::cout << "* empty(): ";
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		createRandomVectors(ftV, stlV, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 15);

		PRINT_RESULT(TO_EQUAL(ftS.empty(), stlS.empty()));
	}
	std::cout << std::endl;
}
