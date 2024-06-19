#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat mary("mary", 146);

	try
	{
		Bureaucrat john("john", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n" << std::endl;
	}

	Bureaucrat luca("luca", 10);
	std::cout << luca;
	for (int i = 0; true; ++i)
	{
		try
		{
			luca.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n" << std::endl;
			break;
		}
		std::cout << i << " ";
	}
	Bureaucrat reno(mary);
	std::cout << reno;
	for (int i = 0; true; ++i)
	{
		try
		{
			reno.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << "\n" <<std::endl;
			break;
		}
		std::cout << i << " ";
	}

	Bureaucrat lisa;
	lisa = luca;
	std::cout << lisa << std::endl;
}