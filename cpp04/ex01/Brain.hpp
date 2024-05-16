#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &obj);
	Brain &operator=(const Brain &obj);
};

#endif