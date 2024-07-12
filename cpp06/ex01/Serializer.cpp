/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:42:05 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/12 12:18:43 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { *this = other; }
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}