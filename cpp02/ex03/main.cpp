#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
	Point a(9.8f, 8.1f);
	Point b(2.6f, 6.2f);
	Point c(7.9f, 1.1f);
	Point toFind(6, 5);

	if (bsp(a, b, c, toFind))
		std::cout << "il punto è contenuto nel triangolo" << std::endl;
	else
		std::cout << "il punto non è contenuto nel triangolo" << std::endl;
}