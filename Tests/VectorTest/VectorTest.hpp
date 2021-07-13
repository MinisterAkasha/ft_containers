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
		void testRangeConstructor() const;
		void testCopyConstructor() const;
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
	
	public:
		VectorTest();

		~VectorTest();
	
	public:
		void	test() const;
	
};

#endif