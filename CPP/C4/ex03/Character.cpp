#include "Character.hpp"

Character::Character()
{
	;
}

Character::Character(std::string const name)
{
	this->name = name;
	this->limit = 0;
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
	}
}

Character::Character(const Character &type)
{
	this->name = type.name;
	for (int i = 0; i < type.limit; i++)
	{
		this->slot[i] = type.slot[i]->clone();
	}
}
Character::~Character()
{
	for (int i = 0; i < 4 ; i++)
	{
		if (this->slot[i] != NULL)
			delete this->slot[i];
	}
}
std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (this->limit >= 4 || m == NULL)
		return ;
	int i = 0;
	for (i = 0; i < this->limit; i++)
	{
		if (this->slot[i] == m)
			return ;
	}
	this->slot[this->limit] = m;
	this->limit++;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->limit)
		return ;
	if (this->slot[idx] == NULL)
		return ;
	for (int i = idx; i < 3; i++)
	{
		this->slot[i] = this->slot[i + 1];
		this->slot[i + 1] = NULL;
	}
	this->limit--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->limit || this->slot[idx] == NULL)
	{
		return ;
	}
	this->slot[idx]->use(target);
}

Character &Character::operator=(Character const &type)
{
	this->name = type.name;
	for (int i = 0; i < this->limit; i++)
		delete this->slot[i];
	this->limit = 0;
	for (int i = 0; i < type.limit; i++)
		this->equip(type.slot[i]->clone());
	return (*this);
}
