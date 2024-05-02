#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

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
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
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
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
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
    std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
	this->_nbDeposits = this->_nbDeposits + 1;
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	this->_amount = this->_amount + deposit;
	this->_totalAmount = this->_totalAmount + deposit;
	this->_totalNbDeposits = this->_totalNbDeposits + 1;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals = this->_nbWithdrawals + 1;
		this->_amount = this->_amount - withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << _nbDeposits << std::endl;
		this->_totalNbWithdrawals = this->_totalNbWithdrawals + 1;
		this->_totalAmount = this->_totalAmount - withdrawal;
		return (true);
	}
}

//./account > file && diff <(cut -c 19- 19920104_091532.log) <(cut -c 19- file) || echo fail
