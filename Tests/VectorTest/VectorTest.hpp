#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include <iostream>
# include <vector>
# include "vector.hpp"
# include "testUtils.hpp"

class VectorTest {
	private:
		void testFillConstructor() const;
		void testRangeConstructor() const;
		void testCopyConstructor() const;
		void testBegin() const;
		void testConstBegin() const;
		void testEnd() const;
		void testConstEnd() const;
		void testREnd() const;
		void testConstREnd() const;
		void testRBegin() const;
		void testConstRBegin() const;
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
		void testRangeErase() const;
		void testSwap() const;
		void testNonMemberEqualOperator() const;
		void testGetAllocator() const;
		void testFillAssign() const;
		void testRangeAssign() const;
		void testResize() const;
		void testAccessOperator() const;
		void testAt() const;
		void testFront() const;
		void testBack() const;
		void testNonMemberNotEqualOperator() const;
		void testNonMemberLess() const;
		void testNonMemberLessOrEqual() const;
		void testNonMemberMore() const;
		void testNonMemberMoreOrMore() const;
		void testSwapNonMemver() const;
		void testNonMemberOperatorMinus() const;
		void testNonMemberOperatorPlus() const;

		void testVectorIterator() const;
	
	public:
		VectorTest();

		~VectorTest();
	
	public:
		void	test() const;
	
};

#endif