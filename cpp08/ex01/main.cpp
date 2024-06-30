#include "Span.hpp"

int main()
{
	Span minmax(12);
	std::vector<int> vec;
	vec.push_back(INT_MAX);

	vec.push_back(INT_MIN);
	std::cout << static_cast<unsigned int>(INT_MAX) - static_cast<unsigned int>(INT_MIN) << std::endl;

	minmax.addNumber(vec.begin(), vec.end());
	std::cout << "shortestSpan: " << minmax.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << minmax.longestSpan() << std::endl;


	Span error(5);
	std::vector<int> vec2;
	vec2.push_back(15);
	vec2.push_back(-13);
	vec2.push_back(-13);
	vec2.push_back(4);
	vec2.push_back(3);
	vec2.push_back(41);
	try
	{
		error.addNumber(vec2.begin(), vec2.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "shortestSpan: " << error.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << error.longestSpan() << std::endl; // 5 - 1 = 4 (il 6 non è stato aggiunto)


	Span empty(5);
	try
	{
		empty.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	Span toomuch(100000);
	std::vector<int> vec3;
	for (int i = 0; i < 100000; i++)
		vec3.push_back(i);
	try
	{
		toomuch.addNumber(vec3.begin(), vec3.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "shortestSpan: " << toomuch.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << toomuch.longestSpan() << std::endl;


std::cout << "RAND_MAX è: " << RAND_MAX << std::endl;
	srand(static_cast<unsigned int>(time(0))); 
	Span random(10000);
	std::vector<int> vec4;
	for (int i = 0; i < 10000; i++)
		vec4.push_back(rand());
	random.addNumber(vec4.begin(), vec4.end());
	std::cout << "shortestSpan: " << random.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << random.longestSpan() << std::endl;

}