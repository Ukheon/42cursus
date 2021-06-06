#include <iostream>
#include <cstring>
class info {  
private:
	std::string first_name;
	std::string second_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
	int			i;

public:
	void    insert_firstname(std::string input);
	void	insert_secondname(std::string input);
	void	insert_nickname(std::string input);
	void	insert_login(std::string input);
	void	insert_postal(std::string input);
	void	insert_email(std::string input);
	void	insert_phonenumber(std::string input);
	void	insert_birthday(std::string input);
	void	insert_favorite_meal(std::string input);
	void	insert_underwear_color(std::string input);
	void	insert_darkest_secret(std::string input);
	void	show_data();
	void	insert_index(int i);
};

void		info::insert_firstname(std::string input)
{
	this->first_name = input;
}
void		info::insert_secondname(std::string input)
{
	this->second_name = input;
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
	std::cout << this->first_name << std::endl;
	std::cout << this->second_name << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->login << std::endl;
	std::cout << this->postal_address << std::endl;
	std::cout << this->email_address << std::endl;
	std::cout << this->phone_number << std::endl;
	std::cout << this->birthday << std::endl;
	std::cout << this->favorite_meal << std::endl;
	std::cout << this->underwear_color << std::endl;
	std::cout << this->darkest_secret << std::endl;
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
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			std::cout << "first name = ";
			std::getline(std::cin, input);
			phonebook[i].insert_firstname(input);
			std::cout << "second name = ";
			std::getline(std::cin, input);
			phonebook[i].insert_secondname(input);
			std::cout << "nick name = ";
			std::getline(std::cin, input);
			phonebook[i].insert_nickname(input);
			std::cout << "login = ";
			std::getline(std::cin, input);
			phonebook[i].insert_login(input);
			std::cout << "postal_address = ";
			std::getline(std::cin, input);
			phonebook[i].insert_postal(input);
			std::cout << "email_address = ";
			std::getline(std::cin, input);
			phonebook[i].insert_email(input);
			std::cout << "phonenumber = ";
			std::getline(std::cin, input);
			phonebook[i].insert_phonenumber(input);
			std::cout << "birthday_date = ";
			std::getline(std::cin, input);
			phonebook[i].insert_birthday(input);
			std::cout << "favorite_meal = ";
			std::getline(std::cin, input);
			phonebook[i].insert_favorite_meal(input);
			std::cout << "underwear_color = ";
			std::getline(std::cin, input);
			phonebook[i].insert_underwear_color(input);
			std::cout << "darkest_secret = ";
			std::getline(std::cin, input);
			phonebook[i].insert_darkest_secret(input);
			std::getline(std::cin, input);
			phonebook[i].insert_index(i);
			i++;
		}
	}
	while (i-- > 0)
	{
		phonebook[i].show_data();
	}
}