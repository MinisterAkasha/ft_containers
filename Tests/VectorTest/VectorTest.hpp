#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include <iostream>
# include <vector>
# include "vector.hpp"
# include "testUtils.hpp"

class VectorTest {
	private:
		ft::vector<int>		myVecorEmpty;
		ft::vector<int>		myVecor;

		std::vector<int>	stdVecorEmpty;
		std::vector<int>	stdVecor;
	
	private:
		void testFillConstructor() const;
		void testBegin() const;
		void testEnd() const;
		void testSize() const;
		void testEqualOperator() const;
		void testEmpty() const;
		void testCapasity() const;
		void testMaxSize() const;
		void testSingleInsert() const;
		void testFillInsert() const;
		void testRangeInsert() const;
		void testPopBack() const;
		void testPushBack() const;
		void testReserve() const;
		void testClear() const;
		void testSingleErase() const;
	
	public:
		VectorTest();

		~VectorTest();
	
	public:
		void	test() const;
	
};

#endif