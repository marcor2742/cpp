#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& obj) : name(str), weapon(obj)
{
    std::cout << "HumanA è Americano" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA è morto in una sparatoria" << std::endl;  //mettere nome
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}