#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class 				Fixed
{
private:
	int					value;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed &fix);
	~Fixed();
	Fixed &operator = (const Fixed &fix);
	int		getRawBits() const;
};

#endif