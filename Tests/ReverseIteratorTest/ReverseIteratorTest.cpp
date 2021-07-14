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
	std::cout << "* initialization constructor: ";
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

		ft::vector<int>::reverse_iterator ftReverse(ft.rbegin());
		std::vector<int>::reverse_iterator stlReverse(stl.rbegin());

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

		ft::vector<int>::const_reverse_iterator ftReverse(ft.rbegin());
		std::vector<int>::const_reverse_iterator stlReverse(stl.rbegin());

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	std::cout << std::endl;
}