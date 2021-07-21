#include "MapTest.hpp"

MapTest::MapTest() {
	test();
}

MapTest::~MapTest() {}

void	MapTest::test() const {
	std::cout << std::endl << "<-- Map test -->" << std::endl << std::endl;
	std::srand(time(NULL));
	testDefaultConstructor();
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
