#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
    std::cout << "costruttore chiamato" << std::endl;
}

Zombie::~Zombie()
{
}

void Zombie::announce( void ){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie( std::string name ) {
    Zombie *ciccio = new Zombie (name);
    return ciccio;
}

void randomChump( std::string name ) {
    Zombie obj(name);
    obj.announce();

}