#include "VectorTest.hpp"

VectorTest::VectorTest() {
	test();
}

VectorTest::~VectorTest() {
	//TODO delete all memory
}

void	VectorTest::test() const {
	testFillConstructor();
}

void	VectorTest::testFillConstructor() const {
	size_t	size = 10;
	int		value = 4;
	ft::vector<int>		myVector(10, 4);
	std::vector<int>	stdVector(size, value);
}