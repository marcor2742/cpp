#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.tpp"

int main()
{
	std::vector<int> vez;

	vez.push_back(1);
	vez.push_back(231);
	vez.push_back(65);
	vez.push_back(7);
	//vez.insert(vez.begin() + 1, 9);

	vez.pop_back();

	for (int i = 0; i < (int)vez.size(); ++i)
		std::cout << vez[i] << " ";
	std::cout << std::endl;

	std::cout << easyfind(vez, 7) << std::endl;
	//std::find(vez.begin(), vez.end(), 9); //output end se non lo trova
}