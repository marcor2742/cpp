#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];
	AMateria *unequiped[MAXTRASH];
	int nMaterials;
	int nUnequiped;
public:
	Character();
	Character(std::string str);
	Character(Character const &copychar);
	Character &operator=(Character const &copychar);
	
	~Character();
    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif