#include "MateriaSource.hpp"
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->sources[i] = NULL;
	this->idx = 0;
}

MateriaSource::MateriaSource(MateriaSource const &type)
{
	this->idx = 0;
	for (int i = 0; i < type.idx; i++)
	{
		this->learnMateria(type.sources[i]->clone());
	}
}

MateriaSource::~MateriaSource()
{
	if (this->sources)
	{
		for (int i = 0; i < this->idx ; i++)
			delete this->sources[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &type)
{
	this->idx = 0;
	for (int i = 0; i < this->idx; i++)
		delete this->sources[i];
	for (int i = 0; i < type.idx; i++)
		this->learnMateria(type.sources[i]->clone());
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->idx >= 4)
		return ;
	this->sources[this->idx++] = m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->idx; i++)
	{
		if (type == this->sources[i]->getType())
		{
			return (this->sources[i]->clone());
		}
	}
	return (0);
}
