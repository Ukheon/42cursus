#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	std::cout << "Assignation operator called " << std::endl;
	this->value = fix.getRawBits();
	return (*this);
}


int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

const int  &Fixed::test()
{
	int *a;
	int temp = 10;
	a = &temp;
	return (*a);
}

int					main(void)
{
	// Fixed a;
	// Fixed b( a );
	Fixed c;

	int test;


	test = c.test();
	std::cout << test << std::endl;
	test = 122;
	std::cout << test << std::endl;


	// c = b;
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;
	return (0);
}