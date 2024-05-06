/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:35:40 by mruggier          #+#    #+#             */
/*   Updated: 2024/05/06 11:35:42 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(){
    std::string stringA = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringA;
    std::string &stringREF = stringA;

    std::cout << &stringA << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << stringA << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}