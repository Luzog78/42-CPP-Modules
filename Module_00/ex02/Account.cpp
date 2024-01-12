/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 04:51:28 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:15:26 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

int	Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount() {
	return Account::_totalAmount;
}

int	Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount + deposit
				<< ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:";
	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout	<< withdrawal
				<< ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount() const {
	return this->_amount;
}

void	Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	std::cout	<< std::setfill('0') << "["
				<< std::setw(2) << now->tm_year + 1900
				<< std::setw(2) << now->tm_mon + 1
				<< std::setw(2) << now->tm_mday << "_"
				<< std::setw(2) << now->tm_hour
				<< std::setw(2) << now->tm_min
				<< std::setw(2) << now->tm_sec << "] ";
}
