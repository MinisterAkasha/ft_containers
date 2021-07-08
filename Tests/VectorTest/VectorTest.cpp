#include "VectorTest.hpp"

VectorTest::VectorTest() {
	test();
}

VectorTest::~VectorTest() {
	//TODO delete all memory
}

void	VectorTest::test() const {
	std::cout << "<-- Vector test -->" << std::endl;
	testBegin();
	// testFillConstructor();
}

void	VectorTest::testFillConstructor() const {
	size_t	size = 2;
	int		value = 4;
	ft::vector<int>		myVector(size, value);
	std::vector<int>	stlVector(size, value);

	std::vector<int>::iterator stlIterator = stlVector.begin();
	while (stlIterator != stlVector.end())
	{
		std::cout << *stlIterator << std::endl;
		stlIterator++;
	}
}

void	VectorTest::testBegin() const {
	std::cout << "Vector begin tests: ";

	{
		ft::vector<int>::iterator			myIterator;
		std::vector<int>::iterator			stlIterator;

		ft::vector<int>	myVector(10, 4);
		std::vector<int> stlVectro(10, 4);

		myIterator = myVector.begin();
		stlIterator = stlVectro.begin();

		IS_EQUIL(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(10, std::string("string"));
		std::vector<std::string> stlVectro(10, std::string("string"));

		myIterator = myVector.begin();
		stlIterator = stlVectro.begin();

		IS_EQUIL(*myIterator, *stlIterator);
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVectro(15, 7.025);

		myIterator = myVector.begin();
		stlIterator = stlVectro.begin();

		IS_EQUIL(*myIterator, *stlIterator);
	}

	//TODO тест после push/pop/insert ...

	std::cout << std::endl;
}