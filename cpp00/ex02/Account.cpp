#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;

// int index = 0;

Account::Account( int initial_deposit ) {

    this->_accountIndex = _nbAccounts;
    ++_nbAccounts;
    
    _displayTimestamp();
    _accountIndex++;
    std::cout << initial_deposit << std::endl; 
}

Account::~Account(){
    std::cout << "cose finite" << std::endl; 
}

void Account::_displayTimestamp(){
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    char buffer[20];
    strftime(buffer, 20, "%Y%m%d_%H%M%S", now);

    std::cout << "[" << buffer << "] ";
}