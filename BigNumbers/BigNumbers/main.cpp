#include"BigInteger.h"

/*
* C++11 came with a new, very powerful feature - move semantics
* Here, I implemented some simple operations on big numbers, respecting RAII idiom and the rule of 5
*/

int main()
{
	biginteger::BigInteger a, b, c;
	std::cin >> a;
	std::cin >> b;
	c = a + b;
	std::cout << c;

	return 0;
}