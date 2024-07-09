/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:41:59 by mruggier          #+#    #+#             */
/*   Updated: 2024/07/09 15:42:00 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cassert>

void testSerialization() {
	Data originalData = {42, "Test String"};
	uintptr_t serializedData = Serializer::serialize(&originalData);
	assert(serializedData != 0);
}

void testDeserialization() {
	Data originalData = {42, "Test String"};
	uintptr_t serializedData = Serializer::serialize(&originalData);
	Data* deserializedData = Serializer::deserialize(serializedData);
	assert(deserializedData != 0); 
	assert(deserializedData->i == originalData.i);
	assert(deserializedData->str == originalData.str);
}

void testNullPointer() {
	uintptr_t serializedNull = Serializer::serialize(0);
	assert(serializedNull == 0);
	Data* deserializedNull = Serializer::deserialize(0);
	assert(deserializedNull == 0);
}

int main() {
	testSerialization();
	testDeserialization();
	testNullPointer();
	std::cout << "All tests passed!" << std::endl;
	return 0;
}