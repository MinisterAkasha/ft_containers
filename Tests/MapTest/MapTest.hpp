#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include <iostream>
# include <map>
# include "map.hpp"
# include "testUtils.hpp"
#include "utils.hpp"

class MapTest {
	private:
		void	testDefaultConstructor() const;
		void	testRangeConstructor() const;
		void	testCopyConstructor() const;
		void	testMemberOperatorEqual() const;
		void	testBegin() const;
		void	testEnd() const;
		void	testRBegin() const;
		void	testREnd() const;
		void	testSingleInsert() const;
		void	testWithHintInsert() const;
		void	testRangeInsert() const;
		void	testErasePosition() const;
		void	testEraseKey() const;
		void	testEraseRange() const;
		void	testSwap() const;
		void	testClear() const;
		void	testFind() const;
		void	testEmpty() const;
		void	testCount() const;
		void	testLowerBound() const;
		void	testtestAccessOperator() const;

		void	testNonMemberOperatorEqual() const;
		void	testNonMemberOperatorNotEqual() const;
		void	testNonMemberOperatorLess() const;
		void	testNonMemberOperatorLessOrEqual() const;
		void	testNonMemberOperatorMore() const;
		void	testNonMemberOperatorMoreOrEqual() const;
		// void testMapIterator() const;
	
	public:
		MapTest();

		~MapTest();
	
	public:
		void	test() const;
};

#endif