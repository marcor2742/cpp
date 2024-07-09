/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:42:08 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 15:42:09 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int i;
	std::string str;
};

class Serializer
{
private:
	Serializer() {}
	Serializer(const Serializer& other) { *this = other; }
	Serializer& operator=(const Serializer& other) { (void)other; return *this; }

public:
	~Serializer() {}
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif