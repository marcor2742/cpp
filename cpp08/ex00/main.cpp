#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

int main() {
    std::vector<int> vez;
    vez.push_back(1);
    vez.push_back(231);
    vez.push_back(65);
	vez.push_back(1);
    vez.push_back(7);
	vez.pop_back();

    for (std::vector<int>::size_type i = 0; i < vez.size(); ++i)
        std::cout << vez[i] << " ";
    std::cout << std::endl;
	
    // Test con std::list
    std::list<int> l;
	l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(1);




    easyfind(vez, 1);
	easyfind(vez, 65);
    easyfind(vez, 7);
    easyfind(l, 3);
}