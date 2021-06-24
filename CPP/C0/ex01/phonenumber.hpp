#ifndef PHONENUMBER_HPP
# define PHONENUMBER_HPP
# include <iostream>
# include <cstring>
# include <iomanip>

class info {  
private:
	std::string first_name;
	std::string last_name;
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
	std::string get_firstname();
	std::string get_lastname();
	std::string get_nickname();
	void    insert_firstname(std::string input);
	void	insert_lastname(std::string input);
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

#endif