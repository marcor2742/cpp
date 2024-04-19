#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include "colours.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {

    this->_accountIndex = _nbAccounts;
    ++_nbAccounts;
    this->_totalAmount = this->_totalAmount + initial_deposit;
    this->_amount = initial_deposit;
    
    _displayTimestamp();
    std::cout << "index:" BLUE<< _accountIndex <<END ";amount:" BLUE<< initial_deposit <<END ";created" << std::endl; 
}

int Account::getNbAccounts(){
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(){
    return (Account::_totalAmount);
}

int Account::getNbDeposits(){
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(){
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" BLUE<< getNbAccounts() <<END ";total:" BLUE<< getTotalAmount() <<END ";deposits:" BLUE<< getNbDeposits() <<END ";withdrawals:" BLUE<< getNbWithdrawals() <<END<< std::endl;
}

Account::~Account(){
    std::cout << "cose finite" << std::endl; 
}

int Account::checkAmount() const{
    return (this->_amount);
}

void Account::_displayTimestamp(){
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    char buffer[20];
    strftime(buffer, 20, "%Y%m%d_%H%M%S", now);

    std::cout << "[" << buffer << "] ";
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" BLUE<< _accountIndex <<END ";amount:" BLUE<< this->_amount <<END ";deposits:" BLUE<< _nbDeposits <<END ";withdrawals:" BLUE<< _nbWithdrawals <<END << std::endl; 
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1" << std::endl;
}