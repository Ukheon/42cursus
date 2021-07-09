#include "Character.hpp"

Character::Character()
{
	this->ap = 40;
	this->name = "unknown";
	this->w_ptr = NULL;
}
Character::Character(std::string const & name)
{
	this->ap = 40;
	this->name = name;
}

Character::~Character()
{
	;
}

void Character::recoverAP()
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon *type)
{
	this->w_ptr = type;
}

void Character::attack(Enemy *type)
{
	if (this->ap - this->w_ptr->getAPCost() < 0)
	{
		std::cout << "not enough energy" << std::endl;
		return ;
	}
	this->ap -= this->w_ptr->getAPCost();
	type->takeDamage(this->w_ptr->getDamage());
	if (type->getHP() <= 0)
	{
		delete type;
		type = NULL;
		return ;
	}
	std::cout << this->name + " attacks " + type->getType() << " with a " + this->check_type()->getName() << std::endl;
	this->w_ptr->attack();
}

int Character::getap() const
{
	return (this->ap);
}

std::string const &Character::getName() const
{
	return (this->name);
}

AWeapon		*Character::check_type() const
{
	if (this->w_ptr == NULL)
		return (NULL);
	return (this->w_ptr);
}

std::ostream 		&operator << (std::ostream &out, const Character &type)
{
	if (type.check_type())
		out << type.getName() + " has " << type.getap() << " AP and wields a " << type.check_type()->getName() << std::endl;
	else
		out << type.getName() + " has " << type.getap() << " AP and is unarmed" << std::endl;
	return (out);
}