#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : n(0), array(NULL) {}

template<typename T>
Array<T>::Array(unsigned int n) : n(n), array(new T[n]()) {}

template<typename T>
Array<T>::Array(const Array& other) 
{
	*this = other;
}

template<typename T>
Array<T>::~Array()
{
	delete [] array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete [] array;
		n = other.n;
		array = new T[n];
		for (unsigned int i = 0; i < n; i++)
			array[i] = other.array[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= n || i < 0)
		throw std::out_of_range("Index is out of range");
	return array[i];
}

template<typename T>
int Array<T>::size() const
{
	return n;
}