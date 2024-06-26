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