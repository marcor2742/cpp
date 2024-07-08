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

void mergeVector(std::vector<int> &result, unsigned int startLeft, unsigned int middle, unsigned int endRight)
{
	std::vector<int> vecLeft(result.begin() + startLeft, result.begin() + middle + 1);
	std::vector<int> vecRight(result.begin() + middle + 1, result.begin() + endRight + 1);

	unsigned int iLeft = 0;
	unsigned int iRight = 0;
	unsigned int index = startLeft;
	while (iLeft < vecLeft.size() && iRight < vecRight.size())
	{
		if (vecLeft[iLeft] <= vecRight[iRight])
			result[index++] = vecLeft[iLeft++];
		else
			result[index++] = vecRight[iRight++];
	}

	while (iLeft < vecLeft.size())
		result[index++] = vecLeft[iLeft++];

	while (iRight < vecRight.size())
		result[index++] = vecRight[iRight++];
}

void mergeSort(std::vector<int> &vec, unsigned int left, unsigned int right)
{
	if (left < right)
	{
		unsigned int middle = left + (right - left) / 2;
		mergeSort(vec, left, middle);
		mergeSort(vec, middle + 1, right);
		mergeVector(vec, left, middle, right);
	}
}

std::list<int> mergeList(std::list<int>::iterator startLeft, std::list<int>::iterator middle, std::list<int>::iterator endRight)
{
    std::list<int> result;
    std::list<int>::iterator left = startLeft;
    std::list<int>::iterator right = middle;

    while (left != middle && right != endRight)
    {
        if (*left < *right)
        {
            result.push_back(*left);
            ++left;
        }
        else
        {
            result.push_back(*right);
            ++right;
        }
    }

    while (left != middle)
    {
        result.push_back(*left);
        ++left;
    }

    while (right != endRight)
    {
        result.push_back(*right);
        ++right;
    }

    return result;
}

void mergesort(std::list<int> &list, std::list<int>::iterator start, std::list<int>::iterator end)
{
	if (std::distance(start, end) > 1)
	{
		std::list<int>::iterator middle = start;
		std::advance(middle, std::distance(start, end) / 2);
		mergesort(list, start, middle);
		mergesort(list, middle, end);
		std::list<int> result = mergeList(start, middle, end);
		std::copy(result.begin(), result.end(), start);
	}
}

void	PmergeMe::mergeInsertion_sort()
{
	bool OddOne = false;
	int OddOne_value;
	if (m_vector.size() % 2 != 0)
	{
		OddOne = true;
		OddOne_value = m_list.back();
		m_list.pop_back();
		m_vector.pop_back();
	}

	clock_t start = clock();
	mergesort(m_list, m_list.begin(), m_list.end());
	if (OddOne == true)
	{
		// For std::list
		std::list<int>::iterator positionList = std::lower_bound(m_list.begin(), m_list.end(), OddOne_value);
		m_list.insert(positionList, OddOne_value);
	}
	clock_t end_l = clock();



	clock_t start_v = clock();
	mergeSort(m_vector, 0, m_vector.size() - 1);
	if (OddOne == true)
	{
		std::vector<int>::iterator positionVector = std::lower_bound(m_vector.begin(), m_vector.end(), OddOne_value);
		m_vector.insert(positionVector, OddOne_value);
	}
	clock_t end_v = clock();


	
	std::cout << "Sorted: ";
	for (size_t i = 0; i < m_vector.size(); i++)
	{
		std::cout << m_vector[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "List Time: " << (double)(end_l - start) / CLOCKS_PER_SEC * 1000000 << "us" << std::endl;
	std::cout << "Vector Time: " << (double)(end_v - start_v) / CLOCKS_PER_SEC * 1000000 << "us" << std::endl;
}