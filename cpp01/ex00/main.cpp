#include "Zombie.hpp"

int main() {
    randomChump("gino");
    Zombie *allocatedZombie = newZombie("ciro");

    (*allocatedZombie).announce();
    delete (allocatedZombie);
    return(0);
}