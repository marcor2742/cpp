#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	std::cout << "swap" << std::endl;
	T tmp = b;
	b = a;
	a = tmp;
}

template<typename T>
T min(T a, T b)
{
	std::cout << "minCalled( ";
	if (a < b)
		return a;
	return b;
}

template<typename T>
T max(T a, T b)
{
	std::cout << "maxCalled( ";
	if (a > b)
		return a;
	return b;
}

#endif