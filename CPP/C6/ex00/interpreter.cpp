#include "interpreter.hpp"

interpreter::interpreter()
{
	;
}

interpreter::~interpreter()
{

}
interpreter::interpreter(interpreter const &copy)
:intV(copy.intV), floatV(copy.floatV), doubleV(copy.doubleV), _case(copy._case), str(copy.str)
{
	for (int i = 0; i < 4; i++)
		this->typeName[i] = copy.typeName[i];
}

interpreter &interpreter::operator=(interpreter const &copy)
{
	this->intV = copy.intV;
	this->doubleV = copy.doubleV;
	this->floatV = copy.floatV;
	this->charV = copy.charV;
	this->_case = copy._case;
	this->str = copy.str;
	for (int i = 0; i < 4; i++)
		this->typeName[i] = copy.typeName[i];
	return (*this);
}

int		interpreter::ValidParamCheck()
{
	int check = 0;
	for (int i = 0; i < this->str.length(); i++)
	{
		if (!(this->str[i] >= '0' && this->str[i] <= '9'))
		{
			if (check == 0 && this->str[i] == '.' && i + 1 != this->str.length())
			{
				check++;
				continue ;
			}
			if (i == 0 && str[i] == '-' || (i + 1 == this->str.length() && str[i] == 'f'))
				continue ;
			return (1);
		}
	}
	return (0);
}

void	interpreter::print()
{
	if (this->_case == -1)
	{
		std::cout << this->typeName[0] << "impossible" << std::endl;
		std::cout << this->typeName[1] << "impossible" << std::endl;
		std::cout << this->typeName[2] << "nanf" << std::endl;
		std::cout << this->typeName[3] << "nan" << std::endl;
	}
	else if (this->_case == 0)
		std::cout << "Error: Wrong input" << std::endl;
	else if (this->_case == 2)
	{
		for (int i = 0; i < 4; i++)
			std::cout << this->typeName[i] << "impossible" << std::endl;
	}
	else
	{
		std::stringstream temp;
		temp << this->floatV;
		this->str = temp.str();
		if (this->str.find("nan", 0) != -1)
		{
			this->_case = -1;
			this->print();
			return ;
		}
		if (this->doubleV >= 32 && this->doubleV <= 126)
			std::cout << this->typeName[0] << "'" << this->charV << "'" << std::endl;
		else
			std::cout << this->typeName[0] << "Non displayable" << std::endl;
		if (this->doubleV > INT_MAX || this->doubleV < INT_MIN)
			std::cout << this->typeName[1] << "impossible" << std::endl;
		else
			std::cout << this->typeName[1] << this->intV << std::endl;

		if (this->str.find("inf", 0) != -1 || this->str.find("nan", 0) != -1)
		{
			std::cout << this->typeName[2] << this->floatV << "f" << std::endl;
		}
		else if (this->str.find(".", 0) == -1)
			std::cout << this->typeName[2] << this->floatV << ".0f" << std::endl;
		else
			std::cout << this->typeName[2] << this->floatV << "f" << std::endl;

		temp.str().clear();
		temp << this->doubleV;
		this->str = temp.str();
		if (this->str.find("inf", 0) != -1 || this->str.find("nan", 0) != -1)
			std::cout << this->typeName[3] << this->doubleV << std::endl;
		else if (this->str.find(".", 0) == -1)
			std::cout << this->typeName[3] << this->doubleV << ".0" << std::endl;
		else
			std::cout << this->typeName[3] << this->doubleV << "" << std::endl;
	}
}

interpreter::interpreter(char *str)
{
	this->typeName[0] = "char: ";
	this->typeName[1] = "int: ";
	this->typeName[2] = "float: ";
	this->typeName[3] = "double: ";
	if (str == NULL)
	{
		for (int i = 0; i < 4; i++)
			std::cout << this->typeName[i] << "impossible";
		this->_case = 0;
		return ;
	}
	std::string temp(str);
	this->str = temp;
	this->_case = -1;
	if (this->str == "nan" || this->str == "nanf")
		return ;
	if (str == NULL)
	{
		for (int i = 0; i < 4; i++)
			std::cout << this->typeName[i] << "impossible";
		this->_case = 0;
		return ;
	}
	else if (this->ValidParamCheck())
	{
		this->_case = 2;
		return ;
	}
	this->_case = 4;
	this->doubleV = atof(str);
	this->intV = static_cast<int>(this->doubleV);
	this->floatV = static_cast<float>(this->doubleV);
	this->charV = static_cast<char>(this->doubleV);
}
