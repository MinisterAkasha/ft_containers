#include "MapTest.hpp"

MapTest::MapTest() {
	test();
}

MapTest::~MapTest() {}

void	MapTest::test() const {
	std::cout << std::endl << "<-- Map test -->" << std::endl << std::endl;
	std::srand(time(NULL));
	testDefaultConstructor();
	testBegin();
	testEnd();
	testRBegin();
	testREnd();
	testSingleInsert();
	testWithHintInsert();
	testRangeInsert();
	testErasePosition();
	testEraseKey();
	testEraseRange();
	testSwap();
	testClear();
	testFind();
	testEmpty();
	testtestAccessOperator();
	testNonMemberOperatorEqual();
	testNonMemberOperatorNotEqual();
	testNonMemberOperatorLess();
	testNonMemberOperatorLessOrEqual();
	testNonMemberOperatorMore();
	testNonMemberOperatorMoreOrEqual();
}

void	MapTest::testBegin() const {
	std::cout << "* begin(): ";
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft::map<int, int>::iterator		ftI = ft.begin();
		std::map<int, int>::iterator	stlI = stl.begin();

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::iterator		ftI = ft.begin();
		std::map<int, int>::iterator	stlI = stl.begin();

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::iterator		ftI = ft.begin();
		std::map<int, int>::iterator	stlI = stl.begin();

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int>	ft;
		std::map<std::string, int>	stl;


		ft.insert(ft::make_pair("string", 10));
		stl.insert(std::make_pair("string", 10));

		ft::map<std::string, int>::iterator		ftI = ft.begin();
		std::map<std::string, int>::iterator	stlI = stl.begin();

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("string", "10"));
		stl.insert(std::make_pair("string", "10"));

		ft::map<std::string, std::string>::iterator		ftI = ft.begin();
		std::map<std::string, std::string>::iterator	stlI = stl.begin();

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("", ""));
		stl.insert(std::make_pair("", ""));

		ft::map<std::string, std::string>::iterator		ftI = ft.begin();
		std::map<std::string, std::string>::iterator	stlI = stl.begin();

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	std::cout << std::endl;
}

void	MapTest::testEnd() const {
	std::cout << "* end(): ";
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft::map<int, int>::iterator		ftI = --(ft.end());
		std::map<int, int>::iterator	stlI = --(stl.end());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::iterator		ftI = --(ft.end());
		std::map<int, int>::iterator	stlI = --(stl.end());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::iterator		ftI = --(ft.end());
		std::map<int, int>::iterator	stlI = --(stl.end());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int>	ft;
		std::map<std::string, int>	stl;


		ft.insert(ft::make_pair("string", 10));
		stl.insert(std::make_pair("string", 10));

		ft::map<std::string, int>::iterator		ftI = --(ft.end());
		std::map<std::string, int>::iterator	stlI = --(stl.end());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("string", "10"));
		stl.insert(std::make_pair("string", "10"));

		ft::map<std::string, std::string>::iterator		ftI = --(ft.end());
		std::map<std::string, std::string>::iterator	stlI = --(stl.end());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("", ""));
		stl.insert(std::make_pair("", ""));

		ft::map<std::string, std::string>::iterator		ftI = --(ft.end());
		std::map<std::string, std::string>::iterator	stlI = --(stl.end());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	std::cout << std::endl;
}

void	MapTest::testRBegin() const {
	std::cout << "* rbegin(): ";
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft::map<int, int>::reverse_iterator		ftI = ++(ft.rbegin());
		std::map<int, int>::reverse_iterator	stlI = ++(stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		for (int i = 0; i < 20; i++) {
			if (i % 2) {
				ft.insert(ft::make_pair(i, i));
				stl.insert(std::make_pair(i, i));
			} else {
				ft.insert(ft::make_pair(-i, -i));
				stl.insert(std::make_pair(-i, -i));

			}
		}

		ft::map<int, int>::reverse_iterator		ftI = ++(ft.rbegin());
		std::map<int, int>::reverse_iterator	stlI = ++(stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::reverse_iterator		ftI = ++(ft.rbegin());
		std::map<int, int>::reverse_iterator	stlI = ++(stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::reverse_iterator		ftI = (ft.rbegin());
		std::map<int, int>::reverse_iterator	stlI = (stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int>	ft;
		std::map<std::string, int>	stl;


		ft.insert(ft::make_pair("string", 10));
		stl.insert(std::make_pair("string", 10));

		ft::map<std::string, int>::reverse_iterator		ftI = (ft.rbegin());
		std::map<std::string, int>::reverse_iterator	stlI = (stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("string", "10"));
		stl.insert(std::make_pair("string", "10"));

		ft::map<std::string, std::string>::reverse_iterator		ftI = (ft.rbegin());
		std::map<std::string, std::string>::reverse_iterator	stlI = (stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("", ""));
		stl.insert(std::make_pair("", ""));

		ft::map<std::string, std::string>::reverse_iterator		ftI = (ft.rbegin());
		std::map<std::string, std::string>::reverse_iterator	stlI = (stl.rbegin());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	std::cout << std::endl;
}

void	MapTest::testREnd() const {
	std::cout << "* rend(): ";
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft::map<int, int>::reverse_iterator		ftI = --(ft.rend());
		std::map<int, int>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		for (int i = 0; i < 20; i++) {
			if (i % 2) {
				ft.insert(ft::make_pair(i, i));
				stl.insert(std::make_pair(i, i));
			} else {
				ft.insert(ft::make_pair(-i, -i));
				stl.insert(std::make_pair(-i, -i));

			}
		}

		ft::map<int, int>::reverse_iterator		ftI = --(ft.rend());
		std::map<int, int>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::reverse_iterator		ftI = --(ft.rend());
		std::map<int, int>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		ft::map<int, int>::reverse_iterator		ftI = --(ft.rend());
		std::map<int, int>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int>	ft;
		std::map<std::string, int>	stl;


		ft.insert(ft::make_pair("string", 10));
		stl.insert(std::make_pair("string", 10));

		ft::map<std::string, int>::reverse_iterator		ftI = --(ft.rend());
		std::map<std::string, int>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("string", "10"));
		stl.insert(std::make_pair("string", "10"));

		ft::map<std::string, std::string>::reverse_iterator		ftI = --(ft.rend());
		std::map<std::string, std::string>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("", ""));
		stl.insert(std::make_pair("", ""));

		ft::map<std::string, std::string>::reverse_iterator		ftI = --(ft.rend());
		std::map<std::string, std::string>::reverse_iterator	stlI = --(stl.rend());

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first) && TO_EQUAL(ftI->second, stlI->second));
	}
	std::cout << std::endl;
}


void	MapTest::testDefaultConstructor() const {
	std::cout << "* default constuctor: ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, std::string> ft;
		std::map<std::string, std::string> stl;

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<double, double> ft;
		std::map<double, double> stl;

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	std::cout << std::endl;
}

void	MapTest::testSingleInsert() const {
	std::cout << "* insert() <single elem>: ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair = ft.insert(ft::make_pair(10, 1));
		std::pair<std::map<int, int>::iterator, bool> stlPair = stl.insert(std::make_pair(10, 1));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair;
		std::pair<std::map<int, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair(10, 1));
		ft.insert(ft::make_pair(20, 2));
		ftPair = ft.insert(ft::make_pair(30, 3));

		stl.insert(std::make_pair(10, 1));
		stl.insert(std::make_pair(20, 2));
		stlPair = stl.insert(std::make_pair(30, 3));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft::pair<ft::map<std::string, int>::iterator, bool> ftPair;
		std::pair<std::map<std::string, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair("str1", 1));
		ft.insert(ft::make_pair("str2", 2));
		ftPair = ft.insert(ft::make_pair("str3", 3));

		stl.insert(std::make_pair("str1", 1));
		stl.insert(std::make_pair("str2", 2));
		stlPair = stl.insert(std::make_pair("str3", 3));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft::pair<ft::map<std::string, int>::iterator, bool> ftPair;
		std::pair<std::map<std::string, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair("str1", 1));
		ftPair = ft.insert(ft::make_pair("str1", 3));

		stl.insert(std::make_pair("str1", 1));
		stlPair = stl.insert(std::make_pair("str1", 3));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair = ft.insert(ft::make_pair(10, 1));
		std::pair<std::map<int, int>::iterator, bool> stlPair = stl.insert(std::make_pair(10, 1));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair;
		std::pair<std::map<int, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair(20, 2));
		ftPair = ft.insert(ft::make_pair(20, 3));

		stl.insert(std::make_pair(20, 2));
		stlPair = stl.insert(std::make_pair(20, 3));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair;
		std::pair<std::map<int, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair(20, 2));
		ftPair = ft.insert(ft::make_pair(10, 2));

		stl.insert(std::make_pair(20, 2));
		stlPair = stl.insert(std::make_pair(10, 2));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair;
		std::pair<std::map<int, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair(20, 2));
		ftPair = ft.insert(ft::make_pair(20, 2));

		stl.insert(std::make_pair(20, 2));
		stlPair = stl.insert(std::make_pair(20, 2));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair;
		std::pair<std::map<int, int>::iterator, bool> stlPair;

		ft.insert(ft::make_pair(10, 1));
		ft.insert(ft::make_pair(20, 2));
		ft.insert(ft::make_pair(30, 3));
		ftPair = ft.insert(ft::make_pair(30, 30));

		stl.insert(std::make_pair(10, 1));
		stl.insert(std::make_pair(20, 2));
		stl.insert(std::make_pair(30, 3));
		stlPair = stl.insert(std::make_pair(30, 30));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::pair<ft::map<int, int>::iterator, bool> ftPair;
		std::pair<std::map<int, int>::iterator, bool> stlPair;

		for (int i = 0; i < 10; i++) {
			ftPair = ft.insert(ft::make_pair(i * 10, i));
			stlPair = stl.insert(std::make_pair(i * 10, i));
		}

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftPair.first->first, stlPair.first->first)
			&& TO_EQUAL(ftPair.first->second, stlPair.first->second)
			&& TO_EQUAL(ftPair.second, stlPair.second));
	}
	std::cout << std::endl;
}

void	MapTest::testWithHintInsert() const {
	std::cout << "* insert() <with hint>: ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::map<int, int>::iterator ftI = ft.insert(ft.begin(), ft::make_pair(10, 1));
		std::map<int, int>::iterator stlI = stl.insert(stl.begin(), std::make_pair(10, 1));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::map<int, int>::iterator ftI;
		std::map<int, int>::iterator stlI;

		ft.insert(ft.begin(), ft::make_pair(10, 1));
		stl.insert(stl.begin(), std::make_pair(10, 1));

		ftI = ft.insert(ft.begin(), ft::make_pair(10, 2));
		stlI = stl.insert(stl.begin(), std::make_pair(10, 2));
		
		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::map<int, int>::iterator ftI;
		std::map<int, int>::iterator stlI;

		ft.insert(ft.begin(), ft::make_pair(10, 1));
		stl.insert(stl.begin(), std::make_pair(10, 1));

		ftI = ft.insert(ft.begin(), ft::make_pair(20, 2));
		stlI = stl.insert(stl.begin(), std::make_pair(20, 2));
		
		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::map<int, int>::iterator ftI;
		std::map<int, int>::iterator stlI;

		ft.insert(ft.begin(), ft::make_pair(10, 1));
		stl.insert(stl.begin(), std::make_pair(10, 1));

		ftI = ft.insert(ft.begin(), ft::make_pair(20, 1));
		stlI = stl.insert(stl.begin(), std::make_pair(20, 1));
		
		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft::map<int, int>::iterator ftI;
		std::map<int, int>::iterator stlI;

		for (int i = 0; i < 10; i++) {
			ftI = ft.insert(ft.begin(), ft::make_pair(i * 10, i));
			stlI = stl.insert(stl.begin(), std::make_pair(i * 10, i));
		}

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft::map<std::string, int>::iterator ftI;
		std::map<std::string, int>::iterator stlI;

		ftI = ft.insert(ft.begin(), ft::make_pair("str1", 1));
		stlI = stl.insert(stl.begin(), std::make_pair("str1", 1));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft::map<std::string, int>::iterator ftI;
		std::map<std::string, int>::iterator stlI;

		ftI = ft.insert(ft.begin(), ft::make_pair("str1", 1));
		stlI = stl.insert(stl.begin(), std::make_pair("str1", 1));
		ftI = ft.insert(ft.begin(), ft::make_pair("str2", 2));
		stlI = stl.insert(stl.begin(), std::make_pair("str2", 2));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft::map<std::string, int>::iterator ftI;
		std::map<std::string, int>::iterator stlI;

		ftI = ft.insert(ft.begin(), ft::make_pair("str1", 1));
		stlI = stl.insert(stl.begin(), std::make_pair("str1", 1));
		ftI = ft.insert(ft.begin(), ft::make_pair("str1", 2));
		stlI = stl.insert(stl.begin(), std::make_pair("str1", 2));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft::map<std::string, int>::iterator ftI;
		std::map<std::string, int>::iterator stlI;

		ftI = ft.insert(ft.begin(), ft::make_pair("", 1));
		stlI = stl.insert(stl.begin(), std::make_pair("", 1));
		ftI = ft.insert(ft.begin(), ft::make_pair("str1", 2));
		stlI = stl.insert(stl.begin(), std::make_pair("str1", 2));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl)
			&& TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	
	std::cout << std::endl;
}

void	MapTest::testRangeInsert() const {
	std::cout << "* insert() <range>: ";
	{
		ft::map<int, int> ftSupport;
		std::map<int, int> stlSupport;

		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.insert(ft.begin(), ft.end());
		stl.insert(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ftSupport;
		std::map<int, int> stlSupport;

		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(-i, i));
			stl.insert(std::make_pair(-i, i));
		}

		ft.insert(ft::make_pair(1, 2));
		stl.insert(std::make_pair(1, 2));
		ft.insert(ft::make_pair(1, 1));
		stl.insert(std::make_pair(1, 1));
		ft.insert(ft::make_pair(1, 3));
		stl.insert(std::make_pair(1, 3));

		ft.insert(ft.begin(), ft.end());
		stl.insert(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ftSupport;
		std::map<int, int> stlSupport;

		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ftSupport, stlSupport, 10);

		ft.insert(ftSupport.begin(), ftSupport.end());
		stl.insert(stlSupport.begin(), stlSupport.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ftSupport;
		std::map<int, int> stlSupport;

		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ftSupport, stlSupport, 10);

		ft.insert(ftSupport.begin(), ++ftSupport.begin());
		stl.insert(stlSupport.begin(), ++stlSupport.begin());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.insert(ft.begin(), ft.end());
		stl.insert(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ftSupport;
		std::map<std::string, int> stlSupport;

		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		std::string	str = "str";

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(str, i));
			stl.insert(std::make_pair(str, i));
		}

		ft.insert(ft.begin(), ft.end());
		stl.insert(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ftSupport;
		std::map<std::string, int> stlSupport;

		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft.insert(ft::make_pair("str1", 1));
		stl.insert(std::make_pair("str1", 1));
		ft.insert(ft::make_pair("str2", 2));
		stl.insert(std::make_pair("str2", 2));
		ft.insert(ft::make_pair("str3", 3));
		stl.insert(std::make_pair("str3", 3));

		ft.insert(ft.begin(), ft.end());
		stl.insert(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	std::cout << std::endl;
}

void	MapTest::testErasePosition() const {
	std::cout << "* erase() <position>: ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin());
		stl.erase(stl.begin());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ft, stl, 10);

		ft.erase(ft.begin());
		stl.erase(stl.begin());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ft, stl, 100);

		ft.erase(ft.begin());
		stl.erase(stl.begin());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ft, stl, 100);

		ft.erase(++(++ft.begin()));
		stl.erase(++(++stl.begin()));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(--ft.end());
		stl.erase(--stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft.insert(ft::make_pair("string", 1));
		stl.insert(std::make_pair("string", 1));

		ft.erase(ft.begin());
		stl.erase(stl.begin());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair("string", i));
			stl.insert(std::make_pair("string", i));
		}

		ft.erase(--ft.end());
		stl.erase(--stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft.insert(ft::make_pair("str1", 1));
		stl.insert(std::make_pair("str1", 1));
		ft.insert(ft::make_pair("str2", 2));
		stl.insert(std::make_pair("str2", 2));
		ft.insert(ft::make_pair("str3", 3));
		stl.insert(std::make_pair("str3", 3));
		ft.insert(ft::make_pair("str4", 4));
		stl.insert(std::make_pair("str4", 4));

		ft.erase(--ft.end());
		stl.erase(--stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	
	std::cout << std::endl;
}

void	MapTest::testEraseKey() const {
	std::cout << "* erase() <key>: ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(1);
		stl.erase(1);

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ft, stl, 10);

		ft.erase(17245);
		stl.erase(17245);

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ft, stl, 100);

		ft.erase(0);
		stl.erase(0);

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(0);
		stl.erase(0);

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft.insert(ft::make_pair("string", 1));
		stl.insert(std::make_pair("string", 1));

		ft.erase("string");
		stl.erase("string");

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair("string", i));
			stl.insert(std::make_pair("string", i));
		}

		ft.erase("string");
		stl.erase("string");

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft.insert(ft::make_pair("str1", 1));
		stl.insert(std::make_pair("str1", 1));
		ft.insert(ft::make_pair("str2", 2));
		stl.insert(std::make_pair("str2", 2));
		ft.insert(ft::make_pair("str3", 3));
		stl.insert(std::make_pair("str3", 3));
		ft.insert(ft::make_pair("str4", 4));
		stl.insert(std::make_pair("str4", 4));

		ft.erase("str1");
		stl.erase("str1");

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	
	std::cout << std::endl;
}

void	MapTest::testFind() const {
	std::cout << "* find(): ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.insert(ft.begin(), ft::make_pair(10, 1));
		stl.insert(stl.begin(), std::make_pair(10, 1));

		ft::map<int, int>::iterator ftI = ft.find(10);
		std::map<int, int>::iterator stlI = stl.find(10);

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.insert(ft.begin(), ft::make_pair(10, 1));
		stl.insert(stl.begin(), std::make_pair(10, 1));
		ft.insert(ft.begin(), ft::make_pair(20, 2));
		stl.insert(stl.begin(), std::make_pair(20, 2));
		ft.insert(ft.begin(), ft::make_pair(30, 3));
		stl.insert(stl.begin(), std::make_pair(30, 3));

		ft::map<int, int>::iterator ftI = ft.find(30);
		std::map<int, int>::iterator stlI = stl.find(30);

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft.begin(), ft::make_pair(i, i));
			stl.insert(stl.begin(), std::make_pair(i, i));
		}

		ft::map<int, int>::iterator ftI = --(ft.find(30));
		std::map<int, int>::iterator stlI = --(stl.find(30));

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft.begin(), ft::make_pair(i, i));
			stl.insert(stl.begin(), std::make_pair(i, i));
		}

		ft::map<int, int>::iterator ftI = --(ft.find(-1));
		std::map<int, int>::iterator stlI = --(stl.find(-1));

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft.begin(), ft::make_pair(i * 10, i));
			stl.insert(stl.begin(), std::make_pair(i * 10, i));
		}

		ft::map<int, int>::iterator ftI = ft.find(30);
		std::map<int, int>::iterator stlI = stl.find(30);

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft.begin(), ft::make_pair(i * 10, i));
			stl.insert(stl.begin(), std::make_pair(i * 10, i));
		}

		ft::map<int, int>::iterator ftI = ft.find(30);
		std::map<int, int>::iterator stlI = stl.find(30);

		PRINT_RESULT(TO_EQUAL(ftI->first, stlI->first)
			&& TO_EQUAL(ftI->second, stlI->second));
	}
	std::cout << std::endl;
}

void	MapTest::testEraseRange() const {
	std::cout << "* erase() <range>: ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 10; i < 15; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.end());
		stl.erase(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.find(7));
		stl.erase(stl.begin(), stl.find(7));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.begin());
		stl.erase(stl.begin(), stl.begin());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.end(), ft.end());
		stl.erase(stl.end(), stl.end());

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.find(9));
		stl.erase(stl.begin(), stl.find(9));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.erase(ft.begin(), ft.find(9));
		stl.erase(stl.begin(), stl.find(9));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 10; i < 15; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.find(12), ft.find(20));
		stl.erase(stl.find(12), stl.find(20));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 15; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.find(12), ft.find(20));
		stl.erase(stl.find(12), stl.find(20));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 5; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.find(0), ft.find(20));
		stl.erase(stl.find(0), stl.find(20));

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	std::cout << std::endl;
}

void	MapTest::testEmpty() const {
	std::cout << "* empty(): ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 10; i < 15; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.find(7));
		stl.erase(stl.begin(), stl.find(7));

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.end());
		stl.erase(stl.begin(), stl.end());

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.begin(), ft.find(9));
		stl.erase(stl.begin(), stl.find(9));

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.erase(ft.begin(), ft.find(9));
		stl.erase(stl.begin(), stl.find(9));

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 10; i < 15; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.find(12), ft.find(20));
		stl.erase(stl.find(12), stl.find(20));

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 15; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.find(12), ft.find(20));
		stl.erase(stl.find(12), stl.find(20));

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		for (int i = 0; i < 5; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		ft.erase(ft.find(0), ft.find(20));
		stl.erase(stl.find(0), stl.find(20));

		PRINT_RESULT(TO_EQUAL(ft.empty(), stl.empty()));
	}
	std::cout << std::endl;
}

void	MapTest::testClear() const {
	std::cout << "* clear(): ";
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.clear();
		stl.clear();

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		ft.insert(ft::make_pair(10, 1));
		stl.insert(std::make_pair(10, 1));

		ft.clear();
		stl.clear();

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<int, int> ft;
		std::map<int, int> stl;

		createRandomMap(ft, stl, 100);

		ft.clear();
		stl.clear();

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	{
		ft::map<std::string, int> ft;
		std::map<std::string, int> stl;

		ft.insert(ft::make_pair("string", 1));
		ft.insert(ft::make_pair("string1", 2));
		ft.insert(ft::make_pair("string2", 3));
		stl.insert(std::make_pair("string", 1));
		stl.insert(std::make_pair("string1", 2));
		stl.insert(std::make_pair("string2", 3));

		ft.clear();
		stl.clear();

		PRINT_RESULT(TO_EQUAL_MAP(ft, stl));
	}
	std::cout << std::endl;
}

void	MapTest::testSwap() const {
	std::cout << "* swap(): ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL_MAP(ft1, stl1) == TO_EQUAL_MAP(ft2, stl2));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		ft1.swap(ft1);
		stl1.swap(stl1);

		PRINT_RESULT(TO_EQUAL_MAP(ft1, stl1) == TO_EQUAL_MAP(ft2, stl2));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL_MAP(ft1, stl1) == TO_EQUAL_MAP(ft2, stl2));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL_MAP(ft1, stl1) == TO_EQUAL_MAP(ft2, stl2));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft2.insert(ft::make_pair("string", 1));
		stl2.insert(std::make_pair("string", 1));

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL_MAP(ft1, stl1) == TO_EQUAL_MAP(ft2, stl2));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft2.insert(ft::make_pair("string", 1));
		stl2.insert(std::make_pair("string", 1));

		ft1.insert(ft::make_pair("st", 2));
		stl1.insert(std::make_pair("st", 2));

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL_MAP(ft1, stl1) == TO_EQUAL_MAP(ft2, stl2));
	}
	std::cout << std::endl;
}

void	MapTest::testtestAccessOperator() const {
	std::cout << "* opearator[]: ";
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;

		PRINT_RESULT(TO_EQUAL(ft[5], stl[5]));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;

		for (int i = 0; i < 10; i++) {
			ft.insert(ft::make_pair(i, i));
			stl.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL(ft[5], stl[5]));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		PRINT_RESULT(TO_EQUAL(ft[2], stl[2]));
	}
	{
		ft::map<int, int>	ft;
		std::map<int, int>	stl;


		ft.insert(ft::make_pair(10, 10));
		stl.insert(std::make_pair(10, 10));

		PRINT_RESULT(TO_EQUAL(ft[10], stl[10]));
	}
	{
		ft::map<std::string, int>	ft;
		std::map<std::string, int>	stl;


		ft.insert(ft::make_pair("string", 10));
		stl.insert(std::make_pair("string", 10));

		PRINT_RESULT(TO_EQUAL(ft["string"], stl["string"]));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("string", "10"));
		stl.insert(std::make_pair("string", "10"));

		PRINT_RESULT(TO_EQUAL(ft["string"], stl["string"]));
	}
	{
		ft::map<std::string, std::string>	ft;
		std::map<std::string, std::string>	stl;


		ft.insert(ft::make_pair("", ""));
		stl.insert(std::make_pair("", ""));

		PRINT_RESULT(TO_EQUAL(ft[""], stl[""]));
	}
	std::cout << std::endl;
}

void	MapTest::testNonMemberOperatorEqual() const {
	std::cout << "* operator== <non-member>: ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl2, 10);
		createRandomMap(ft2, stl1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i< 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 10; i < 20; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 1));

		ft2.insert(ft::make_pair("string1", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string1", 1));

		ft2.insert(ft::make_pair("string2", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		ft1.insert(ft::make_pair("string2", 2));
		stl1.insert(std::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 2));

		ft2.insert(ft::make_pair("string3", 3));
		ft2.insert(ft::make_pair("string4", 4));
		stl2.insert(std::make_pair("string3", 3));
		stl2.insert(std::make_pair("string4", 4));

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	std::cout << std::endl;
}

void	MapTest::testNonMemberOperatorNotEqual() const {
	std::cout << "* operator!= <non-member>: ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl2, 10);
		createRandomMap(ft2, stl1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i< 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 10; i < 20; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 1));

		ft2.insert(ft::make_pair("string1", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string1", 1));

		ft2.insert(ft::make_pair("string2", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		ft1.insert(ft::make_pair("string2", 2));
		stl1.insert(std::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 2));

		ft2.insert(ft::make_pair("string3", 3));
		ft2.insert(ft::make_pair("string4", 4));
		stl2.insert(std::make_pair("string3", 3));
		stl2.insert(std::make_pair("string4", 4));

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	std::cout << std::endl;
}

void	MapTest::testNonMemberOperatorLess() const {
	std::cout << "* operator< <non-member>: ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i< 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 10; i < 20; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 10; i < 20; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 1));

		ft2.insert(ft::make_pair("string1", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string1", 1));

		ft2.insert(ft::make_pair("string2", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		ft1.insert(ft::make_pair("string2", 2));
		stl1.insert(std::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 2));

		ft2.insert(ft::make_pair("string3", 3));
		ft2.insert(ft::make_pair("string4", 4));
		stl2.insert(std::make_pair("string3", 3));
		stl2.insert(std::make_pair("string4", 4));

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	std::cout << std::endl;
}

void	MapTest::testNonMemberOperatorLessOrEqual() const {
	std::cout << "* operator<= <non-member>: ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i< 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 10; i < 20; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 10; i < 20; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 1));

		ft2.insert(ft::make_pair("string1", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string1", 1));

		ft2.insert(ft::make_pair("string2", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		ft1.insert(ft::make_pair("string2", 2));
		stl1.insert(std::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 2));

		ft2.insert(ft::make_pair("string3", 3));
		ft2.insert(ft::make_pair("string4", 4));
		stl2.insert(std::make_pair("string3", 3));
		stl2.insert(std::make_pair("string4", 4));

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	std::cout << std::endl;
}

void	MapTest::testNonMemberOperatorMore() const {
	std::cout << "* operator> <non-member>: ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i< 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 10; i < 20; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 10; i < 20; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 1));

		ft2.insert(ft::make_pair("string1", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string1", 1));

		ft2.insert(ft::make_pair("string2", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		ft1.insert(ft::make_pair("string2", 2));
		stl1.insert(std::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 2));

		ft2.insert(ft::make_pair("string3", 3));
		ft2.insert(ft::make_pair("string4", 4));
		stl2.insert(std::make_pair("string3", 3));
		stl2.insert(std::make_pair("string4", 4));

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	std::cout << std::endl;
}

void	MapTest::testNonMemberOperatorMoreOrEqual() const {
	std::cout << "* operator> <non-member>: ";
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		createRandomMap(ft1, stl1, 10);
		createRandomMap(ft2, stl2, 10);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i< 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 10; i < 20; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 0; i < 10; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<int, int> ft1;
		ft::map<int, int> ft2;

		std::map<int, int> stl1;
		std::map<int, int> stl2;

		for (int i = 0; i < 10; i++) {
			ft1.insert(ft::make_pair(i, i));
			stl1.insert(std::make_pair(i, i));
		}

		for (int i = 10; i < 20; i++) {
			ft2.insert(ft::make_pair(i, i));
			stl2.insert(std::make_pair(i, i));
		}

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 1));

		ft2.insert(ft::make_pair("string1", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		stl1.insert(std::make_pair("string1", 1));

		ft2.insert(ft::make_pair("string2", 1));
		stl2.insert(std::make_pair("string2", 1));

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::map<std::string, int> ft1;
		ft::map<std::string, int> ft2;

		std::map<std::string, int> stl1;
		std::map<std::string, int> stl2;

		ft1.insert(ft::make_pair("string1", 1));
		ft1.insert(ft::make_pair("string2", 2));
		stl1.insert(std::make_pair("string1", 1));
		stl1.insert(std::make_pair("string2", 2));

		ft2.insert(ft::make_pair("string3", 3));
		ft2.insert(ft::make_pair("string4", 4));
		stl2.insert(std::make_pair("string3", 3));
		stl2.insert(std::make_pair("string4", 4));

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	std::cout << std::endl;
}
