#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string str) : type(str)
{
    std::cout << "l'arma " << this->type << " è stata creata" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "oh no, si è rotta l'arma" << std::endl;
}

const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string str)
{
    this->type = str;
}
