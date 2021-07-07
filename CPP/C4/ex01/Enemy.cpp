#include "Enemy.hpp"

Enemy::Enemy()
{
	;
}

Enemy::Enemy(const Enemy &type)
{
	*this = type;
}
Enemy::~Enemy()
{
	;
}

std::string const &Enemy::getType() const
{
	return (this->type);
}

int					Enemy::getHP() const
{
	return (this->hp);
}

void Enemy::takeDamage(int damage)
{
	this->hp -= damage;
	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}

Enemy &Enemy::operator=(Enemy const &type)
{
	if (this == &type)
		return (*this);
	this->hp = type.hp;
	this->type = type.type;
	return (*this);
}