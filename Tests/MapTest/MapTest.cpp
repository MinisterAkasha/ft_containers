#include "MapTest.hpp"

MapTest::MapTest() {
	test();
}

MapTest::~MapTest() {}

void	MapTest::test() const {
	std::cout << std::endl << "<-- Map test -->" << std::endl << std::endl;
	std::srand(time(NULL));
}
