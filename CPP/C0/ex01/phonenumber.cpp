
#include "./phonenumber.hpp"

std::string	info::get_firstname(void)
{
	return (this->first_name);
}
std::string	info::get_lastname(void)
{
	return (this->last_name);
}
std::string	info::get_nickname(void)
{
	return (this->nickname);
}

void		info::insert_firstname(std::string input)
{
	this->first_name = input;
}
void		info::insert_lastname(std::string input)
{
	this->last_name = input;
}
void		info::insert_nickname(std::string input)
{
	this->nickname = input;
}
void		info::insert_login(std::string input)
{
	this->login = input;
}
void		info::insert_postal(std::string input)
{
	this->postal_address = input;
}
void		info::insert_email(std::string input)
{
	this->email_address = input;
}
void		info::insert_phonenumber(std::string input)
{
	this->phone_number = input;
}
void		info::insert_birthday(std::string input)
{
	this->birthday = input;
}
void		info::insert_favorite_meal(std::string input)
{
	this->favorite_meal = input;
}
void		info::insert_underwear_color(std::string input)
{
	this->underwear_color = input;
}
void		info::insert_darkest_secret(std::string input)
{
	this->darkest_secret = input;
}
void		info::insert_index(int i)
{
	this->i = i;
}
void		info::show_data()
{
	std::cout << "firstname = " << this->first_name << std::endl;
	std::cout << "lastname = " << this->last_name << std::endl;
	std::cout << "nickname = " << this->nickname << std::endl;
	std::cout << "login = " << this->login << std::endl;
	std::cout << "postal address = " << this->postal_address << std::endl;
	std::cout << "email address = " << this->email_address << std::endl;
	std::cout << "phone number = " << this->phone_number << std::endl;
	std::cout << "birthday date = " << this->birthday << std::endl;
	std::cout << "favorite meal = " << this->favorite_meal << std::endl;
	std::cout << "underwear color = " << this->underwear_color << std::endl;
	std::cout << "darkest secret = " << this->darkest_secret << std::endl;
}

void		exec_add(std::string input, int i, info *phonebook)
{
	std::cout << "first name = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_firstname(input);
	std::cout << "last name = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_lastname(input);
	std::cout << "nick name = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_nickname(input);
	std::cout << "login = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_login(input);
	std::cout << "postal_address = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_postal(input);
	std::cout << "email_address = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_email(input);
	std::cout << "phonenumber = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_phonenumber(input);
	std::cout << "birthday_date = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_birthday(input);
	std::cout << "favorite_meal = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_favorite_meal(input);
	std::cout << "underwear_color = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_underwear_color(input);
	std::cout << "darkest_secret = ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	phonebook[i].insert_darkest_secret(input);
}

std::string			check_input(std::string input)
{
	std::string res;
	int front = 0;
	int back;
	int count = 0;
	std::getline(std::cin, input);
	while (input[front] == ' ')
		front++;
	back = input.size();
	while (input[--back] == ' ')
		count++;
	res = input.substr(front, input.size() - front - count);
	return (res);
}

void			show_contact(info *phonebook, int index)
{
	int			i;
	std::string input;
	i = 0;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "firstname";
	std::cout << "|" << std::setw(10) << "lastname";
	std::cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;
	while (i < index)
	{
		std::cout << "|" << std::setw(10) << i;
		if (phonebook[i].get_firstname().size() > 10)
			std::cout << "|" << std::setw(10) << phonebook[i].get_firstname().substr(0, 9)+".";	
		else
			std::cout << "|" << std::setw(10) << phonebook[i].get_firstname();
		if (phonebook[i].get_lastname().size() > 10)
			std::cout << "|" << std::setw(10) << phonebook[i].get_lastname().substr(0, 9)+".";
		else
			std::cout << "|" << std::setw(10) << phonebook[i].get_lastname();
		if (phonebook[i].get_nickname().size() > 10)
			std::cout << "|" << std::setw(10) << phonebook[i].get_nickname().substr(0, 9)+'.' << "|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << phonebook[i].get_nickname() << "|" << std::endl;
		i++;
	}
	std::cout << "Enter index to get full page: ";
	input = check_input(input);
	if (input.size() < 2 && input[0] >= '0' && input [0] < '9')
	{
		if (input[0] - 48 >= index)
			std::cout << "Not exist data" << std::endl;
		else
			phonebook[input[0] - 48].show_data();
	}
	else
	{
		std::cout << "Wrong index" << std::endl;
	}
}

int main(void)
{
	int         i;
	info        phonebook[8];

	std::string input;
	i = 0;
	while (1)
	{
		std::cout << "Enter a command (ADD or SEARCH or EXIT):";
		std::getline(std::cin, input);
		if (input == "EXIT" || std::cin.eof())
			break ;
		else if (input == "ADD")
		{
			if (i > 7)
			{
				std::cout << "The index is overflow" << std::endl;
				continue ;
			}
			exec_add(input, i, phonebook);
			i++;
		}
		else if (input == "SEARCH")
		{
			show_contact(phonebook, i);
		}
		else
			std::cout << input << ": Command not found" << std::endl;
	}
}