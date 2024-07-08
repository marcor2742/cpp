#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <climits>
#include <cerrno>
#include <utility>
#include <sys/time.h>
#include <deque>
//#include <sstream>
//#include <cstdlib>

class PmergeMe
{
	private:
		std::list<int> m_list;
		std::deque<int> m_deque;
		std::vector<int> m_vector;

	public:
		PmergeMe() {};
		PmergeMe(PmergeMe const& copy) { *this = copy; };
		~PmergeMe() {};

		PmergeMe& operator=(PmergeMe const& copy) { m_list = copy.m_list; m_vector = copy.m_vector; return *this; };

		void	pmerge(char **argv);
		void	parse(char **argv);
		template <typename T, typename S, typename V>
		void	mergeInsertion_sort(T &container, S &cont, V &conta, char choice);
};

#endif