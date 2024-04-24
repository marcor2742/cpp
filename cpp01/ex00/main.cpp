#include "Zombie.hpp"

int main() {
    randomChump("ciao");
    Zombie *cazzo = newZombie("we");

    (*cazzo).announce();
    return(0);
}