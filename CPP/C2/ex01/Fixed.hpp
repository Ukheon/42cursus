#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
#

class 				Fixed
{
private:
	int					value;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(float num);
	Fixed(int num);
	Fixed(const Fixed &fix);
	~Fixed();
	Fixed			&operator = (const Fixed &fix);
	int				toInt() const;
	float 			getValue() const;
};

std::ostream		&operator << (std::ostream &out, const Fixed &fix);

#endif