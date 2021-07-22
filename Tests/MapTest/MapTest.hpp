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
		void	testSingleInsert() const;
		void	testWithHintInsert() const;
		void	testRangeInsert() const;
		// void testMapIterator() const;
	
	public:
		MapTest();

		~MapTest();
	
	public:
		void	test() const;
};

#endif