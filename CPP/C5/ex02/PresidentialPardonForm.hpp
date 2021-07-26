#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm();
	const std::string target;
public:
	static const std::string name;
	PresidentialPardonForm(PresidentialPardonForm const &type);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &type);
	void execute(Bureaucrat const &type) const;
};

#endif
