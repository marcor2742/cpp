#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string suffix = ".replace";
	std::string fileout = argv[1] + suffix;

	std::ifstream inFile(filename.c_str());
	if (!inFile)
	{
		std::cerr << "Error: No such file or permission denied" << std::endl;
		return 1;
	}
	std::ofstream outFile(fileout.c_str());
	if (!outFile)
    {
        std::cerr << "Errore: impossibile creare il file di output" << std::endl;
        return 1;
    }

	std::string line;
	std::size_t pos;
	std::string newline = ""; //ma per sicurezza la inizializzo vuota
	std::size_t lenS1 = s1.length();
	while (std::getline(inFile, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			newline = newline + line.substr(0, pos); //funziona anche se nweline è vuota o non inizializzata
			line = line.substr(pos + lenS1);
			newline = newline + s2;
			pos = line.find(s1);
		}
		newline = newline + line; //funziona anche se nweline è vuota o non inizializzata
		outFile << newline << '\n';
		newline.clear();
	}
	inFile.close();
    outFile.close();
}
