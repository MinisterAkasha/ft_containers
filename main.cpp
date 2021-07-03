#include "Vector.hpp"
#include "vector"

int main()
{
    std::vector<int>	hehe;
	std::vector<int>::iterator d(hehe.begin());
	// std::vector<int>::iterator b(hehe.begin());
	d += 2;
	return 0;
}