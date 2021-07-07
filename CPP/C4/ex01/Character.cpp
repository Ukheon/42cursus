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
	if (type->getHP() <= 0 && type != 0)
	{
		delete type;
		type = 0;
		return ;
	}
	std::cout << this->name + " attacks " + type->getType() << " with a Power Fist" << std::endl;
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

// AWeapon Character::getWeapon()
// {
// 	this->w_ptr->getName();
// }

AWeapon		*Character::check_type() const
{
	if (this->w_ptr == NULL)
		return (NULL);
	return (this->w_ptr);
}

std::ostream 		&operator << (std::ostream &out, const Character &type)
{
	// std::cout << this->name + "has " << this->ap << " AP and is unarmed" << std::endl;
	// me has 40 AP and wields a Plasma Rifle
	// std::string temp;
	// out << "hi" << std::endl;
	// temp = type.check_type();
	if (type.check_type())
		out << type.getName() + " has " << type.getap() << " AP and wields a " << type.check_type()->getName() << std::endl;
	else
		out << type.getName() + " has " << type.getap() << " AP and is unarmed" << std::endl;
	return (out);
}