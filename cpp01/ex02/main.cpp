#include <iostream>
#include <string>

int main(){
    std::string stringA = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringA;
    std::string &stringREF = stringA;

    std::cout << &stringA << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << stringA << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}