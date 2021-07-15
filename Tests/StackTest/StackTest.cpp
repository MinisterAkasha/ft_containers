#include "StackTest.hpp"

StackTest::StackTest() {
	test();
};

StackTest::~StackTest() {};

void	StackTest::test() const {
	std::cout << std::endl << "<-- Stack test -->" << std::endl << std::endl;
	testConstructor();
	testPush();
	testPop();
	testEmpty();
	testSize();
	testTop();
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

void	StackTest::testPush() const {
	std::cout << "* push: ";
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		ftS.push(10);
		stlS.push(10);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		for (int i = 0; i < 10; i++) {
			ftS.push(i);
			stlS.push(i);
		}

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		ftS.push(0);
		stlS.push(0);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 5);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 5);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 15);

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	std::cout << std::endl;
}

void	StackTest::testPop() const {
	std::cout << "* pop: ";
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		ftS.pop();
		stlS.pop();

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		for (int i = 0; i < 50; i++) {
			ftS.pop();
			stlS.pop();
		}

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		ftS.pop();
		stlS.pop();
		
		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 5);

		for (int i = 0; i < 3; i++) {
			ftS.pop();
			stlS.pop();
		}

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 50);

		for (int i = 0; i < 40; i++) {
			ftS.pop();
			stlS.pop();
		}

		PRINT_RESULT(TO_EQUAL_STACK(ftS, stlS));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 15);

		for (int i = 0; i < 5; i++) {
			ftS.pop();
			stlS.pop();
		}

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

void	StackTest::testSize() const {
	std::cout << "* size(): ";
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		createRandomVectors(ftV, stlV, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 15);

		PRINT_RESULT(TO_EQUAL(ftS.size(), stlS.size()));
	}
	std::cout << std::endl;
}

void	StackTest::testTop() const {
	std::cout << "* top(): ";
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 1);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		createRandomVectors(ftV, stlV, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV(10, 10);
		std::vector<int> stlV(10, 10);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 15);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}

	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 1);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	{
		ft::stack<int, ft::vector<int> > ftS;
		std::stack<int, std::vector<int> > stlS;

		createRandomStack(ftS, stlS, 100);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		createRandomVectors(ftV, stlV, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));

	}
	{
		ft::vector<int> ftV(10, 10);
		std::vector<int> stlV(10, 10);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	{
		ft::vector<int> ftV;
		std::vector<int> stlV;

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		createRandomStack(ftS, stlS, 100);

		PRINT_RESULT(TO_EQUAL(ftS.top(), stlS.top()));
	}
	{
		ft::vector<int> ftV(10, 100);
		std::vector<int> stlV(10, 100);

		ft::stack<int, ft::vector<int> > ftS(ftV);
		std::stack<int, std::vector<int> > stlS(stlV);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	{
		std::list<int> list1;
		std::list<int> list2;

		createRandomList(list1, list2, 100);

		ft::stack<int, std::list<int> > ftS(list1);
		std::stack<int, std::list<int> > stlS(list2);

		createRandomStack(ftS, stlS, 15);

		const int ftVal = ftS.top();
		const int stlVal = stlS.top();

		PRINT_RESULT(TO_EQUAL(ftVal, stlVal));
	}
	std::cout << std::endl;
}
