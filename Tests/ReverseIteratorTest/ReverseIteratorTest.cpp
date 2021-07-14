#include "ReverseIteratorTest.hpp"

ReverseIteratorTest::ReverseIteratorTest() {
	std::cout << "<-- Reverse iterator test -->" << std::endl;
	test();
}

ReverseIteratorTest::~ReverseIteratorTest() {}

void	ReverseIteratorTest::test() const {
	testInitializationConstructor();	
}

void	ReverseIteratorTest::testInitializationConstructor() const {
	std::cout << "* constructors: ";
	{
		
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		ft::vector<int>::const_reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::const_reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::const_reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::const_reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::const_reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::const_reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		ft::vector<int>::reverse_iterator ftReverse1 = ft.rbegin();
		ft::vector<int>::reverse_iterator ftReverse2(ftReverse1);
		std::vector<int>::reverse_iterator stlReverse1 = stl.rbegin();
		std::vector<int>::reverse_iterator stlReverse2(stlReverse1);

		PRINT_RESULT(TO_EQUAL(*ftReverse2, *stlReverse2));
	}
	{
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse1 = ft.rbegin();
		ft::vector<int>::reverse_iterator ftReverse2(ftReverse1);
		std::vector<int>::reverse_iterator stlReverse1 = stl.rbegin();
		std::vector<int>::reverse_iterator stlReverse2(stlReverse1);

		PRINT_RESULT(TO_EQUAL(*ftReverse2, *stlReverse2));
	}
	{
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse1 = ft.rbegin() + 50;
		ft::vector<int>::reverse_iterator ftReverse2(ftReverse1);
		std::vector<int>::reverse_iterator stlReverse1 = stl.rbegin() + 50;
		std::vector<int>::reverse_iterator stlReverse2(stlReverse1);

		PRINT_RESULT(TO_EQUAL(*ftReverse2, *stlReverse2));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse1 = ft.rbegin() + 99;
		ft::vector<int>::reverse_iterator ftReverse2(ftReverse1);
		std::vector<int>::reverse_iterator stlReverse1 = stl.rbegin() + 99;
		std::vector<int>::reverse_iterator stlReverse2(stlReverse1);

		PRINT_RESULT(TO_EQUAL(*ftReverse2, *stlReverse2));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse1 = ft.rbegin() + 0;
		ft::vector<int>::reverse_iterator ftReverse2(ftReverse1);
		std::vector<int>::reverse_iterator stlReverse1 = stl.rbegin() + 0;
		std::vector<int>::reverse_iterator stlReverse2(stlReverse1);

		PRINT_RESULT(TO_EQUAL(*ftReverse2, *stlReverse2));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse1 = ft.rend() - 50;
		ft::vector<int>::reverse_iterator ftReverse2(ftReverse1);
		std::vector<int>::reverse_iterator stlReverse1 = stl.rend() - 50;
		std::vector<int>::reverse_iterator stlReverse2(stlReverse1);

		PRINT_RESULT(TO_EQUAL(*ftReverse2, *stlReverse2));
	}
	std::cout << std::endl;
}
