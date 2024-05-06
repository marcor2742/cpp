#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "harl evidentemente ha scritto troppo o si è dimenticato di scrivere un argomento" << std::endl;
		return 1;
	}
	
	Harl obj;
    
	obj.complain(argv[1]);
}