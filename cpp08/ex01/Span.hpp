#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()

class Span
{
private:
	std::vector<int> vec;
	unsigned int N;
	Span() {};
public:
	Span(unsigned int N) : N(N) {};
	~Span() {};
	Span(const Span &other) : N(other.N) {};
	Span &operator=(const Span &other) { N = other.N; return *this; };

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif