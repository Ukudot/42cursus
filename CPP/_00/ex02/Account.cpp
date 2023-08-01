#include <iostream>
#include <ctime>
#include <locale>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	static int	i;

	this->_accountIndex = i;
	i++;
	this->_nbDeposits = 0;
	this->_amount = initial_deposit;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts = i;
	Account::_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();;
	std::cout << ";closed" << std::endl;
	return ;
}

int		Account::getNbAccounts(void)
{
	int	nbAccounts;

	nbAccounts = Account::_nbAccounts;
	return (nbAccounts);
}

int		Account::getTotalAmount(void)
{
	int	totalAmount;

	totalAmount = Account::_totalAmount;
	return (totalAmount);
}

int		Account::getNbDeposits(void)
{
	int	totalNbDeposits;

	totalNbDeposits = Account::_totalNbDeposits;
	return (totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	int	totalNbWithdrawals;

	totalNbWithdrawals = Account::_totalNbWithdrawals;
	return (totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();;
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->checkAmount() < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->checkAmount();
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	int	amount;

	amount = this->_amount;
	return (amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900) 
		<< (now->tm_mon + 1)
		<< now->tm_mday
		<< "_"
		<< now->tm_hour
		<< now->tm_min
		<< now->tm_sec
		<< "]";
//	std::cout << "[19920104_091532]";
	return ;
}
