#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materia[4];
	int nMaterials;
public:
	MateriaSource();
	MateriaSource(MateriaSource const &copymateria);
	MateriaSource &operator=(MateriaSource const &copymateria);
	~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif