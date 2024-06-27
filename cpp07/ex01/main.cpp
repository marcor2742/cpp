#include <iostream>
#include "iter.hpp"

int main()
{
	float farray[3] = {1.5f, 2.99f, 3.0f};
	iter(farray, 3, add2);
	for(int i = 0; i < 3; i++)
        std::cout << farray[i] << " ";
    std::cout << std::endl;

	double darray[3] = {84.5, 11.98451, 6};
	iter(darray, 3, add2);
	for(int i = 0; i < 3; i++)
        std::cout << darray[i] << " ";
    std::cout << std::endl;
}