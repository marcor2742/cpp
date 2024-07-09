/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:42:38 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 15:42:58 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
	srand(time(NULL));

	Base *ABC = generate();
	identify_from_pointer(ABC);
	//identify_from_reference(*ABC);

	delete ABC;
}