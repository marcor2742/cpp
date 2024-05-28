/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:28:23 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/28 16:28:24 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
//const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;
delete i;
//...

/*Dog pippo;
{
	Dog tmp(pippo);
}
pippo.getBrain();*/

// Cat pietro;
// {
// 	Cat tmp(pietro);
// }
// pietro.getBrain();


// Dog pluto;
// {
// 	Dog tmp;
// 	tmp = pluto;
// }
return 0;
}