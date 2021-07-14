#include "ReverseIteratorTest.hpp"

ReverseIteratorTest::ReverseIteratorTest() {
	std::cout << "<-- Reverse iterator test -->" << std::endl;
	test();
}

ReverseIteratorTest::~ReverseIteratorTest() {}

void	ReverseIteratorTest::test() const {
	testInitializationConstructor();	
	testOperatorPlus();
	testOperatorMinus();
	testOperatorDecrement();
	testBase();
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

void	ReverseIteratorTest::testBase() const {
	std::cout << "* base(): ";
	{
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin() + 10;
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin() + 10;

		PRINT_RESULT(TO_EQUAL(*((ftReverse.base())++), *((stlReverse.base())++)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		for (int i = 0; i < 10; i++) {
			ft.push_back(i);
			stl.push_back(i);
		}

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin() + 2;
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin() + 2;

		PRINT_RESULT(TO_EQUAL(*(ftReverse.base()), *(stlReverse.base())));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin() + 50;
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin() + 50;

		PRINT_RESULT(TO_EQUAL(*ftReverse.base(), *stlReverse.base()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 10);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin() + 10;
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin() + 10;

		PRINT_RESULT(TO_EQUAL(*ftReverse.base(), *stlReverse.base()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*ftReverse.base(), *stlReverse.base()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend() - 50;
		std::vector<int>::reverse_iterator stlReverse = stl.rend() - 50;

		PRINT_RESULT(TO_EQUAL(*ftReverse.base(), *stlReverse.base()));
	}
	std::cout << std::endl;
}

void	ReverseIteratorTest::testOperatorPlus() const {
	std::cout << "* operator+: ";
	{
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftReverse + 5), *(stlReverse + 5)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		for (int i = 0; i < 10; i++) {
			ft.push_back(i);
			stl.push_back(i);
		}

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftReverse + 2), *(stlReverse + 2)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftReverse + 50), *(stlReverse + 50)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 10);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftReverse + 0), *(stlReverse + 0)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(ftReverse + -5), *(stlReverse + -5)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		ftReverse + 50;
		stlReverse + 50;

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		ftReverse + 0;
		stlReverse + 0;

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		ftReverse + 99;
		stlReverse + 99;

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftReverse + 50), *(stlReverse + 50)));
	}
	std::cout << std::endl;
}

void	ReverseIteratorTest::testOperatorMinus() const {
	std::cout << "* operator-: ";
	{
		ft::vector<int> ft(10, 100);
		std::vector<int> stl(10, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(ftReverse - 5), *(stlReverse - 5)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		for (int i = 0; i < 10; i++) {
			ft.push_back(i);
			stl.push_back(i);
		}

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(ftReverse - 2), *(stlReverse - 2)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(ftReverse - 50), *(stlReverse - 50)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 10);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftReverse - 0), *(stlReverse - 0)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(ftReverse - 5), *(stlReverse - 5)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		ftReverse - 50;
		stlReverse - 50;

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		ftReverse - 0;
		stlReverse - 0;

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin();
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin();

		ftReverse - 99;
		stlReverse - 99;

		PRINT_RESULT(TO_EQUAL(*ftReverse, *stlReverse));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(ftReverse - 50), *(stlReverse - 50)));
	}
	std::cout << std::endl;
}

void	ReverseIteratorTest::testOperatorDecrement() const {
	std::cout << "* operator--: ";
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		ftReverse--;
		stlReverse--;
		
		PRINT_RESULT(TO_EQUAL(*(ftReverse), *(stlReverse)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		--ftReverse;
		--stlReverse;
		
		PRINT_RESULT(TO_EQUAL(*(ftReverse), *(stlReverse)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rbegin()--;
		std::vector<int>::reverse_iterator stlReverse = stl.rbegin()--;

		PRINT_RESULT(TO_EQUAL(*(ftReverse), *(stlReverse)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend()--;
		std::vector<int>::reverse_iterator stlReverse = stl.rend()--;

		PRINT_RESULT(TO_EQUAL(*(--ftReverse), *(--stlReverse)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend();
		std::vector<int>::reverse_iterator stlReverse = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftReverse), *(--stlReverse)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = ft.rend()--;
		std::vector<int>::reverse_iterator stlReverse = stl.rend()--;

		PRINT_RESULT(TO_EQUAL(*(--ftReverse), *(--stlReverse)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::reverse_iterator ftReverse = --ft.rend();
		std::vector<int>::reverse_iterator stlReverse = --stl.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftReverse), *(--stlReverse)));
	}
	std::cout << std::endl;
}
