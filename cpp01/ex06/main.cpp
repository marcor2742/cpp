#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "harl evidentemente ha scritto troppo o si è dimenticato di scrivere un argomento" << std::endl;
		return 1;
	}

	std::string levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (argv[1] != levelArray[i] && i < 4)
		i++;
	
	Harl obj;
	switch (i)
	{
        case 0:
            obj.complain("debug");
			obj.complain("info");
			obj.complain("warning");
			obj.complain("error");
            break;
        case 1:
			obj.complain("info");
			obj.complain("warning");
			obj.complain("error");
            break;
        case 2:
			obj.complain("warning");
			obj.complain("error");
            break;
		case 3:
			obj.complain("error");
			break;
        default:
            obj.complain("insignificant problems");
    }
}