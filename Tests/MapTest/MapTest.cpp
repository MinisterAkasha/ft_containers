#include "MapTest.hpp"

MapTest::MapTest() {
	test();
}

MapTest::~MapTest() {}

void	MapTest::test() const {
	std::cout << std::endl << "<-- Map test -->" << std::endl << std::endl;
	std::srand(time(NULL));
	testDefaultConstructor();
	testSingleInsert();
	testWithHintInsert();
	testRangeInsert();
	testErasePosition();
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

