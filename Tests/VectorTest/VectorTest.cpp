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
	testConstBegin();
	testEnd();
	testConstEnd();
	testREnd();
	testConstREnd();
	testRBegin();
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
	testSwapNonMemver();
	testNonMemberEqualOperator();
	testNonMemberNotEqualOperator();
	testNonMemberLess();
	testNonMemberLessOrEqual();
	testNonMemberMore();
	testNonMemberMoreOrMore();
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
		ft::vector<int>::iterator			ftIterator;
		std::vector<int>::iterator			stlIterator;

		ft::vector<int>	myVector(10, 4);
		std::vector<int> stlVector(10, 4);

		ftIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}

	{
		ft::vector<std::string>::iterator	ftIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(10, std::string("string"));
		std::vector<std::string> stlVector(10, std::string("string"));

		ftIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}

	{
		ft::vector<std::string>::iterator	ftIterator;
		std::vector<std::string>::iterator	stlIterator;

		ft::vector<std::string>	myVector(25, std::string("loooooooooooooooong string"));
		std::vector<std::string> stlVector(25, std::string("loooooooooooooooong string"));

		ftIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}

	{
		ft::vector<double>::iterator			ftIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		ftIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<double>::iterator			ftIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		myVector.insert(myVector.begin(), 10);
		stlVector.insert(stlVector.begin(), 10);

		ftIterator = myVector.begin();
		stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}


	std::cout << std::endl;
}

void	VectorTest::testConstBegin() const {
	std::cout << "* begin()<const_iterator>: ";
	{

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		ft::vector<double>::const_iterator			ftIterator = myVector.begin();
		std::vector<double>::const_iterator			stlIterator = stlVector.begin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator), *(stlIterator)));
	}
	{
		ft::vector<int>::const_iterator			ftIterator;
		std::vector<int>::const_iterator		stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ftIterator = ft.begin() + 50;
		stlIterator = stl.begin() + 50;

		PRINT_RESULT(TO_EQUAL(*(ftIterator), *(stlIterator)));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 1000);

		ft::vector<int>::const_iterator		ftIterator = ft.begin();
		std::vector<int>::const_iterator			stlIterator = stl.begin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 1000);

		ft::vector<int>::const_iterator		ftIterator = ft.begin() + 500;
		std::vector<int>::const_iterator			stlIterator = stl.begin() + 500;

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ft::vector<int>::const_iterator		ftIterator = ft.begin() + 5;
		std::vector<int>::const_iterator			stlIterator = stl.begin() + 5;

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	std::cout << std::endl;
}

void	VectorTest::testEnd() const {
	std::cout << "* end(): ";

	{
		ft::vector<int>::iterator			ftIterator;
		std::vector<int>::iterator			stlIterator;

		ft::vector<int>	myVector(100, 4);
		std::vector<int> stlVector(100, 4);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	{
		ft::vector<std::string>::iterator	ftIterator;
		std::vector<std::string>::iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	{
		ft::vector<std::string>::iterator	ftIterator;
		std::vector<std::string>::iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	{
		ft::vector<double>::iterator			ftIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::iterator			ftIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.pop_back();
		stlVector.pop_back();

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::iterator			ftIterator;
		std::vector<double>::iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	std::cout << std::endl;
}

void	VectorTest::testConstEnd() const {
	std::cout << "* end()<const_iterator>: ";

	{
		ft::vector<int>::const_iterator			ftIterator;
		std::vector<int>::const_iterator			stlIterator;

		ft::vector<int>	myVector(100, 4);
		std::vector<int> stlVector(100, 4);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	{
		ft::vector<std::string>::const_iterator	ftIterator;
		std::vector<std::string>::const_iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	{
		ft::vector<std::string>::const_iterator	ftIterator;
		std::vector<std::string>::const_iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	{
		ft::vector<double>::const_iterator			ftIterator;
		std::vector<double>::const_iterator			stlIterator;

		ft::vector<double>	myVector;
		std::vector<double> stlVector;

		createRandomVectors(myVector, stlVector, 100);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::const_iterator			ftIterator;
		std::vector<double>::const_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		createRandomVectors(myVector, stlVector, 100);

		myVector.pop_back();
		stlVector.pop_back();

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::const_iterator			ftIterator;
		std::vector<double>::const_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		createRandomVectors(myVector, stlVector, 100);

		ftIterator = myVector.end();
		stlIterator = stlVector.end();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}

	std::cout << std::endl;
}

void	VectorTest::testREnd() const {
	std::cout << "* rend(): ";
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int>	myVector(100, 4);
		std::vector<int> stlVector(100, 4);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int>	myVector(1);
		std::vector<int> stlVector(1);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int>	myVector;
		std::vector<int> stlVector;

		for (int i = 0; i < 10; i++) {
			myVector.push_back(i);
			stlVector.push_back(i);
		}

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<std::string>::reverse_iterator	ftIterator;
		std::vector<std::string>::reverse_iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<std::string>::reverse_iterator	ftIterator;
		std::vector<std::string>::reverse_iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::reverse_iterator			ftIterator;
		std::vector<double>::reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::reverse_iterator			ftIterator;
		std::vector<double>::reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.pop_back();
		stlVector.pop_back();

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::reverse_iterator			ftIterator;
		std::vector<double>::reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ftIterator = ft.rend();
		stlIterator = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 1000);

		ftIterator = ft.rend();
		stlIterator = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	std::cout << std::endl;
}

void	VectorTest::testConstREnd() const {
	std::cout << "* rend()<const_reverse_iterator>: ";
	{
		ft::vector<int>::const_reverse_iterator			ftIterator;
		std::vector<int>::const_reverse_iterator			stlIterator;

		ft::vector<int>	myVector(100, 4);
		std::vector<int> stlVector(100, 4);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::const_reverse_iterator			ftIterator;
		std::vector<int>::const_reverse_iterator			stlIterator;

		ft::vector<int>	myVector(1);
		std::vector<int> stlVector(1);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::const_reverse_iterator			ftIterator;
		std::vector<int>::const_reverse_iterator			stlIterator;

		ft::vector<int>	myVector;
		std::vector<int> stlVector;

		for (int i = 0; i < 10; i++) {
			myVector.push_back(i);
			stlVector.push_back(i);
		}

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<std::string>::const_reverse_iterator	ftIterator;
		std::vector<std::string>::const_reverse_iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<std::string>::const_reverse_iterator	ftIterator;
		std::vector<std::string>::const_reverse_iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::const_reverse_iterator			ftIterator;
		std::vector<double>::const_reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::const_reverse_iterator			ftIterator;
		std::vector<double>::const_reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.pop_back();
		stlVector.pop_back();

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<double>::const_reverse_iterator			ftIterator;
		std::vector<double>::const_reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		ftIterator = myVector.rend();
		stlIterator = stlVector.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::const_reverse_iterator			ftIterator;
		std::vector<int>::const_reverse_iterator			stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ftIterator = ft.rend();
		stlIterator = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	{
		ft::vector<int>::const_reverse_iterator			ftIterator;
		std::vector<int>::const_reverse_iterator			stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 1000);

		ftIterator = ft.rend();
		stlIterator = stl.rend();

		PRINT_RESULT(TO_EQUAL(*(--ftIterator), *(--stlIterator)));
	}
	std::cout << std::endl;
}

void	VectorTest::testRBegin() const {
	std::cout << "* rbegin(): ";
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int>	myVector(100, 4);
		std::vector<int> stlVector(100, 4);

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int>	myVector(7);
		std::vector<int> stlVector(7);

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*(++ftIterator), *(++stlIterator)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int>	myVector;
		std::vector<int> stlVector;

		for (int i = 0; i < 10; i++) {
			myVector.push_back(i);
			stlVector.push_back(i);
		}

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator++), *(stlIterator++)));
	}
	{
		ft::vector<std::string>::reverse_iterator	ftIterator;
		std::vector<std::string>::reverse_iterator	stlIterator;
		std::string							string = "string";

		ft::vector<std::string>	myVector(2, string);
		std::vector<std::string> stlVector(2, string);

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator + 1), *(stlIterator + 1)));
	}
	{
		ft::vector<std::string>::reverse_iterator	ftIterator;
		std::vector<std::string>::reverse_iterator	stlIterator;
		std::string							string = "loooooooooooooooong string";

		ft::vector<std::string>	myVector(15, string);
		std::vector<std::string> stlVector(15, string);

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator + 5), *(stlIterator + 5)));
	}
	{
		ft::vector<double>::reverse_iterator			ftIterator;
		std::vector<double>::reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator + 7), *(stlIterator + 7)));
	}
	{
		ft::vector<double>::reverse_iterator			ftIterator;
		std::vector<double>::reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.pop_back();
		stlVector.pop_back();

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<double>::reverse_iterator			ftIterator;
		std::vector<double>::reverse_iterator			stlIterator;

		ft::vector<double>	myVector(15, 7.025);
		std::vector<double> stlVector(15, 7.025);
		myVector.push_back(10);
		stlVector.push_back(10);

		ftIterator = myVector.rbegin();
		stlIterator = stlVector.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator + 10), *(stlIterator + 10)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 100);

		ftIterator = ft.rbegin();
		stlIterator = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*(ftIterator + 50), *(stlIterator + 50)));
	}
	{
		ft::vector<int>::reverse_iterator			ftIterator;
		std::vector<int>::reverse_iterator			stlIterator;

		ft::vector<int> ft;
		std::vector<int> stl;

		createRandomVectors(ft, stl, 1000);

		ftIterator = ft.rbegin();
		stlIterator = stl.rbegin();

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
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
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		PRINT_RESULT(TO_EQUAL(ft.empty(), stlVector.empty()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		PRINT_RESULT(TO_EQUAL(ft.empty(), stlVector.empty()));
	}
	{
		ft::vector<std::string> ft;
		std::vector<std::string> stlVector;

		PRINT_RESULT(TO_EQUAL(ft.empty(), stlVector.empty()));
	}
	{
		ft::vector<std::string> ft(100);
		std::vector<std::string> stlVector(100);

		PRINT_RESULT(TO_EQUAL(ft.empty(), stlVector.empty()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		PRINT_RESULT(TO_EQUAL(ft.empty(), stlVector.empty()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		for (int i = 0; i < 25; i++) {
			ft.pop_back();
			stlVector.pop_back();
		}
		PRINT_RESULT(TO_EQUAL(ft.empty(), stlVector.empty()));
	}
	std::cout << std::endl;
}

void	VectorTest::testCapasity() const {
	std::cout << "* capacity(): ";
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;
		std::vector<int> stl1;
		std::vector<int> stl2;

		createRandomVectors(ft1, stl1, 100);
		createRandomVectors(ft2, stl2, 15);

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL(ft1.capacity(), stl1.capacity()) && TO_EQUAL(ft2.capacity(), stl2.capacity()));
	}
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;
		std::vector<int> stl1;
		std::vector<int> stl2;


		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL(ft1.capacity(), stl1.capacity()) && TO_EQUAL(ft2.capacity(), stl2.capacity()));
	}
	{
		ft::vector<int> ft1(10, 15);
		ft::vector<int> ft2(100, 4);
		std::vector<int> stl1(10, 15);
		std::vector<int> stl2(100, 4);

		createRandomVectors(ft1, stl1, 100);
		createRandomVectors(ft2, stl2, 15);

		ft1.swap(ft2);
		stl1.swap(stl2);

		PRINT_RESULT(TO_EQUAL(ft1.capacity(), stl1.capacity()) && TO_EQUAL(ft2.capacity(), stl2.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string> ft;
		std::vector<std::string> stlVector;

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		ft.push_back(10);
		stlVector.push_back(10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string> ft(100);
		std::vector<std::string> stlVector(100);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		for (int i = 0; i < 25; i++) {
			ft.pop_back();
			stlVector.pop_back();
		}
		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	std::cout << std::endl;
}

void	VectorTest::testMaxSize() const {
	std::cout << "* max_size(): ";
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<std::string> ft;
		std::vector<std::string> stlVector;

		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<std::string> ft(100);
		std::vector<std::string> stlVector(100);

		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		for (int i = 0; i < 25; i++) {
			ft.pop_back();
			stlVector.pop_back();
		}
		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	{
		ft::vector<int> ft(10, 4);
		std::vector<int> stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 10000; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}
		PRINT_RESULT(TO_EQUAL(ft.max_size(), stlVector.max_size()));
	}
	std::cout << std::endl;
}

void	VectorTest::testSingleInsert() const {
	std::cout << "* insert()<single elem>: ";
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ft.end();
		std::vector<int>::iterator	stlIterator = stlVector.end();

		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ft.end()++;
		std::vector<int>::iterator	stlIterator = stlVector.end()++;

		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(5, 4);
		std::vector<int>	stlVector(5, 4);

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		
		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);

		int rand = std::rand();
		for (int i = 0; i < 100; i++) {
			ft.push_back(rand);
			stlVector.push_back(rand);
			rand = std::rand();
		}

		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ft.insert(ftIterator, 10);
		stlVector.insert(stlIterator, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);


		for (int i = 0; i < 100; i++) {
			ft.push_back(i);
			stlVector.push_back(i);
		
		}
		ft::vector<int>::iterator	ftIterator = ft.begin() + 2;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 2;
		
		ft.insert(ftIterator, 100);
		stlVector.insert(stlIterator, 100);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);


		for (int i = 0; i < 100; i++) {
			ft.push_back(i);
			stlVector.push_back(i);
		
		}
		ft::vector<int>::iterator	ftIterator = ft.begin() + 2;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 2;
		
		PRINT_RESULT(TO_EQUAL(*ft.insert(ftIterator, 100), *stlVector.insert(stlIterator, 100)));
	}
	{
		ft::vector<int>		ft(100, 15);
		std::vector<int>	stlVector(100, 15);


		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();
		
		PRINT_RESULT(TO_EQUAL(*ft.insert(ftIterator, 100), *stlVector.insert(stlIterator, 100)));
	}
	{
		ft::vector<int>		ft(100, 15);
		std::vector<int>	stlVector(100, 15);


		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());
		
		PRINT_RESULT(TO_EQUAL(*ft.insert(ftIterator, 100), *stlVector.insert(stlIterator, 100)));
	}
	{
		ft::vector<std::string>		ft(100, std::string("vector"));
		std::vector<std::string>	stlVector(100, std::string("vector"));


		ft::vector<std::string>::iterator	ftIterator = ft.begin() + 50;
		std::vector<std::string>::iterator	stlIterator = stlVector.begin() + 50;
		
		PRINT_RESULT(TO_EQUAL(*ft.insert(ftIterator, std::string("insert")), *stlVector.insert(stlIterator, std::string("insert"))));
	}
	std::cout << std::endl;
}

void	VectorTest::testPopBack() const {
	std::cout << "* pop_back(): ";
	{
		ft::vector<int>		ft(10, 10);
		std::vector<int>	stlVector(10, 10);

		ft.pop_back();
		stlVector.pop_back();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(100, 1000);
		std::vector<int>	stlVector(100, 1000);

		for (int i = 0; i < 100; i++) {
			ft.pop_back();
			stlVector.pop_back();
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(100, std::string("string"));
		std::vector<std::string>	stlVector(100, std::string("string"));

		for (int i = 0; i < 50; i++) {
			ft.pop_back();
			stlVector.pop_back();
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(1, std::string("looooooooooooooooooooooooooooong string"));
		std::vector<std::string>	stlVector(1, std::string("looooooooooooooooooooooooooooong string"));

		ft.pop_back();
		stlVector.pop_back();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testPushBack() const {
	std::cout << "* push_back(): ";
	{
		ft::vector<int>		ft(10, 10);
		std::vector<int>	stlVector(10, 10);

		ft.push_back(4);
		stlVector.push_back(4);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(100, 1000);
		std::vector<int>	stlVector(100, 1000);

		for (int i = 0; i < 100; i++) {
			ft.push_back(i);
			stlVector.push_back(i);
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(100, std::string("string"));
		std::vector<std::string>	stlVector(100, std::string("string"));

		for (int i = 0; i < 50; i++) {
			ft.push_back("s");
			stlVector.push_back("s");
		}

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(1, std::string("looooooooooooooooooooooooooooong string"));
		std::vector<std::string>	stlVector(1, std::string("looooooooooooooooooooooooooooong string"));

		ft.push_back("vector");
		stlVector.push_back("vector");

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft;
		std::vector<std::string>	stlVector;

		ft.push_back("vector");
		stlVector.push_back("vector");

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testReserve() const {
	std::cout << "* reserve(): ";
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft.reserve(0);
		stlVector.reserve(0);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft.reserve(0);
		stlVector.reserve(0);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string>		ft;
		std::vector<std::string>	stlVector;

		ft.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string>		ft(10, std::string("vector"));
		std::vector<std::string>	stlVector(10, std::string("vector"));

		ft.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<std::string>		ft(10, std::string("vector"));
		std::vector<std::string>	stlVector(10, std::string("vector"));

		ft.reserve(100);
		stlVector.reserve(100);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testFillInsert() const {
	std::cout << "* insert()<fill>: ";
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, 4, 14);
		stlVector.insert(stlIterator, 4, 14);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ft.end();
		std::vector<int>::iterator	stlIterator = stlVector.end();

		ft.insert(ftIterator, 10, 5);
		stlVector.insert(stlIterator, 10, 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;

		ft::vector<int>::iterator	ftIterator = ft.end()++;
		std::vector<int>::iterator	stlIterator = stlVector.end()++;

		ft.insert(ftIterator, 10, 5);
		stlVector.insert(stlIterator, 10, 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ft.insert(ftIterator, 2, 17);
		stlVector.insert(stlIterator, 2, 17);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(5, 4);
		std::vector<int>	stlVector(5, 4);

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, 10, 50);
		stlVector.insert(stlIterator, 10, 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);

		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		
		ft.insert(ftIterator, 0, 10);
		stlVector.insert(stlIterator, 0, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);

		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = --(ft.end());
		std::vector<int>::iterator	stlIterator = --(stlVector.end());

		ft.insert(ftIterator, 10, 1);
		stlVector.insert(stlIterator, 10, 1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(10, 4);
		std::vector<int>	stlVector(10, 4);


		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.begin() + 2;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 2;
		
		ft.insert(ftIterator, 100, 10);
		stlVector.insert(stlIterator, 100, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(55, 4);
		std::vector<int>	stlVector(55, 4);

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, 55, 1);
		stlVector.insert(stlIterator, 55, 1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(55, 4);
		std::vector<int>	stlVector(55, 4);

		ft::vector<int>::iterator	ftIterator = ft.begin() + 10;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 10;

		ft.insert(ftIterator, 1, 55);
		stlVector.insert(stlIterator, 1, 55);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(55, 4);
		std::vector<int>	stlVector(55, 4);

		ft::vector<int>::iterator	ftIterator = ft.begin() + 10;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 10;

		ft.insert(ftIterator, 100, 55);
		stlVector.insert(stlIterator, 100, 55);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeInsert() const {
	std::cout << "* insert()<range>: ";
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, arr, arr + 5);
		stlVector.insert(stlIterator, arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(20, 3);
		std::vector<int>	stlVector(20, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ft.begin() + 5;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 5;

		ft.insert(ftIterator, arr, arr);
		stlVector.insert(stlIterator, arr, arr);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(20, 3);
		std::vector<int>	stlVector(20, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ft.begin() + 5;
		std::vector<int>::iterator	stlIterator = stlVector.begin() + 5;

		ft.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(20, 3);
		std::vector<int>	stlVector(20, 3);
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ft.end() - 5;
		std::vector<int>::iterator	stlIterator = stlVector.end() - 5;

		ft.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		int arr[] = {1, 2, 3, 4, 5, 10};

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		int arr[] = {1, 2, 3, 4, 5, 10};

		createRandomVectors(ft, stlVector, 10);

		ft::vector<int>::iterator	ftIterator = ft.begin();
		std::vector<int>::iterator	stlIterator = stlVector.begin();

		stlVector.insert(stlIterator, arr, arr + 6);
		ft.insert(ftIterator, arr, arr + 6);
		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(20, "vector");
		std::vector<std::string>	stlVector(20, "vector");
		std::string arr[] = {"vector1", "vector2", "vector3", "vector4", "vector5", "vector6"};

		ft::vector<std::string>::iterator	ftIterator = ft.end() - 5;
		std::vector<std::string>::iterator	stlIterator = stlVector.end() - 5;

		ft.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft;
		std::vector<std::string>	stlVector;
		std::string arr[] = {"vector1", "vector2", "vector3", "vector4", "vector5", "vector6"};

		ft::vector<std::string>::iterator	ftIterator = ft.end()--;
		std::vector<std::string>::iterator	stlIterator = stlVector.end()--;

		ft.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft;
		std::vector<std::string>	stlVector;
		std::string arr[] = {"vector1", "vector2", "vector3", "vector4", "vector5", "vector6"};

		ft::vector<std::string>::iterator	ftIterator = ft.begin();
		std::vector<std::string>::iterator	stlIterator = stlVector.begin();

		ft.insert(ftIterator, arr, arr + 6);
		stlVector.insert(stlIterator, arr, arr + 6);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testClear() const {
	std::cout << "* clear(): ";
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(200, 3);
		std::vector<int>	stlVector(200, 3);
		
		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 1000);

		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(200, "vector");
		std::vector<std::string>	stlVector(200, "vector");
		
		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft;
		std::vector<std::string>	stlVector;
		
		ft.clear();
		stlVector.clear();

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	std::cout << std::endl;
}

void	VectorTest::testSingleErase() const {
	std::cout << "* erase()<single>: ";
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ft.erase(ft.begin());
		stlVector.erase(stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ft.erase(--ft.end());
		stlVector.erase(--stlVector.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin());
		stlVector.erase(stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin() + 50);
		stlVector.erase(stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin() + 50);
		stlVector.erase(stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin() + 50);
		stlVector.erase(stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.end() - 50);
		stlVector.erase(stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ft.erase(ft.begin());
		stlVector.erase(stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ft.erase(ft.begin() + 5);
		stlVector.erase(stlVector.begin() + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ft.erase(ft.begin() + 9);
		stlVector.erase(stlVector.begin() + 9);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin()), *stlVector.erase(stlVector.begin())));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin()), *stlVector.erase(stlVector.begin())));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin() + 50), *stlVector.erase(stlVector.begin() + 50)));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);


		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin() + 50), *stlVector.erase(stlVector.begin() + 50)));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin() + 50), *stlVector.erase(stlVector.begin() + 50)));
	}
	{
		ft::vector<int>		ft(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ft, stlVector, 100);

		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.end() - 50), *stlVector.erase(stlVector.end() - 50)));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin()), *stlVector.erase(stlVector.begin())));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin() + 5), *stlVector.erase(stlVector.begin() + 5)));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		PRINT_RESULT(TO_EQUAL(*ft.erase(ft.begin() + 9), *stlVector.erase(stlVector.begin() + 9)));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeErase() const {
	std::cout << "* erase()<range>: ";
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		ft.erase(ft.begin(), ft.begin() + 1);
		stlVector.erase(stlVector.begin(), stlVector.begin() + 1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 2);

		ft.erase(ft.begin(), ft.end());
		stlVector.erase(stlVector.begin(), stlVector.end());

		ft::vector<int>::iterator ftItr = ft.begin();
		std::vector<int>::iterator stlItr = stlVector.begin();


		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin() + 50, ft.begin() + 80);
		stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin() + 50, ft.begin() + 80);
		stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin() + 50, ft.begin() + 80);
		stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.begin(), ft.end());
		stlVector.erase(stlVector.begin(), stlVector.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ft, stlVector, 100);

		ft.erase(ft.end() - 80, ft.end() - 50);
		stlVector.erase(stlVector.end() - 80, stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ft.erase(ft.begin(), ft.begin());
		stlVector.erase(stlVector.begin(), stlVector.begin());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ft.erase(ft.begin() + 5, ft.begin() + 8);
		stlVector.erase(stlVector.begin() + 5, stlVector.begin() + 8);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");
		
		ft.erase(ft.begin(), ft.begin() + 9);
		stlVector.erase(stlVector.begin(), stlVector.begin() + 9);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin(), ft.begin() + 1);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 1);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin(), ft.begin() + 50);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 50);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft(2, 3);
		std::vector<int>	stlVector(2, 3);
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin() + 50, ft.begin() + 80);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin() + 50, ft.begin() + 80);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 50, stlVector.begin() + 80);


		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft(100, 150);
		std::vector<int>	stlVector(100, 150);
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin() + 50, ft.end());
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 50, stlVector.end());

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 5);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin() + 2, ft.begin() + 4);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin() + 2, stlVector.begin() + 4);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft(100, 20);
		std::vector<int>	stlVector(100, 20);
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.end() - 80, ft.end() - 50);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.end() - 80, stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.end() - 80, ft.end() - 50);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.end() - 80, stlVector.end() - 50);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<int>		ft;
		std::vector<int>	stlVector;
		
		createRandomVectors(ft, stlVector, 100);

		ft::vector<int>::iterator	ftIterator = ft.erase(ft.begin(), ft.end() - 1);
		std::vector<int>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.end() - 1);

		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");

		ft::vector<std::string>::iterator	ftIterator = ft.erase(ft.begin(), ft.begin() + 5);
		std::vector<std::string>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 5);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");

		ft::vector<std::string>::iterator	ftIterator = ft.erase(ft.begin(), ft.begin());
		std::vector<std::string>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 5);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	{
		ft::vector<std::string>		ft(10, "vector");
		std::vector<std::string>	stlVector(10, "vector");

		ft::vector<std::string>::iterator	ftIterator = ft.erase(ft.begin(), ft.begin() + 9);
		std::vector<std::string>::iterator	stlIterator = stlVector.erase(stlVector.begin(), stlVector.begin() + 9);
		
		PRINT_RESULT(TO_EQUAL(*ftIterator, *stlIterator));
	}
	std::cout << std::endl;
}

void	VectorTest::testSwap() const {
	std::cout << "* swap(): ";
	{
		ft::vector<int>	ft1(10, 10);
		ft::vector<int>	ft2(5, 20);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(5, 20);

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1(10, 10);
		ft::vector<int>	ft2(1, 2);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 2);

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1;
		ft::vector<int>	ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		createRandomVectors(ft1, stl1, 100);
		createRandomVectors(ft2, stl2, 15);

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1;
		ft::vector<int>	ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		createRandomVectors(ft1, stl1, 100);
		createRandomVectors(ft2, stl2, 15);

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1;
		ft::vector<int>	ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<std::string>	ft1;
		ft::vector<std::string>	ft2;

		std::vector<std::string>	stl1;
		std::vector<std::string>	stl2;

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<std::string>	ft1(10, "vector");
		ft::vector<std::string>	ft2(2, "swap");

		std::vector<std::string>	stl1(10, "vector");
		std::vector<std::string>	stl2(2, "swap");

		stl1.swap(stl2);
		ft1.swap(ft2);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	std::cout << std::endl;
}

void	VectorTest::testGetAllocator() const {
	std::cout << "* get_allocator(): ";
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		PRINT_RESULT(ft1.get_allocator() == ft2.get_allocator());
	}
	std::cout << std::endl;
}

void	VectorTest::testFillAssign() const {
	std::cout << "* assign()<fill>: ";
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		createRandomVectors(ft, stlVector, 100);
		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 10);
		std::vector<int> stlVector(10, 10);

		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 10);
		std::vector<int> stlVector(10, 10);

		ft.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 10);
		std::vector<int> stlVector(10, 10);

		ft.assign(1000, 10);
		stlVector.assign(1000, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 10);
		std::vector<int> stlVector(10, 10);

		createRandomVectors(ft, stlVector, 100);
		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10);
		std::vector<int> stlVector(10);

		createRandomVectors(ft, stlVector, 100);
		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10);
		std::vector<int> stlVector(10);

		createRandomVectors(ft, stlVector, 100);
		ft.assign(10, 10);
		stlVector.assign(10, 10);

		removeElemsFromVector(ft, 5);
		removeElemsFromVector(stlVector, 5);
		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10);
		std::vector<int> stlVector(10);

		ft.assign(10, 10);
		stlVector.assign(10, 10);

		removeElemsFromVector(ft, 10);
		removeElemsFromVector(stlVector, 10);
		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(100);
		std::vector<int> stlVector(100);

		ft.assign(5, 10);
		stlVector.assign(5, 10);

		removeElemsFromVector(ft, 5);
		removeElemsFromVector(stlVector, 5);
		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;


		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;


		ft.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft(100, 100);
		std::vector<int> stlVector(100, 100);


		ft.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		createRandomVectors(ft, stlVector, 100);

		ft.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		createRandomVectors(ft, stlVector, 100);

		ft.assign(10, 10);
		stlVector.assign(10, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		createRandomVectors(ft, stlVector, 100);

		ft.assign(110, 10);
		stlVector.assign(110, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		createRandomVectors(ft, stlVector, 0);

		ft.assign(110, 10);
		stlVector.assign(110, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;

		createRandomVectors(ft, stlVector, 0);

		ft.assign(0, 10);
		stlVector.assign(0, 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	std::cout << std::endl;
}

void	VectorTest::testRangeAssign() const {
	std::cout << "* assign()<range>: ";
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10);
		std::vector<int> stlVector(10);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 20);
		std::vector<int> stlVector(10, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 20);
		std::vector<int> stlVector(10, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 10);
		stlVector.assign(arr, arr + 10);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft(10, 20);
		ft::vector<int> ftSupport;
		std::vector<int> stlVector(10, 20);
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}
	{
		ft::vector<int> ft;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft.assign(ftSupport.begin(), ftSupport.end());
		stlVector.assign(stlSupport.begin(), stlSupport.end());

		PRINT_RESULT(TO_EQUAL_VECTOR(ft, stlVector));
	}

	{
		ft::vector<int> ft;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft.assign(ftSupport.begin(), ftSupport.end());
		stlVector.assign(stlSupport.begin(), stlSupport.end());

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		ft::vector<int> ftSupport;
		std::vector<int> stlVector;
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft(500, 10);
		ft::vector<int> ftSupport;
		std::vector<int> stlVector(500, 10);
		std::vector<int> stlSupport;

		createRandomVectors(ftSupport, stlSupport, 100);

		ft.assign(ftSupport.begin(), ftSupport.begin() + 20);
		stlVector.assign(stlSupport.begin(), stlSupport.begin() + 20);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft;
		std::vector<int> stlVector;
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft(2, 20);
		std::vector<int> stlVector(2, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 5);
		stlVector.assign(arr, arr + 5);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
	}
	{
		ft::vector<int> ft(100, 20);
		std::vector<int> stlVector(100, 20);
		int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		ft.assign(arr, arr + 10);
		stlVector.assign(arr, arr + 10);

		PRINT_RESULT(TO_EQUAL(ft.capacity(), stlVector.capacity()));
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

void	VectorTest::testSwapNonMemver() const {
	std::cout << "* swap() <non-member>: ";
	{
		ft::vector<int>	ft1(10, 10);
		ft::vector<int>	ft2(5, 20);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(5, 20);

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1(10, 10);
		ft::vector<int>	ft2(1, 2);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 2);

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1;
		ft::vector<int>	ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		createRandomVectors(ft1, stl1, 100);
		createRandomVectors(ft2, stl2, 15);

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1;
		ft::vector<int>	ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		createRandomVectors(ft1, stl1, 100);
		createRandomVectors(ft2, stl2, 15);

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<int>	ft1;
		ft::vector<int>	ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<std::string>	ft1;
		ft::vector<std::string>	ft2;

		std::vector<std::string>	stl1;
		std::vector<std::string>	stl2;

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	{
		ft::vector<std::string>	ft1(10, "vector");
		ft::vector<std::string>	ft2(2, "word");

		std::vector<std::string>	stl1(10, "vector");
		std::vector<std::string>	stl2(2, "word");

		std::swap(stl2, stl1);
		ft::swap(ft2, ft1);

		PRINT_RESULT(TO_EQUAL_VECTOR(ft1, stl1) && TO_EQUAL_VECTOR(ft2, stl2));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberEqualOperator() const {
	std::cout << "* operator== <non-member>: ";
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		std::vector<int> stl1;
		std::vector<int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<int> ft1(10, 10);
		ft::vector<int> ft2(10, 10);

		std::vector<int> stl1(10, 10);
		std::vector<int> stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 100);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		std::vector<int> stl1;
		std::vector<int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		std::vector<int> stl1;
		std::vector<int> stl2;

		createRandomVectors(ft1, ft2, 100);
		createRandomVectors(stl1, stl2, 100);

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<std::string> ft1;
		ft::vector<std::string> ft2;

		std::vector<std::string> stl1;
		std::vector<std::string> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	{
		ft::vector<std::string> ft1(10, "vector");
		ft::vector<std::string> ft2(10, "vector");

		std::vector<std::string> stl1(10, "vector");
		std::vector<std::string> stl2(10, "vector");

		PRINT_RESULT(TO_EQUAL((ft1 == ft2), (stl1 == stl2)));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberNotEqualOperator() const {
	std::cout << "* operator!= <non-member>: ";
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		std::vector<int> stl1;
		std::vector<int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<int> ft1(10, 10);
		ft::vector<int> ft2(10, 10);

		std::vector<int> stl1(10, 10);
		std::vector<int> stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 100);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		std::vector<int> stl1;
		std::vector<int> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<int> ft1;
		ft::vector<int> ft2;

		std::vector<int> stl1;
		std::vector<int> stl2;

		createRandomVectors(ft1, ft2, 100);
		createRandomVectors(stl1, stl2, 100);

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<std::string> ft1;
		ft::vector<std::string> ft2;

		std::vector<std::string> stl1;
		std::vector<std::string> stl2;

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	{
		ft::vector<std::string> ft1(10, "vector");
		ft::vector<std::string> ft2(10, "vector");

		std::vector<std::string> stl1(10, "vector");
		std::vector<std::string> stl2(10, "vector");

		PRINT_RESULT(TO_EQUAL((ft1 != ft2), (stl1 != stl2)));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberLess() const {
	std::cout << "* operator< <non-member>: ";
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 100);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1(1, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(1, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1;
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		for (int i = 0; i < 10; i++) {
			ft1.push_back(i);
			ft2.push_back(i);
			stl1.push_back(i);
			stl2.push_back(i);
		}

		PRINT_RESULT(TO_EQUAL((ft1 < ft2), (stl1 < stl2)));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberLessOrEqual() const {
	std::cout << "* operator<= <non-member>: ";
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 100);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1(1, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(1, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1;
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		for (int i = 0; i < 10; i++) {
			ft1.push_back(i);
			ft2.push_back(i);
			stl1.push_back(i);
			stl2.push_back(i);
		}

		PRINT_RESULT(TO_EQUAL((ft1 <= ft2), (stl1 <= stl2)));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberMore() const {
	std::cout << "* operator> <non-member>: ";
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 100);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1(1, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(1, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1;
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		for (int i = 0; i < 10; i++) {
			ft1.push_back(i);
			ft2.push_back(i);
			stl1.push_back(i);
			stl2.push_back(i);
		}

		PRINT_RESULT(TO_EQUAL((ft1 > ft2), (stl1 > stl2)));
	}
	std::cout << std::endl;
}

void	VectorTest::testNonMemberMoreOrMore() const {
	std::cout << "* operator>= <non-member>: ";
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 10);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 100);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 100);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 10);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 10);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1(10, 10);
		ft::vector<int>		ft2(1, 100);

		std::vector<int>	stl1(10, 10);
		std::vector<int>	stl2(1, 100);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1(1, 10);
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1(1, 10);
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2(10, 100);

		std::vector<int>	stl1;
		std::vector<int>	stl2(10, 100);

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	{
		ft::vector<int>		ft1;
		ft::vector<int>		ft2;

		std::vector<int>	stl1;
		std::vector<int>	stl2;

		for (int i = 0; i < 10; i++) {
			ft1.push_back(i);
			ft2.push_back(i);
			stl1.push_back(i);
			stl2.push_back(i);
		}

		PRINT_RESULT(TO_EQUAL((ft1 >= ft2), (stl1 >= stl2)));
	}
	std::cout << std::endl;
}

