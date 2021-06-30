#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class 				Fixed
{
private:
	int					value;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed &fix);
	Fixed			&operator = (const Fixed &fix);
	~Fixed();
	Fixed(float num);
	Fixed(int num);
	int				getRawBits() const;
	void			setRawBits(int const raw);
	int				toInt() const;
	float 			toFloat() const;
};

std::ostream		&operator << (std::ostream &out, const Fixed &fix);

#endif