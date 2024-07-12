/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:25:06 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/12 15:25:07 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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