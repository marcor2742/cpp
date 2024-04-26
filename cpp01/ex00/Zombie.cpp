#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
    std::cout << "costruttore chiamato" << std::endl;
}

Zombie::~Zombie()
{

    std::cout << "lo zombie " << this->_name << " e' stato brutalmente ucciso" << std::endl;
}

void Zombie::announce( void ){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}