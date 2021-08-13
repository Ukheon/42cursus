#include "whatever.hpp"

int main(void)
{
	int test = 10;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	a = 10;
	b = 10;
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	int &p3 = min(a, b);
	std::cout << &p3 << std::endl;
	return (0);
}
