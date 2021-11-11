#include "iter.hpp"

//class Awesome
//{
//public:
//Awesome( void ) : _n( 42 ) { return; }
//int get( void ) const { return this->_n; }
//private:
//int _n;
//};
//std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
//template< typename T >
//void print( T const & x ) { std::cout << x << std::endl; return; }
//int main() {
//int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//Awesome tab2[5];

//iter( tab, 5, print );
//iter( tab2, 5, print );

//return 0;
//}

std::ostream &operator<<(std::ostream &out, practice const &type)
{
	for (int i = 0; i < 5; i++)
		std::cout << type.getArr(i) << " ";
	std::cout << std::endl;
	out << "template class . . .";
	return (out);
}

int main()
{
	int iarr[5] = {1, 3, 5, 7, 9};
	iter(iarr, 5, print);

	double darr[5] = {1.0, 2.2, 3.3, 4.4, 5.5};
	iter(darr, 5, print);

	std::string str[5] = {"hi","nice","to","meet","you"};
	iter(str, 5, print);

	practice *test = new practice[3];
	iter(test, 3, print);
	delete[] test;
	return (0);
}
