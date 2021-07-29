#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP
# include <iostream>
# include <stdlib.h>
# include <cstring>
# include <sstream>
# include <climits>
# include <math.h>
class interpreter {
private:
	char	charV;
	int		intV;
	double	doubleV;
	float	floatV;
	int		_case;
	std::string str;
	std::string typeName[4];
public:
	interpreter();
	~interpreter();
	interpreter(char *str);
	interpreter(interpreter const &copy);
	interpreter &operator=(interpreter const &copy);
	int			ValidParamCheck();
	void		print();
};


#endif
