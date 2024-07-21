#include "PmergeMe.hpp"

void	PmergeMe::pmerge(char **argv)
{
	try
	{
	    clock_t start, end;
		double Vus, Dus;

		parse(argv);

		std::cout <<BLUE "Before sorting:" RESET<< std::endl;
		printCont(m_deque);
		printCont(m_vector);
		m_threshold = m_deque.size() * 0.1;

		start = clock();
			merge_sort(m_vector, 0, m_vector.size() - 1);
		end = clock();
		Vus = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
		start = clock();
			merge_sort(m_deque, 0, m_deque.size() - 1);
		end = clock();
		Dus = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

		std::cout <<BLUE "After sorting:" RESET<< std::endl;
		printCont(m_deque);
		printCont(m_vector);

		std::cout << "Vector time: " << Vus << "us" << std::endl;
		std::cout << "Deque time: " << Dus << "us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

template< typename T >
void	PmergeMe::printCont(T & cont)
{
	for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
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

        m_deque.push_back(static_cast<int>(val));
        m_vector.push_back(static_cast<int>(val));
    }
}

template<typename T>
void PmergeMe::insertion_sort(T &cont, int begin, int end)
{
	for (int i = begin + 1; i <= end; i++) 
	{
		int key = cont[i];
		int j = i - 1;
		while (j >= begin && cont[j] > key)
		{
			cont[j + 1] = cont[j];
			j = j - 1;
		}
		cont[j + 1] = key;
	}
}

template<typename T>
void PmergeMe::merge_sort(T &cont, int begin, int end)
{
	if (begin < end)
	{
		if (end - begin <= m_threshold)
			insertion_sort(cont, begin, end);
		else
		{
			int middle = (begin + end) / 2;
			merge_sort(cont, begin, middle);
			merge_sort(cont, middle + 1, end);

			std::vector<int> tmp(end - begin + 1);
			int b = begin, m = middle + 1, i = 0;

			while (b <= middle && m <= end)
			{
				if (cont[b] <= cont[m])
					tmp[i++] = cont[b++];
				else
					tmp[i++] = cont[m++];
			}
			while (b <= middle)
				tmp[i++] = cont[b++];
			while (m <= end)
				tmp[i++] = cont[m++];

			for (int it = 0; it < i; it++) 
				cont[begin + it] = tmp[it];
		}
	}
}
