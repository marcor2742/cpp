#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	RPN rpn;
	std::cout << "1. ";
	rpn.Calculate(argv[1]);
	std::cout << std::endl;


	std::cout << "2. ";
	RPN rpn2;
	rpn2.Calculate("8 9 * 9 - 9 - 9 - 4 - 1 +");

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
	
}