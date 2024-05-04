#include "HumanB.hpp"

HumanB::HumanB(std::string str, Weapon *obj) : name(str), weapon(obj)
{
    std::cout << this->name << " è Americano" << std::endl;
}

HumanB::HumanB(std::string str) : name(str)
{
    std::cout << this->name << " non è Americano" << std::endl;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << this->name << " è morto di vecchiaia" << std::endl;
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& obj)
{
    this->weapon = &obj;
}
