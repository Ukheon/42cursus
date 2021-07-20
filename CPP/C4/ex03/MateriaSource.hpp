#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	int idx;
	AMateria *sources[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const &type);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &type);

	void learnMateria(AMateria *m);
	AMateria* createMateria(std::string const &type);
};

#endif
