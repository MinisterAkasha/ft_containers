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
	std::cout << std::endl;
}
