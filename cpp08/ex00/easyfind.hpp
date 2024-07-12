/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:24:00 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/12 15:24:01 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void easyfind(T &input, int tofind)
{
	try
	{
		int i = 0;
		for (typename T::iterator it = input.begin(); it != input.end(); ++it, i++)
		{
			if (*it == tofind)
			{
				std::cout << i << std::endl;
				return;
			}
		}
		throw std::runtime_error("not found");
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
}