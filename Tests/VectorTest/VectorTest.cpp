#include "VectorTest.hpp"

VectorTest::VectorTest() {
	test();
}

VectorTest::~VectorTest() {
	//TODO delete all memory
}

void	VectorTest::test() const {
	std::cout << "<-- Vector test -->" << std::endl;
	// testSize();
	// testBegin();
	// testEnd();
	testFillConstructor();
}

void	VectorTest::testFillConstructor() const {
	std::cout << "* fill constuctor: ";
	size_t	size = 7;
	int		value = 4;
	ft::vector<int>		myVector(size, value);
	std::vector<int>	stlVector(size, value);

	// std::vector<int>::iterator stlIterator = stlVector.begin();
	ft::vector<int>::iterator myIterator = myVector.begin();
	while (myIterator != myVector.end())
	{
		std::cout << *myIterator << std::endl;
		myIterator++;
	}
	std::cout << std::endl;
}

void	VectorTest::testBegin() const {
	std::cout << "* begin(): ";

	{
		ft::vector<int>::iterator			myIterator;
		std::vector<int>::iterator			stlIterator;

		ft::vector<int>	myVector(10, 4);
		std::vector<int> stlVector(10, 4);

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_BE(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(10, std::string("string"));
		std::vector<std::string> stlVector(10, std::string("string"));

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_BE(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(25, std::string("loooooooooooooooong string"));
		std::vector<std::string> stlVector(25, std::string("loooooooooooooooong string"));

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_BE(*myIterator, *stlIterator);
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_BE(*myIterator, *stlIterator);
	}
	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myVector.insert(myVector.begin(), 10);
		stlVector.insert(stlVector.begin(), 10);

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_BE(*myIterator, *stlIterator);
	}


	std::cout << std::endl;
}

void	VectorTest::testEnd() const {
	std::cout << "* end(): ";

	{
		ft::vector<int>::iterator			myIterator;
		std::vector<int>::iterator			stlIterator;

		ft::vector<int>	myVector(100, 4);
		std::vector<int> stlVector(100, 4);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_BE(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(2, std::string("string"));
		std::vector<std::string> stlVector(2, std::string("string"));

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_BE(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(15, std::string("loooooooooooooooong string"));
		std::vector<std::string> stlVector(15, std::string("loooooooooooooooong string"));

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_BE(*myIterator, *stlIterator);
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_BE(*myIterator, *stlIterator);
	}
	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.pop_back();
		stlVector.pop_back();

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_BE(*myIterator, *stlIterator);
	}
	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_BE(*myIterator, *stlIterator);
	}

	std::cout << std::endl;
}

void	VectorTest::testSize() const {
	std::cout << "* size(): ";
	{
		ft::vector<int>		myVector(10, 0);
		std::vector<int> 	stlVector(10, 0);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_BE(s1, s2);
	}
	{
		ft::vector<int>		myVector(0, 0);
		std::vector<int> 	stlVector(0, 0);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_BE(s1, s2);
	}
	{
		ft::vector<int>		myVector(100, 100);
		std::vector<int> 	stlVector(100, 100);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_BE(s1, s2);
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);
		myVector.push_back(10);
		stlVector.push_back(10);

		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_BE(s1, s2);
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);
		myVector.pop_back();
		stlVector.pop_back();

		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_BE(s1, s2);
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);

		myVector.insert(myVector.begin(), 10);
		stlVector.insert(stlVector.begin(), 10);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_BE(s1, s2);
	}
	std::cout << std::endl;
}