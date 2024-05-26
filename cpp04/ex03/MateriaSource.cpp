#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : nMaterials(0)
{
	std::cout BLUE<< "MateriaSource default constructor called" <<END std::endl;
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copymateria)
{
	std::cout << "copy constructor with ";
	*this = copymateria;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copymateria)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &copymateria)
	{
		nMaterials = copymateria.nMaterials;
		for (int i = 0; i < 4; i++)
		{
			if (materia[i])
				delete materia[i];
			if (copymateria.materia[i])
				materia[i] = copymateria.materia[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (nMaterials > 3)
		std::cout << "MateriaSource is full" << std::endl;
	else
	{
		materia[nMaterials] = m;
		nMaterials++;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	return 0;
}