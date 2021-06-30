#include "Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed				&Fixed::operator = (const Fixed &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = fix.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)(roundf((num * (1 << this->bit))));
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num * (1 << this->bit);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream		&operator << (std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}

float				Fixed::toFloat() const
{
	float res;

	res = (float)this->value / (1 << this->bit);
	return (res);
}

int					Fixed::toInt() const
{
	return (this->value / (1 << this->bit));
}

int					main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}