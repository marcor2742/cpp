/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:41:43 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 15:41:44 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverer.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "too few arguments" << std::endl;
		return 1;
	}

	std::string literal = argv[1];
	ScalarConverter::convert(literal);
}