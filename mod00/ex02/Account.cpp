#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << ' ';
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "created";
    std::cout << std::endl;
}

Account::~Account(void) {
    _nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout << ' ';
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "closed";
    std::cout << std::endl;
}

int Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (_totalAmount);
}

int Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

void Account::makeDeposit(int deposit) {
    const int p_amount = _amount;

    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << ' ';
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << p_amount << ';';
    std::cout << "deposit:" << deposit << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    const int p_amount = _amount;

    _displayTimestamp();
    std::cout << ' ';
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "p_amount:" << p_amount << ';';
    std::cout << "withdrawal:";
    if (_amount < withdrawal || withdrawal < 0) {
        std::cout << "refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout << withdrawal << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "nb_withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return (true);
}

int Account::checkAmount(void) const {
    return (_amount);
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << ' ';
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';
    std::cout << "deposits:" << _nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << ' ';
    std::cout << "accounts:" << _nbAccounts << ';';
    std::cout << "total:" << _totalAmount << ';';
    std::cout << "deposits:" << _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals;
    std::cout << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t time = std::time(NULL);
    std::tm *localtime = std::localtime(&time);
    char buffer[32];
    std::strftime(buffer, 32, "[%Y%m%d_%H%M%S]", localtime);
    std::cout << buffer;
}
