#include "PmergeMe.hpp"

void	PmergeMe::pmerge(char **argv)
{

	try
	{
		parse(argv);
		mergeInsertion_sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	PmergeMe::parse(char **argv)
{
	char *endptr;
    errno = 0;
    for (int i = 1; argv[i]; i++)
    {
        long val = std::strtol(argv[i], &endptr, 10);
        
        if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (val > INT_MAX || val < INT_MIN))
        {
			throw std::out_of_range("Error: number out of range");
        }
		if (*endptr != '\0')
		{
			throw std::invalid_argument("Error: invalid argument");
		}

        
        m_list.push_back(static_cast<int>(val));
        m_vector.push_back(static_cast<int>(val));
    }

	std::cout << "List: ";
	for (std::list<int>::iterator it = m_list.begin(); it != m_list.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "Vector: ";
	for (std::vector<int>::iterator it = m_vector.begin(); it != m_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::mergeInsertion_sort()
{

}