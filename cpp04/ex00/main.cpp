/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:26:58 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/28 16:26:59 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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