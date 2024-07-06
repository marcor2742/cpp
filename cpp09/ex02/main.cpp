#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe [int1] [int2] [int3] ..." << std::endl;
		return 1;
	}
	PmergeMe pm;
	pm.pmerge(argv);
}