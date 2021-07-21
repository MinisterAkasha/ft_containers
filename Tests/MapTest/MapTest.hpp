#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include <iostream>
# include <map>
# include "map.hpp"
# include "testUtils.hpp"

class MapTest {
	private:
		void	testDefaultConstructor() const;
		// void testMapIterator() const;
	
	public:
		MapTest();

		~MapTest();
	
	public:
		void	test() const;
};

#endif