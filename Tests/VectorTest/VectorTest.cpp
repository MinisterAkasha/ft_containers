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
	testEqualOperator();
	testEmpty();
	testCapasity();
	testMaxSize();
	testClear();
	testSingleErase();
	testRangeErase();
	testSwap();
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

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ftVector.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}

		ft::vector<int>::iterator	ftIterator = --(ftVector.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ftVector.insert(ftIterator, 10, 1);
		stlVector.insert(stlIterator, 10, 1);

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
	std::cout << "* erase()<range>: ";
	{
		ft::vector<int>	ftVector1(10, 10);
		ft::vector<int>	ftVector2(5, 20);

		std::vector<int>	stlVector1(2, 10);
		std::vector<int>	stlVector2(10, 20);

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
	std::cout << std::endl;
}