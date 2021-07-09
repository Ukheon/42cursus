#include "Squad.hpp"

Squad::Squad()
{
	this->count = 0;
	this->units = NULL;
}

Squad::~Squad()
{
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete[] this->units;
	}
}

Squad::Squad(const Squad &type)
{
	this->count = 0;
	this->units = NULL;
	*this = type;
}

Squad &Squad::operator=(const Squad &type)
{
	if (this == &type)
		return (*this);
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete[] this->units;
	}
	this->units = new ISpaceMarine*[type.count + 1];
	for (int i = 0; i < type.count; i++)
	{
		this->units[i] = type.units[i]->clone();
	}
	this->count = type.count;
	return (*this);
}

int Squad::getCount() const
{
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int num) const
{
	if (this->count == 0 || num >= this->count)
		return (NULL);
	return (this->units[num]);
}

int Squad::push(ISpaceMarine *type)
{
	if (type == NULL)
		return (0);
	if (this->units == NULL)
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = type;
		this->count++;
		return (this->count);
	}
	else
	{
		for (int i = 0; i < this->count; i++)
		{
			if (this->units[i] == type)
			{
				return (this->count);
			}
		}
		ISpaceMarine **temp = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; i++)
		{
			temp[i] = this->units[i];
		}
		temp[this->count] = type;
		delete[] this->units;
		this->units = temp;
		this->count++;
		return (this->count);
	}
}
