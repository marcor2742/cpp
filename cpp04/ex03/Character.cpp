#include "Character.hpp"

Character::Character() : name("default"), nMaterials(0), nUnequiped(0)
{
	for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
	std::cout <<BLUE "Character default constructor called" END<< std::endl;
}

Character::Character(std::string str) : name(str), nMaterials(0), nUnequiped(0)
{
	std::cout << BLUE << name << " character constructor called" END<< std::endl;
}

Character::Character(Character const &copychar)
{
	std::cout <<BLUE "copy constructor with ";
	*this = copychar;
}

Character &Character::operator=(Character const &copychar)
{
	std::cout <<BLUE "Character assignation operator called" END<< std::endl;
	if (this != &copychar)
	{
		name = copychar.name;
		nMaterials = copychar.nMaterials;
		nUnequiped = copychar.nUnequiped;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (copychar.inventory[i])
				inventory[i] = copychar.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << BLUE << name << " destructor called" END<< std::endl;
	for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
	for (int i = 0; unequiped[i] && i < MAXTRASH; i++)
    {
            delete unequiped[i];
    }
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (nMaterials > 3)
		std::cout << name << "'s inventory is full" << std::endl;
	else
	{
		inventory[nMaterials] = m;
		nMaterials++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "wrong index" << std::endl;
	else if (!inventory[nMaterials])
		std::cout << name << "'s inventory at "<< idx << " is empty" << std::endl;
	else
	{
		if (nUnequiped >= MAXTRASH)
			std::cout << name << " ha inquinato troppo e ora non può più buttare le cose per terra" << std::endl;
		else
		{
        	unequiped[nUnequiped] = inventory[idx];
        	nUnequiped++;
			unequiped[nUnequiped] = NULL; 
        	inventory[idx] = NULL;
		}
	}

}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "wrong index" << std::endl;
	else if (!inventory[idx])
		std::cout << name << "'s inventory at "<< idx << " is empty and you can't use use() to use a Materia" << std::endl;
	else
		inventory[idx]->use(target);
}
