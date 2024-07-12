/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:24:13 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/12 15:24:14 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};
Span::Span(unsigned int N) : N(N) {};
Span::~Span() {};
Span::Span(const Span &other) : N(other.N) {};
Span& Span::operator=(const Span &other) { N = other.N; return *this; };

void Span::addNumber(int n)
{
	if (vec.size() == N)
		throw std::out_of_range("vec is full");
	vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		if (vec.size() == N)
			throw std::out_of_range("vec is full");
		vec.push_back(*it);
	}
}

unsigned int Span::shortestSpan()
{
	long long tmp;
	long long min_span = UINT_MAX;

	if (vec.size() < 2)
		throw std::out_of_range("vec is too small");
	std::sort(vec.begin(), vec.end());
	
	for (std::vector<int>::iterator it = vec.begin() + 1; it != vec.end(); it++)
	{
		tmp = std::abs(static_cast<long long>(*(it - 1)) - static_cast<long long>(*it));
		if (tmp < min_span)
			min_span = tmp;
	}
	return min_span;

}

unsigned int Span::longestSpan()
{
	if (vec.size() < 2)
		throw std::out_of_range("vec is too small");
	std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
	std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
	return std::abs(static_cast<long long>(*max) - static_cast<long long>(*min));
}