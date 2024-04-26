#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << this->_name << "uno zombie è ritornato dagli inferi" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " si è dissolto nell'acido" << std::endl;
}

void Zombie::setName(std::string name){
    Zombie::_name = name;
}

// void Zombie::announce( void ){
//     std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
// }
