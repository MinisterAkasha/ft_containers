#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include <iostream>
# include <vector>
# include "vector.hpp"

class VectorTest {
	private:
		ft::vector<int>		myVecorEmpty;
		ft::vector<int>		myVecor;

		std::vector<int>	stdVecorEmpty;
		std::vector<int>	stdVecor;
	
	private:
		void testFillConstructor() const;
	
	public:
		VectorTest();

		~VectorTest();
	
	public:
		void	test() const;
	
};

#endif