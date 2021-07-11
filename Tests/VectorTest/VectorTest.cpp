#include "VectorTest.hpp"

VectorTest::VectorTest() {
	test();
}

VectorTest::~VectorTest() {}

void	VectorTest::test() const {
	std::cout << "<-- Vector test -->" << std::endl;
	std::srand(time(NULL));
	testReserve();
	testPopBack();
	testPushBack();
	testSingleInsert();
	testFillInsert();
	testRangeInsert();
	testSize();
	testBegin();
	testEnd();
	testFillConstructor();
	testRangeConstructor();
	testCopyConstructor();
	testEqualOperator();
	testEmpty();
	testCapasity();
	testMaxSize();
	testClear();
	testSingleErase();
	testRangeErase();
	testSwap();
	testGetAllocator();
	testFillAssign();
	testRangeAssign();
	testResize();
	testAccessOperator();
	testAt();
	testFront();
	testBack();
	testNonMemberEqualOperator();
	testNonMemberNotEqualOperator();
}

void	VectorTest::testFillConstructor() const {
	std::cout << "* fill constuctor: ";

	size_t size;
	{
		int		value = 4;
		size = 7;
		ft::vector<int>		myVector(size, value);
		std::vector<int>	stlVector(size, value);

		PRINT_RESULT(TO_EQUAL_VECTOR(myVector, stlVector));
	}
	{
		int		value = 0;
		size = 0;
		ft::vector<int>		myVector(size, value);
		std::vector<int>	stlVector(size, value);

		PRINT_RESULT(TO_EQUAL_VECTOR(myVector, stlVector));
	}
	{
				size = 0;
		int		value = 0;
		ft::vector<int>		myVector(size);
		std::vector<int>	stlVector(size);

		PRINT_RESULT(TO_EQUAL_VECTOR(myVector, stlVector));
	}
	{
		std::string		value = "string";
		size = 0;
		ft::vector<std::string>		myVector(size, value);
		std::vector<std::string>	stlVector(size, value);

		PRINT_RESULT(TO_EQUAL_VECTOR(myVector, stlVector));
	}
	{
		std::string		value = "string";
		size = 10;
		ft::vector<std::string>		myVector(size, value);
		std::vector<std::string>	stlVector(size, value);

		PRINT_RESULT(TO_EQUAL_VECTOR(myVector, stlVector));
	}
	{
		double		value = 132.021;
		size = 50;
		ft::vector<double>		myVector(size, value);
		std::vector<double>	stlVector(size, value);

		PRINT_RESULT(TO_EQUAL_VECTOR(myVector, stlVector));
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

		PRINT_RESULT(TO_EQUAL(*myIterator, *stlIterator));
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(10, std::string("string"));
		std::vector<std::string> stlVector(10, std::string("string"));

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*myIterator, *stlIterator));
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(25, std::string("loooooooooooooooong string"));
		std::vector<std::string> stlVector(25, std::string("loooooooooooooooong string"));

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*myIterator, *stlIterator));
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*myIterator, *stlIterator));
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

		PRINT_RESULT(TO_EQUAL(*myIterator, *stlIterator));
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

		PRINT_RESULT(TO_EQUAL(*(--myIterator), *(--stlIterator)));
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--myIterator), *(--stlIterator)));
	}

	{
		ft::vector<std::string>::iterator	myIterator;
		std::vector<std::string>::iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--myIterator), *(--stlIterator)));
	}

	{
		ft::vector<double>::iterator			myIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--myIterator), *(--stlIterator)));
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

		PRINT_RESULT(TO_EQUAL(*(--myIterator), *(--stlIterator)));
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

		PRINT_RESULT(TO_EQUAL(*(--myIterator), *(--stlIterator)));
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

		PRINT_RESULT(TO_EQUAL(s1, s2));
	}
	{
		ft::vector<int>		myVector(0, 0);
		std::vector<int> 	stlVector(0, 0);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		PRINT_RESULT(TO_EQUAL(s1, s2));
	}
	{
		ft::vector<int>		myVector(100, 100);
		std::vector<int> 	stlVector(100, 100);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		PRINT_RESULT(TO_EQUAL(s1, s2));
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);
		myVector.push_back(10);
		stlVector.push_back(10);

		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		PRINT_RESULT(TO_EQUAL(s1, s2));
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);
		myVector.pop_back();
		stlVector.pop_back();

		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		PRINT_RESULT(TO_EQUAL(s1, s2));
	}
	{
		ft::vector<int>		myVector(15, 15);
		std::vector<int> 	stlVector(15, 15);

		myVector.insert(myVector.begin(), 10);
		stlVector.insert(stlVector.begin(), 10);
		size_t				s1 = myVector.size();
		size_t				s2 = stlVector.size();

		PRINT_RESULT(TO_EQUAL(s1, s2));
	}
	std::cout << std::endl;
}

void	VectorTest::testEqualOperator() const {
	std::cout << "* operator=(): ";
	{
		ft::vector<int> vector1(10, 4);
		ft::vector<int> vector2;

		vector2 = vector1;

		PRINT_RESULT(TO_EQUAL_VECTOR(vector1, vector2));
	}
	{
		ft::vector<int> vector1;
		ft::vector<int> vector2;

		vector2 = vector1;

		PRINT_RESULT(TO_EQUAL_VECTOR(vector1, vector2));
	}
	{
		ft::vector<double> vector1;
		ft::vector<double> vector2;

		for (int i = 0; i < 5; i++) {
			vector1.push_back(std::rand());
		}
		vector2 = vector1;

		PRINT_RESULT(TO_EQUAL_VECTOR(vector1, vector2));
	}
	{
		ft::vector<int> vector1(10, 15);
		ft::vector<int> vector2;

		for (int i = 0; i < 100; i++) {
			vector1.push_back(std::rand() % 1000);
		}
		vector2 = vector1;

		PRINT_RESULT(TO_EQUAL_VECTOR(vector1, vector2));
	}
	{
		ft::vector<std::string> vector1(10);
		ft::vector<std::string> vector2;

		for (int i = 0; i < 100; i++) {
			vector1.push_back("string");
		}
		vector2 = vector1;

		PRINT_RESULT(TO_EQUAL_VECTOR(vector1, vector2));
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

		PRINT_RESULT(TO_EQUAL_VECTOR(vector1, vector2));
	}
	std::cout << std::endl;
}

void	VectorTest::testEmpty() const {
	std::cout << "* empty(): ";
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		PRINT_RESULT(TO_EQUAL(ftVector.empty(), stlVector.empty()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		PRINT_RESULT(TO_EQUAL(ftVector.empty(), stlVector.empty()));
	}
	{
		ft::vector<std::string> ftVector;
		std::vector<std::string> stlVector;

		PRINT_RESULT(TO_EQUAL(ftVector.empty(), stlVector.empty()));
	}
	{
		ft::vector<std::string> ftVector(100);
		std::vector<std::string> stlVector(100);

		PRINT_RESULT(TO_EQUAL(ftVector.empty(), stlVector.empty()));
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
		PRINT_RESULT(TO_EQUAL(ftVector.empty(), stlVector.empty()));
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
		PRINT_RESULT(TO_EQUAL(ftVector.empty(), stlVector.empty()));
	}
	std::cout << std::endl;
}

void	VectorTest::testCapasity() const {
	std::cout << "* capacity(): ";
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;
		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		createRandomVectors(ftVector1, stlVector1, 100);
		createRandomVectors(ftVector2, stlVector2, 15);

		ftVector1.swap(ftVector2);
		stlVector1.swap(stlVector2);

		PRINT_RESULT(TO_EQUAL(ftVector1.capacity(), stlVector1.capacity()) && TO_EQUAL(ftVector2.capacity(), stlVector2.capacity()));
	}
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;
		std::vector<int> stlVector1;
		std::vector<int> stlVector2;


		ftVector1.swap(ftVector2);
		stlVector1.swap(stlVector2);

		PRINT_RESULT(TO_EQUAL(ftVector1.capacity(), stlVector1.capacity()) && TO_EQUAL(ftVector2.capacity(), stlVector2.capacity()));
	}
	{
		ft::vector<int> ftVector1(10, 15);
		ft::vector<int> ftVector2(100, 4);
		std::vector<int> stlVector1(10, 15);
		std::vector<int> stlVector2(100, 4);

		createRandomVectors(ftVector1, stlVector1, 100);
		createRandomVectors(ftVector2, stlVector2, 15);

		ftVector1.swap(ftVector2);
		stlVector1.swap(stlVector2);

		PRINT_RESULT(TO_EQUAL(ftVector1.capacity(), stlVector1.capacity()) && TO_EQUAL(ftVector2.capacity(), stlVector2.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string> ftVector;
		std::vector<std::string> stlVector;

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		ftVector.push_back(10);
		stlVector.push_back(10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string> ftVector(100);
		std::vector<std::string> stlVector(100);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
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
		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
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
		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	std::cout << std::endl;
}

void	VectorTest::testMaxSize() const {
	std::cout << "* max_size(): ";
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<std::string> ftVector;
		std::vector<std::string> stlVector;

		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<std::string> ftVector(100);
		std::vector<std::string> stlVector(100);

		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
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
		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
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
		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<int> ftVector(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 10000; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		PRINT_RESULT(TO_EQUAL(ftVector.max_size(), stlVector.max_size()));
	}
	std::cout << std::endl;
}

void	VectorTest::testSingleInsert() const {
	std::cout << "* insert()<single elem>: ";
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ftVector.end();
		std::vector<int>::iterator	stlIterator = stlVector.end();

		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ftVector.end()++;
		std::vector<int>::iterator	stlIterator = stlVector.end()++;

		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(5, 4);
		std::vector<int>	stlVector(5, 4);

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		
		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ftVector.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);


		for (int i = 0; i < 100; i++) {
			ftVector.push_back(i);
			stlVector.push_back(i);
		
		}
		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 2;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 2;
		
		ftVector.insert(ftIterator, 100);
		stlVector.insert(stlIterator, 100);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);


		for (int i = 0; i < 100; i++) {
			ftVector.push_back(i);
			stlVector.push_back(i);
		
		}
		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 2;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 2;
		
		PRINT_RESULT(TO_EQUAL(*ftVector.insert(ftIterator, 100), *stlVector.insert(stlIterator, 100)));
	}
	{
		ft::vector<int>		ftVector(100, 15);
		std::vector<int>	stlVector(100, 15);


		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();
		
		PRINT_RESULT(TO_EQUAL(*ftVector.insert(ftIterator, 100), *stlVector.insert(stlIterator, 100)));
	}
	{
		ft::vector<int>		ftVector(100, 15);
		std::vector<int>	stlVector(100, 15);


		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());
		
		PRINT_RESULT(TO_EQUAL(*ftVector.insert(ftIterator, 100), *stlVector.insert(stlIterator, 100)));
	}
	{
		ft::vector<std::string>		ftVector(100, std::string("vector"));
		std::vector<std::string>	stlVector(100, std::string("vector"));


		ft::vector<std::string>::iterator	ftIterator = ftVector.begin() + 50;
		std::vector<std::string>::iterator	stlIterator = stlVector.begin() + 50;
		
		PRINT_RESULT(TO_EQUAL(*ftVector.insert(ftIterator, std::string("insert")), *stlVector.insert(stlIterator, std::string("insert"))));
	}
	std::cout << std::endl;
}

void	VectorTest::testPopBack() const {
	std::cout << "* pop_back(): ";
	{
		ft::vector<int>		ftVector(10, 10);
		std::vector<int>	stlVector(10, 10);

		ftVector.pop_back();
		stlVector.pop_back();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(100, 1000);
		std::vector<int>	stlVector(100, 1000);

		for (int i = 0; i < 100; i++) {
			ftVector.pop_back();
			stlVector.pop_back();
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(100, std::string("string"));
		std::vector<std::string>	stlVector(100, std::string("string"));

		for (int i = 0; i < 50; i++) {
			ftVector.pop_back();
			stlVector.pop_back();
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(1, std::string("looooooooooooooooooooooooooooong string"));
		std::vector<std::string>	stlVector(1, std::string("looooooooooooooooooooooooooooong string"));

		ftVector.pop_back();
		stlVector.pop_back();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testPushBack() const {
	std::cout << "* push_back(): ";
	{
		ft::vector<int>		ftVector(10, 10);
		std::vector<int>	stlVector(10, 10);

		ftVector.push_back(4);
		stlVector.push_back(4);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(100, 1000);
		std::vector<int>	stlVector(100, 1000);

		for (int i = 0; i < 100; i++) {
			ftVector.push_back(i);
			stlVector.push_back(i);
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(100, std::string("string"));
		std::vector<std::string>	stlVector(100, std::string("string"));

		for (int i = 0; i < 50; i++) {
			ftVector.push_back("s");
			stlVector.push_back("s");
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(1, std::string("looooooooooooooooooooooooooooong string"));
		std::vector<std::string>	stlVector(1, std::string("looooooooooooooooooooooooooooong string"));

		ftVector.push_back("vector");
		stlVector.push_back("vector");

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector;
		std::vector<std::string>	stlVector;

		ftVector.push_back("vector");
		stlVector.push_back("vector");

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testReserve() const {
	std::cout << "* reserve(): ";
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ftVector.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ftVector.reserve(0);
		stlVector.reserve(0);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ftVector.reserve(0);
		stlVector.reserve(0);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ftVector.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string>		ftVector;
		std::vector<std::string>	stlVector;

		ftVector.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string>		ftVector(10, std::string("vector"));
		std::vector<std::string>	stlVector(10, std::string("vector"));

		ftVector.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string>		ftVector(10, std::string("vector"));
		std::vector<std::string>	stlVector(10, std::string("vector"));

		ftVector.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testFillInsert() const {
	std::cout << "* insert()<fill>: ";
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, 4, 14);
		stlVector.insert(stlIterator, 4, 14);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ftVector.end();
		std::vector<int>::iterator	stlIterator = stlVector.end();

		ftVector.insert(ftIterator, 10, 5);
		stlVector.insert(stlIterator, 10, 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ftVector.end()++;
		std::vector<int>::iterator	stlIterator = stlVector.end()++;

		ftVector.insert(ftIterator, 10, 5);
		stlVector.insert(stlIterator, 10, 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ftVector.insert(ftIterator, 2, 17);
		stlVector.insert(stlIterator, 2, 17);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(5, 4);
		std::vector<int>	stlVector(5, 4);

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, 10, 50);
		stlVector.insert(stlIterator, 10, 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		
		ftVector.insert(ftIterator, 0, 10);
		stlVector.insert(stlIterator, 0, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);

		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ftVector.insert(ftIterator, 10, 1);
		stlVector.insert(stlIterator, 10, 1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(10, 4);
		std::vector<int>	stlVector(10, 4);


		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 2;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 2;
		
		ftVector.insert(ftIterator, 100, 10);
		stlVector.insert(stlIterator, 100, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(55, 4);
		std::vector<int>	stlVector(55, 4);

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, 55, 1);
		stlVector.insert(stlIterator, 55, 1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(55, 4);
		std::vector<int>	stlVector(55, 4);

		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 10;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 10;

		ftVector.insert(ftIterator, 1, 55);
		stlVector.insert(stlIterator, 1, 55);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(55, 4);
		std::vector<int>	stlVector(55, 4);

		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 10;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 10;

		ftVector.insert(ftIterator, 100, 55);
		stlVector.insert(stlIterator, 100, 55);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeInsert() const {
	std::cout << "* insert()<range>: ";
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, arr, arr + 5);
		stlVector.insert(stlIterator, arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(20, 3);
		std::vector<int>	stlVector(20, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 5;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 5;

		ftVector.insert(ftIterator, arr, arr);
		stlVector.insert(stlIterator, arr, arr);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(20, 3);
		std::vector<int>	stlVector(20, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ftVector.begin() + 5;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 5;

		ftVector.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(20, 3);
		std::vector<int>	stlVector(20, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ftVector.end() - 5;
		std::vector<int>::iterator	stlIterator = stlVector.end() - 5;

		ftVector.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		int arr[] = {1, 2, 3, 4, 5, 10};

		createRandomVectors(ftVector, stlVector, 10);

		ft::vector<int>::iterator	ftIterator = ftVector.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		stlVector.insert(stlIterator, arr, arr + 6);
		ftVector.insert(ftIterator, arr, arr + 6);
		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(20, "vector");
		std::vector<std::string>	stlVector(20, "vector");
		std::string arr[] = {"vector1", "vector2", "vector3", "vector4", "vector5", "vector6"};

		ft::vector<std::string>::iterator	ftIterator = ftVector.end() - 5;
		std::vector<std::string>::iterator	stlIterator = stlVector.end() - 5;

		ftVector.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector;
		std::vector<std::string>	stlVector;
		std::string arr[] = {"vector1", "vector2", "vector3", "vector4", "vector5", "vector6"};

		ft::vector<std::string>::iterator	ftIterator = ftVector.end()--;
		std::vector<std::string>::iterator	stlIterator = stlVector.end()--;

		ftVector.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector;
		std::vector<std::string>	stlVector;
		std::string arr[] = {"vector1", "vector2", "vector3", "vector4", "vector5", "vector6"};

		ft::vector<std::string>::iterator	ftIterator = ftVector.begin();
		std::vector<std::string>::iterator	stlIterator = stlVector.begin();

		ftVector.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testClear() const {
	std::cout << "* clear(): ";
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(200, 3);
		std::vector<int>	stlVector(200, 3);
		
		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 1000);

		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(200, "vector");
		std::vector<std::string>	stlVector(200, "vector");
		
		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector;
		std::vector<std::string>	stlVector;
		
		ftVector.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testSingleErase() const {
	std::cout << "* erase()<single>: ";
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ftVector.erase(ftVector.begin());
		stlVector.erase(stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ftVector.erase(--ftVector.end());
		stlVector.erase(--stlVector.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin());
		stlVector.erase(stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin() + 50);
		stlVector.erase(stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin() + 50);
		stlVector.erase(stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin() + 50);
		stlVector.erase(stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.end() - 50);
		stlVector.erase(stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ftVector.erase(ftVector.begin());
		stlVector.erase(stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ftVector.erase(ftVector.begin() + 5);
		stlVector.erase(stlVector.begin() + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ftVector.erase(ftVector.begin() + 9);
		stlVector.erase(stlVector.begin() + 9);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin()), *stlVector.erase(stlVector.begin())));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin()), *stlVector.erase(stlVector.begin())));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin() + 50), *stlVector.erase(stlVector.begin() + 50)));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);


		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin() + 50), *stlVector.erase(stlVector.begin() + 50)));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin() + 50), *stlVector.erase(stlVector.begin() + 50)));
	}
	{
		ft::vector<int>		ftVector(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ftVector, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.end() - 50), *stlVector.erase(stlVector.end() - 50)));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin()), *stlVector.erase(stlVector.begin())));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin() + 5), *stlVector.erase(stlVector.begin() + 5)));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		PRINT_RESULT(TO_EQUAL(*ftVector.erase(ftVector.begin() + 9), *stlVector.erase(stlVector.begin() + 9)));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeErase() const {
	std::cout << "* erase()<range>: ";
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ftVector.erase(ftVector.begin(), ftVector.begin() + 1);
		stlVector.erase(stlVector.begin(), stlVector.begin() + 1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 2);

		ftVector.erase(ftVector.begin(), ftVector.end());
		stlVector.erase(stlVector.begin(), stlVector.end());

		ft::vector<int>::iterator ftItr = ftVector.begin();
		std::vector<int>::iterator stlItr = stlVector.begin();


		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin() + 50, ftVector.begin() + 80);
		stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin() + 50, ftVector.begin() + 80);
		stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin() + 50, ftVector.begin() + 80);
		stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.begin(), ftVector.end());
		stlVector.erase(stlVector.begin(), stlVector.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ftVector, stlVector, 100);

		ftVector.erase(ftVector.end() - 80, ftVector.end() - 50);
		stlVector.erase(stlVector.end() - 80, stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ftVector.erase(ftVector.begin(), ftVector.begin());
		stlVector.erase(stlVector.begin(), stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ftVector.erase(ftVector.begin() + 5, ftVector.begin() + 8);
		stlVector.erase(stlVector.begin() + 5, stlVector.begin() + 8);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ftVector.erase(ftVector.begin(), ftVector.begin() + 9);
		stlVector.erase(stlVector.begin(), stlVector.begin() + 9);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin(), ftVector.begin() + 1);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 1);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin(), ftVector.begin() + 50);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin() + 50, ftVector.begin() + 80);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin() + 50, ftVector.begin() + 80);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);


		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector(100, 150);
		std::vector<int>	stlVector(100, 150);
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin() + 50, ftVector.end());
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 50, stlVector.end());

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 5);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin() + 2, ftVector.begin() + 4);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 2, stlVector.begin() + 4);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.end() - 80, ftVector.end() - 50);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.end() - 80, stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.end() - 80, ftVector.end() - 50);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.end() - 80, stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ftVector;
		std::vector<int>	stlVector;
		
		createRandomVectors(ftVector, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ftVector.erase(ftVector.begin(), ftVector.end() - 1);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.end() - 1);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");

		ft::vector<std::string>::iterator	ftIterator = ftVector.erase(ftVector.begin(), ftVector.begin() + 5);
		std::vector<std::string>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 5);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");

		ft::vector<std::string>::iterator	ftIterator = ftVector.erase(ftVector.begin(), ftVector.begin());
		std::vector<std::string>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 5);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<std::string>		ftVector(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");

		ft::vector<std::string>::iterator	ftIterator = ftVector.erase(ftVector.begin(), ftVector.begin() + 9);
		std::vector<std::string>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 9);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	std::cout << std::endl;
}

void	VectorTest::testSwap() const {
	std::cout << "* swap(): ";
	{
		ft::vector<int>	ftVector1(10, 10);
		ft::vector<int>	ftVector2(5, 20);

		std::vector<int>	stlVector1(10, 10);
		std::vector<int>	stlVector2(5, 20);

		stlVector1.swap(stlVector2);
		ftVector1.swap(ftVector2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	{
		ft::vector<int>	ftVector1(10, 10);
		ft::vector<int>	ftVector2(1, 2);

		std::vector<int>	stlVector1(10, 10);
		std::vector<int>	stlVector2(1, 2);

		stlVector1.swap(stlVector2);
		ftVector1.swap(ftVector2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	{
		ft::vector<int>	ftVector1;
		ft::vector<int>	ftVector2;

		std::vector<int>	stlVector1;
		std::vector<int>	stlVector2;

		createRandomVectors(ftVector1, stlVector1, 100);
		createRandomVectors(ftVector2, stlVector2, 15);

		stlVector1.swap(stlVector2);
		ftVector1.swap(ftVector2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	{
		ft::vector<int>	ftVector1;
		ft::vector<int>	ftVector2;

		std::vector<int>	stlVector1;
		std::vector<int>	stlVector2;

		createRandomVectors(ftVector1, stlVector1, 100);
		createRandomVectors(ftVector2, stlVector2, 15);

		stlVector1.swap(stlVector1);
		ftVector1.swap(ftVector1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	{
		ft::vector<int>	ftVector1;
		ft::vector<int>	ftVector2;

		std::vector<int>	stlVector1;
		std::vector<int>	stlVector2;

		stlVector1.swap(stlVector1);
		ftVector1.swap(ftVector1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	{
		ft::vector<std::string>	ftVector1;
		ft::vector<std::string>	ftVector2;

		std::vector<std::string>	stlVector1;
		std::vector<std::string>	stlVector2;

		stlVector1.swap(stlVector1);
		ftVector1.swap(ftVector1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	{
		ft::vector<std::string>	ftVector1(10, "vector");
		ft::vector<std::string>	ftVector2(2, "swap");

		std::vector<std::string>	stlVector1(10, "vector");
		std::vector<std::string>	stlVector2(2, "swap");

		stlVector1.swap(stlVector1);
		ftVector1.swap(ftVector1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector1, stlVector1) && TO_EQUAL_VECTOR(ftVector2, stlVector2));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberEqualOperator() const {
	std::cout << "* operator== <non-member>: ";
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		PRINT_RESULT((ftVector1 == ftVector2) && (stlVector1 == stlVector2));
	}
	{
		ft::vector<int> ftVector1(10, 10);
		ft::vector<int> ftVector2(10, 10);

		std::vector<int> stlVector1(10, 10);
		std::vector<int> stlVector2(10, 10);

		PRINT_RESULT((ftVector1 == ftVector2) && (stlVector1 == stlVector2));
	}
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		PRINT_RESULT((ftVector1 == ftVector2) && (stlVector1 == stlVector2));
	}
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		createRandomVectors(ftVector1, ftVector2, 100);
		createRandomVectors(stlVector1, stlVector2, 100);

		PRINT_RESULT((ftVector1 == ftVector2) && (stlVector1 == stlVector2));
	}
	{
		ft::vector<std::string> ftVector1;
		ft::vector<std::string> ftVector2;

		std::vector<std::string> stlVector1;
		std::vector<std::string> stlVector2;

		PRINT_RESULT((ftVector1 == ftVector2) && (stlVector1 == stlVector2));
	}
	{
		ft::vector<std::string> ftVector1(10, "vector");
		ft::vector<std::string> ftVector2(10, "vector");

		std::vector<std::string> stlVector1(10, "vector");
		std::vector<std::string> stlVector2(10, "vector");

		PRINT_RESULT((ftVector1 == ftVector2) && (stlVector1 == stlVector2));
	}
	std::cout << std::endl;
}

void	VectorTest::testGetAllocator() const {
	std::cout << "* get_allocator(): ";
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		PRINT_RESULT(ftVector1.get_allocator() == ftVector2.get_allocator());
	}
	std::cout << std::endl;
}

void	VectorTest::testFillAssign() const {
	std::cout << "* assign()<fill>: ";
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		createRandomVectors(ftVector, stlVector, 100);
		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 10);
		std::vector<int> stlVector(10, 10);

		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 10);
		std::vector<int> stlVector(10, 10);

		ftVector.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 10);
		std::vector<int> stlVector(10, 10);

		ftVector.assign(1000, 10);
		stlVector.assign(1000, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 10);
		std::vector<int> stlVector(10, 10);

		createRandomVectors(ftVector, stlVector, 100);
		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10);
		std::vector<int> stlVector(10);

		createRandomVectors(ftVector, stlVector, 100);
		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10);
		std::vector<int> stlVector(10);

		createRandomVectors(ftVector, stlVector, 100);
		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		removeElemsFromVector(ftVector, 5);
		removeElemsFromVector(stlVector, 5);
		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10);
		std::vector<int> stlVector(10);

		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		removeElemsFromVector(ftVector, 10);
		removeElemsFromVector(stlVector, 10);
		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(100);
		std::vector<int> stlVector(100);

		ftVector.assign(5, 10);
		stlVector.assign(5, 10);

		removeElemsFromVector(ftVector, 5);
		removeElemsFromVector(stlVector, 5);
		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;


		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;


		ftVector.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector(100, 100);
		std::vector<int> stlVector(100, 100);


		ftVector.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		createRandomVectors(ftVector, stlVector, 100);

		ftVector.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		createRandomVectors(ftVector, stlVector, 100);

		ftVector.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		createRandomVectors(ftVector, stlVector, 100);

		ftVector.assign(110, 10);
		stlVector.assign(110, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		createRandomVectors(ftVector, stlVector, 0);

		ftVector.assign(110, 10);
		stlVector.assign(110, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;

		createRandomVectors(ftVector, stlVector, 0);

		ftVector.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeAssign() const {
	std::cout << "* assign()<range>: ";
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10);
		std::vector<int> stlVector(10);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 20);
		std::vector<int> stlVector(10, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 20);
		std::vector<int> stlVector(10, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 10);
		stlVector.assign(arr, arr + 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector(10, 20);
		ft::vector<int> ftSupport;
		std::vector<int> stlVector(10, 20);
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ftVector.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ftVector.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}
	{
		ft::vector<int> ftVector;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ftVector.assign(ftSupport.begin(), ftSupport.end());
		stlVector.assign(stlSupport.begin(), stlSupport.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ftVector, stlVector));
	}

	{
		ft::vector<int> ftVector;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ftVector.assign(ftSupport.begin(), ftSupport.end());
		stlVector.assign(stlSupport.begin(), stlSupport.end());

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ftVector.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector(500, 10);
		ft::vector<int> ftSupport;
		std::vector<int> stlVector(500, 10);
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ftVector.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector;
		std::vector<int> stlVector;
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector(2, 20);
		std::vector<int> stlVector(2, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ftVector(100, 20);
		std::vector<int> stlVector(100, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ftVector.assign(arr, arr + 10);
		stlVector.assign(arr, arr + 10);

		PRINT_RESULT(TO_EQUAL(ftVector.capacity(), stlVector.capacity()));
	}
	std::cout << std::endl;
}

void	VectorTest::testResize() const {
	std::cout << "* resize(): ";
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		ft.resize(10);
		stl.resize(10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(100);
		std::vector<int> stl(100);

		ft.resize(10);
		stl.resize(10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(100);
		std::vector<int> stl(100);

		ft.resize(110);
		stl.resize(110);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(100);
		std::vector<int> stl(100);

		ft.resize(10, 10);
		stl.resize(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(100, 10);
		std::vector<int> stl(100, 10);

		ft.resize(10);
		stl.resize(10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(100, 10);
		std::vector<int> stl(100, 10);

		ft.resize(10, 4);
		stl.resize(10, 4);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(100, 10);
		std::vector<int> stl(100, 10);

		ft.resize(110, 4);
		stl.resize(110, 4);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft(1, 10);
		std::vector<int> stl(1, 10);

		ft.resize(5, 4);
		stl.resize(5, 4);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		ft.resize(5, 4);
		stl.resize(5, 4);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));	
	}
	
	// { //TODO
	// 	ft::vector<int> ft;
	// 	std::vector<int> stl;

	// 	ft.resize(10);
	// 	stl.resize(10);

	// 	PRINT_RESULT(TO_EQUAL(ft.capacity(), stl.capacity()));	
	// }
	// {
	// 	ft::vector<int> ft(100);
	// 	std::vector<int> stl(100);

	// 	ft.resize(10);
	// 	stl.resize(10);

	// 	PRINT_RESULT(TO_EQUAL(ft.capacity(), stl.capacity()));	
	// }
	// {
	// 	ft::vector<int> ft(100);
	// 	std::vector<int> stl(100);

	// 	ft.resize(10, 10);
	// 	stl.resize(10, 10);

	// 	PRINT_RESULT(TO_EQUAL(ft.capacity(), stl.capacity()));	
	// }
	// {
	// 	ft::vector<int> ft(100, 10);
	// 	std::vector<int> stl(100, 10);

	// 	ft.resize(10);
	// 	stl.resize(10);

	// 	PRINT_RESULT(TO_EQUAL(ft.capacity(), stl.capacity()));	
	// }
	// {
	// 	ft::vector<int> ft(100, 10);
	// 	std::vector<int> stl(100, 10);

	// 	ft.resize(10, 4);
	// 	stl.resize(10, 4);

	// 	PRINT_RESULT(TO_EQUAL(ft.capacity(), stl.capacity()));	
	// }
	// {
	// 	ft::vector<int> ft(100, 10);
	// 	std::vector<int> stl(100, 10);

	// 	ft.resize(110, 4);
	// 	stl.resize(110, 4);

	// 	PRINT_RESULT(TO_EQUAL(ft.capacity(), stl.capacity()));	
	// }
	std::cout << std::endl;
}

void	VectorTest::testAccessOperator() const {
	std::cout << "* operator[]: ";
	{
		ft::vector<int>		ft;
		std::vector<int>	stl;

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft[0], stl[0]));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft[99], stl[99]));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft[99], stl[99]));
	}
	{
		ft::vector<int>		ft(10, 10);
		std::vector<int>	stl(10, 10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft[50], stl[50]));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft[5], stl[5]));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft[9], stl[9]));
	}
	std::cout << std::endl;
}

void	VectorTest::testAt() const {
	std::cout << "* at(): ";
	{
		ft::vector<int>		ft;
		std::vector<int>	stl;

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.at(0), stl.at(0)));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.at(99), stl.at(99)));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.at(99), stl.at(99)));
	}
	{
		ft::vector<int>		ft(10, 10);
		std::vector<int>	stl(10, 10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.at(50), stl.at(50)));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.at(5), stl.at(5)));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.at(9), stl.at(9)));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		try {
			PRINT_RESULT(TO_EQUAL(ft.at(12), stl.at(12)));
		} catch (std::out_of_range) {
			PRINT_RESULT(true);
		}
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		try {
			PRINT_RESULT(TO_EQUAL(ft.at(10), stl.at(10)));
		} catch (std::out_of_range) {
			PRINT_RESULT(true);
		}
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		try {
			PRINT_RESULT(TO_EQUAL(ft.at(100), stl.at(100)));
		} catch (std::out_of_range) {
			PRINT_RESULT(true);
		}
	}
	std::cout << std::endl;
}

void	VectorTest::testFront() const {
	std::cout << "* front(): ";
	{
		ft::vector<int>		ft;
		std::vector<int>	stl;

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		ft.push_back(1);
		stl.push_back(2);

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<int>		ft(10, 10);
		std::vector<int>	stl(10, 10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.front(), stl.front()));
	}
	std::cout << std::endl;
}

void	VectorTest::testBack() const {
	std::cout << "* back(): ";
	{
		ft::vector<int>		ft;
		std::vector<int>	stl;

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<int>		ft(10, 10);
		std::vector<int>	stl(10, 10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stl(10, "vector");

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	{
		ft::vector<int>		ft(10);
		std::vector<int>	stl(10);

		createRandomVectors(ft, stl, 100);

		PRINT_RESULT(TO_EQUAL(ft.back(), stl.back()));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeConstructor() const {
	std::cout << "* range constructor: ";
	{
		ft::vector<int>		ftSupport(10, 100);
		std::vector<int>	stlSupport(10, 100);

		ft::vector<int>::iterator ftIter = ftSupport.begin();
		std::vector<int>::iterator stlIter = stlSupport.begin();

		ft::vector<int>		ft(ftIter, ftIter + 5);
		std::vector<int>	stl(stlIter, stlIter + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<int>		ftSupport(10, 100);
		std::vector<int>	stlSupport(10, 100);

		ft::vector<int>::iterator ftIter = ftSupport.begin();
		std::vector<int>::iterator stlIter = stlSupport.begin();

		ft::vector<int>		ft(ftIter, ftSupport.end());
		std::vector<int>	stl(stlIter, stlSupport.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<int>		ftSupport;
		std::vector<int>	stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft::vector<int>::iterator ftIter = ftSupport.begin();
		std::vector<int>::iterator stlIter = stlSupport.begin();

		ft::vector<int>		ft(ftIter, ftSupport.end());
		std::vector<int>	stl(stlIter, stlSupport.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<int>		ftSupport;
		std::vector<int>	stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft::vector<int>::iterator ftIter = ftSupport.begin();
		std::vector<int>::iterator stlIter = stlSupport.begin();

		ft::vector<int>		ft(ftIter, ftIter + 10);
		std::vector<int>	stl(stlIter, stlIter + 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<std::string>		ftSupport(50, "vector");
		std::vector<std::string>	stlSupport(50, "vector");

		ft::vector<std::string>::iterator ftIter = ftSupport.begin();
		std::vector<std::string>::iterator stlIter = stlSupport.begin();

		ft::vector<std::string>		ft(ftIter, ftIter + 40);
		std::vector<std::string>	stl(stlIter, stlIter + 40);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<std::string>		ftSupport(50, "vector");
		std::vector<std::string>	stlSupport(50, "vector");

		ft::vector<std::string>::iterator ftIter = ftSupport.begin();
		std::vector<std::string>::iterator stlIter = stlSupport.begin();

		ft::vector<std::string>		ft(ftIter, ftIter);
		std::vector<std::string>	stl(stlIter, stlIter);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<std::string>		ftSupport(50, "vector");
		std::vector<std::string>	stlSupport(50, "vector");

		ft::vector<std::string>::iterator ftIter = ftSupport.end();
		std::vector<std::string>::iterator stlIter = stlSupport.end();

		ft::vector<std::string>		ft(ftIter, ftIter);
		std::vector<std::string>	stl(stlIter, stlIter);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	std::cout << std::endl;
}

void	VectorTest::testCopyConstructor() const {
	std::cout << "* copy constructor: ";
	{
		ft::vector<int>		ftSupport(10, 100);
		std::vector<int>	stlSupport(10, 100);

		ft::vector<int>		ft(ftSupport);
		std::vector<int>	stl(stlSupport);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<int>		ftSupport(10, 100);
		std::vector<int>	stlSupport(10, 100);

		ft::vector<int>		ft(ftSupport);
		std::vector<int>	stl(stlSupport);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<int>		ftSupport;
		std::vector<int>	stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft::vector<int>		ft(ftSupport);
		std::vector<int>	stl(stlSupport);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<int>		ftSupport;
		std::vector<int>	stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft::vector<int>		ft(ftSupport);
		std::vector<int>	stl(stlSupport);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<std::string>		ftSupport(50, "vector");
		std::vector<std::string>	stlSupport(50, "vector");

		ft::vector<std::string>		ft(ftSupport);
		std::vector<std::string>	stl(stlSupport);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	{
		ft::vector<std::string>		ftSupport(50, "vector");
		std::vector<std::string>	stlSupport(50, "vector");

		ft::vector<std::string>		ft(ftSupport);
		std::vector<std::string>	stl(stlSupport);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stl));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberNotEqualOperator() const {
	std::cout << "* operator!= <non-member>: ";
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		PRINT_RESULT(!((ftVector1 != ftVector2) && (stlVector1 != stlVector2)));
	}
	{
		ft::vector<int> ftVector1(10, 10);
		ft::vector<int> ftVector2(10, 10);

		std::vector<int> stlVector1(10, 10);
		std::vector<int> stlVector2(10, 10);

		PRINT_RESULT(!((ftVector1 != ftVector2) && (stlVector1 != stlVector2)));
	}
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		PRINT_RESULT(!((ftVector1 != ftVector2) && (stlVector1 != stlVector2)));
	}
	{
		ft::vector<int> ftVector1;
		ft::vector<int> ftVector2;

		std::vector<int> stlVector1;
		std::vector<int> stlVector2;

		createRandomVectors(ftVector1, ftVector2, 100);
		createRandomVectors(stlVector1, stlVector2, 100);

		PRINT_RESULT(!((ftVector1 != ftVector2) && (stlVector1 != stlVector2)));
	}
	{
		ft::vector<std::string> ftVector1;
		ft::vector<std::string> ftVector2;

		std::vector<std::string> stlVector1;
		std::vector<std::string> stlVector2;

		PRINT_RESULT(!((ftVector1 != ftVector2) && (stlVector1 != stlVector2)));
	}
	{
		ft::vector<std::string> ftVector1(10, "vector");
		ft::vector<std::string> ftVector2(10, "vector");

		std::vector<std::string> stlVector1(10, "vector");
		std::vector<std::string> stlVector2(10, "vector");

		PRINT_RESULT(!((ftVector1 != ftVector2) && (stlVector1 != stlVector2)));
	}
	std::cout << std::endl;
}