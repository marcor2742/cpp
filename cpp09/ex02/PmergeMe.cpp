#include "PmergeMe.hpp"

void	PmergeMe::pmerge(char **argv)
{

	try
	{
		parse(argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

bool flag = false;
unsigned int tmp;

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
	std::cout << "List: ";
	for (std::list<int>::iterator it = m_list.begin(); it != m_list.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl << "Vector: ";
	for (std::vector<int>::iterator it = m_vector.begin(); it != m_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	//fill vector pair with m_vector values. if odd, tmp = last value and flag = true
	std::vector<std::pair<unsigned int, unsigned int> > vec;
	for (size_t i = 0; i < m_vector.size(); i += 2)
	{
		if (i + 1 < m_vector.size())
			vec.push_back(std::make_pair(m_vector[i], m_vector[i + 1]));
		else
		{
			tmp = m_vector[i];
			flag = true;
		}
	}


	std::vector<unsigned int> vec_a, vec_b;

	mergeInsertion_sort(vec, vec_a, vec_b, 'v');



	//fill list pair with m_vector values. if odd, tmp = last value and flag = true
	std::deque<std::pair<unsigned int, unsigned int> > dec;
	for (size_t i = 0; i < m_deque.size(); i += 2)
	{
		if (i + 1 < m_deque.size())
			dec.push_back(std::make_pair(m_deque[i], m_deque[i + 1]));
		else
		{
			tmp = m_deque[i];
			flag = true;
		}
	}

	std::deque<unsigned int> dec_a, dec_b;
    mergeInsertion_sort(dec, dec_a, dec_b, 'd');

}


template <typename T, typename S, typename V>

void    PmergeMe::mergeInsertion_sort(T &container, S &cont, V &conta, char choice)
{
    //              Time
    struct timeval start, end;
    long sec, micro;

    gettimeofday(&start, NULL);
    for (size_t i = 0; i < container.size(); i++)
    {
        if (container[i].first > container[i].second)
            std::swap(container[i].first, container[i].second);
    }

    for (size_t i = 0; i < container.size(); i++)
        conta.push_back(container[i].first);

    for (size_t i = 0; i < container.size(); i++)
        cont.push_back(container[i].second);

    std::sort(conta.begin(), conta.end());

    for (size_t i = 0; i < cont.size(); i++)
        conta.insert(std::lower_bound(conta.begin(), conta.end(), cont[i]), cont[i]);
    if (flag)
        conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);

    std::cout << "\nAfter  : "; 

    for (size_t i = 0; i < conta.size(); i++)
        std::cout << conta[i] << " ";

    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    long diff = (sec / 1000000) + (micro);
    if (choice == 'v')
        std::cout << "\nTime to process vector : " << diff  << " us" << "\n";
    if (choice == 'd')
        std::cout << "\nTime to process deque : " << diff  << " us" << "\n";
}