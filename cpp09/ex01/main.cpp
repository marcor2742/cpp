/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:22:03 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/21 19:22:04 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.Calculate(argv[1]);
/*
	std::cout << std::endl;

	std::cout << "2.1 ";
	RPN rpn21;
	rpn21.Calculate("8 9 * 9 - 9 - 9 - 4 - 1 +");

	std::cout << "2.2 ";
	RPN rpn22;
	rpn22.Calculate("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -");

	std::cout << "2.3 ";
	RPN rpn23;
	rpn23.Calculate("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /");

	std::cout << "3. ";
	RPN rpn3;
	rpn3.Calculate("7 7 * 7 -");

	std::cout << "4. ";
	RPN rpn4;
	rpn4.Calculate("1 2 * 2 / 2 * 2 4 - +");

	std::cout << "5. ";
	RPN rpn5;
	rpn5.Calculate("(1 + 1)");

	std::cout << "6. ";
	RPN rpn6;
	rpn6.Calculate("2 2 * 0 *");

	std::cout << "7. ";
	RPN rpn7;
	rpn7.Calculate(" 1 1 +");

	std::cout << "8. ";
	RPN rpn8;
	rpn8.Calculate("1 1 + ");

	std::cout << "9. ";
	RPN rpn9;
	rpn9.Calculate("1 + 1");

	std::cout << "10. ";
	RPN rpn10;
	rpn10.Calculate("1 + 1 1 +");

	std::cout << "11. ";
	RPN rpn11;
	rpn11.Calculate("1 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +");

	std::cout << "12. ";
	RPN rpn12;
	rpn12.Calculate("1");

	std::cout << "13. ";
	RPN rpn13;
	rpn13.Calculate("*");

	std::cout << "14. ";
	RPN rpn14;
	rpn14.Calculate("1 1 1 +");

	std::cout << "15. ";
	RPN rpn15;
	rpn15.Calculate("1 + +");

	std::cout << "16. ";
	RPN rpn16;
	rpn16.Calculate("1 0 /");
*/
}