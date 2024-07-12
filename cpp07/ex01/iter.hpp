/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:25:12 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/12 15:25:13 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename F>
void add2(F& value)
{
	value += 2;
}

template<typename T, typename F>
void iter(T *addr, int len, void (*func)(F&))
{
	for (int i = 0; i < len; i++)
		func(addr[i]);
}

#endif