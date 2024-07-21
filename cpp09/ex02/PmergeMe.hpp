/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:22:43 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/21 19:22:44 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <climits>
#include <cerrno>
#include <utility>
#include <sys/time.h>

#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::deque<int> m_deque;
		std::vector<int> m_vector;
		int m_threshold;

	public:
		PmergeMe();
		PmergeMe(PmergeMe const& copy);
		~PmergeMe();
		PmergeMe& operator=(PmergeMe const& copy);

		void	pmerge(char **argv);

		void	parse(char **argv);
		template< typename T >
		void	merge_sort(T & lst, int beg, int end);
		template< typename T >
		void	insertion_sort(T &cont, int begin, int end);
		template< typename T >
		void	printCont(T & lst);
};

#endif