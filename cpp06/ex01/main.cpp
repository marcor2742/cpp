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