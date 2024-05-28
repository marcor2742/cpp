#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

//const WrongAnimal* wrong = new WrongAnimal();
const WrongAnimal* k = new WrongCat();
//const Animal* l = new WrongCat();
std::cout << k->getType() << " " << std::endl;
k->makeSound();

delete meta;
delete j;
delete i;
//delete wrong;
delete k;

return 0;
}