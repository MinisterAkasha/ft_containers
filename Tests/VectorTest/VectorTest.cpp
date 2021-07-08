#include "VectorTest.hpp"

VectorTest::VectorTest() {
	test();
}

VectorTest::~VectorTest() {}

void	VectorTest::test() const {
	std::cout << "<-- Vector test -->" << std::endl;
	std::srand(time(NULL));
	testSize();
	testBegin();
	testEnd();
	testFillConstructor();
	testEqualOperator();
	testEmpty();
	testCapasity();
}

void	VectorTest::testFillConstructor() const {
	std::cout << "* fill constuctor: ";

	size_t size;
	{
		int		value = 4;
		size = 7;
		ft::vector<int>		myVector(size, value);
		std::vector<int>	stlVector(size, value);

		TO_EQUAL_VECTOR(myVector, stlVector);
	}
	{
		int		value = 0;
		size = 0;
		ft::vector<int>		myVector(size, value);
		std::vector<int>	stlVector(size, value);

		TO_EQUAL_VECTOR(myVector, stlVector);
	}
	{
				size = 0;
		int		value = 0;
		ft::vector<int>		myVector(size);
		std::vector<int>	stlVector(size);

		TO_EQUAL_VECTOR(myVector, stlVector);
	}
	{
		std::string		value = "string";
		size = 0;
		ft::vector<std::string>		myVector(size, value);
		std::vector<std::string>	stlVector(size, value);

		TO_EQUAL_VECTOR(myVector, stlVector);
	}
	{
		std::string		value = "string";
		size = 10;
		ft::vector<std::string>		myVector(size, value);
		std::vector<std::string>	stlVector(size, value);

		TO_EQUAL_VECTOR(myVector, stlVector);
	}
	{
		double		value = 132.021;
		size = 50;
		ft::vector<double>		myVector(size, value);
		std::vector<double>	stlVector(size, value);

		TO_EQUAL_VECTOR(myVector, stlVector);
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

		TO_EQUAL(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(10, std::string("string"));
		std::vector<std::string> stlVector(10, std::string("string"));

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_EQUAL(*myIterator, *stlIterator);
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(25, std::string("loooooooooooooooong string"));
		std::vector<std::string> stlVector(25, std::string("loooooooooooooooong string"));

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_EQUAL(*myIterator, *stlIterator);
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		TO_EQUAL(*myIterator, *stlIterator);
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

		TO_EQUAL(*myIterator, *stlIterator);
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

		TO_EQUAL(*(--myIterator), *(--stlIterator));
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_EQUAL(*(--myIterator), *(--stlIterator));
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_EQUAL(*(--myIterator), *(--stlIterator));
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		TO_EQUAL(*(--myIterator), *(--stlIterator));
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

		TO_EQUAL(*(--myIterator), *(--stlIterator));
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

		TO_EQUAL(*(--myIterator), *(--stlIterator));
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

		TO_EQUAL(s1, s2);
	}
	{
		ft::vector<int>		myVector(0, 0);
		std::vector<int> 	stlVector(0, 0);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_EQUAL(s1, s2);
	}
	{
		ft::vector<int>		myVector(100, 100);
		std::vector<int> 	stlVector(100, 100);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_EQUAL(s1, s2);
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);
		myVector.push_back(10);
		stlVector.push_back(10);

		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_EQUAL(s1, s2);
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);
		myVector.pop_back();
		stlVector.pop_back();

		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_EQUAL(s1, s2);
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);

		myVector.insert(myVector.begin(), 10);
		stlVector.insert(stlVector.begin(), 10);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		TO_EQUAL(s1, s2);
	}
	std::cout << std::endl;
}

void	VectorTest::testEqualOperator() const {
	std::cout << "* operator=(): ";
	{
		ft::vector<int> vector1(10, 4);
		ft::vector<int> vector2;

		vector2 = vector1;

		TO_EQUAL_VECTOR(vector1, vector2);
	}
	{
		ft::vector<int> vector1;
		ft::vector<int> vector2;

		vector2 = vector1;

		TO_EQUAL_VECTOR(vector1, vector2);
	}
	{
		ft::vector<double> vector1;
		ft::vector<double> vector2;

		for (int i = 0; i < 100; i++) {
			vector1.push_back(std::rand());
		}
		vector2 = vector1;

		TO_EQUAL_VECTOR(vector1, vector2);
	}
	{
		ft::vector<int> vector1(10, 15);
		ft::vector<int> vector2;

		for (int i = 0; i < 100; i++) {
			vector1.push_back(std::rand() % 1000);
		}
		vector2 = vector1;

		TO_EQUAL_VECTOR(vector1, vector2);
	}
	{
		ft::vector<std::string> vector1(10);
		ft::vector<std::string> vector2;

		for (int i = 0; i < 100; i++) {
			vector1.push_back("string");
		}
		vector2 = vector1;

		TO_EQUAL_VECTOR(vector1, vector2);
	}
	{
		ft::vector<std::string> vector1(10);
		ft::vector<std::string> vector2;

		for (int i = 0; i < 100; i++) {
			vector1.push_back("looooooooooooooooooooooooooooooooooooooooooooooooooong string");
		}

		vector2 = vector1;
		vector2.pop_back();
		vector1.pop_back();

		TO_EQUAL_VECTOR(vector1, vector2);
	}
	std::cout << std::endl;
}

void	VectorTest::testEmpty() const {
	std::cout << "* empty(): ";
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		TO_EQUAL(ftVector.empty(), stlVector.empty());
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		TO_EQUAL(ftVector.empty(), stlVector.empty());
	}
	{
		ft::vector<std::string> ftVector;
		std::vector<std::string> stlVector;

		TO_EQUAL(ftVector.empty(), stlVector.empty());
	}
	{
		ft::vector<std::string> ftVector(100);
		std::vector<std::string> stlVector(100);

		TO_EQUAL(ftVector.empty(), stlVector.empty());
	}
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		TO_EQUAL(ftVector.empty(), stlVector.empty());
	}
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		for (int i = 0; i < 25; i++) {
			ftVector.pop_back();
			stlVector.pop_back();
		}
		TO_EQUAL(ftVector.empty(), stlVector.empty());
	}
	std::cout << std::endl;
}

void	VectorTest::testCapasity() const {
	std::cout << "* capacity(): ";
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		TO_EQUAL(ftVector.capacity(), stlVector.capacity());
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		TO_EQUAL(ftVector.capacity(), stlVector.capacity());
	}
	{
		ft::vector<std::string> ftVector;
		std::vector<std::string> stlVector;

		TO_EQUAL(ftVector.capacity(), stlVector.capacity());
	}
	{
		ft::vector<std::string> ftVector(100);
		std::vector<std::string> stlVector(100);

		TO_EQUAL(ftVector.capacity(), stlVector.capacity());
	}
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		TO_EQUAL(ftVector.capacity(), stlVector.capacity());
	}
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		for (int i = 0; i < 25; i++) {
			ftVector.pop_back();
			stlVector.pop_back();
		}
		TO_EQUAL(ftVector.capacity(), stlVector.capacity());
	}
	std::cout << std::endl;
}
