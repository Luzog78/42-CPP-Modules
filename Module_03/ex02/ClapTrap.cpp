/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:58:38 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 13:57:30 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
										_energyPoints(10), _attackDamage(0) {
	std::cout	<< GREEN
				<< "ClapTrap " << this->_name << " is born !"
				<< RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout	<< RED
				<< "ClapTrap " << this->_name << " is destroyed..."
				<< RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ClapTrap " << this->_name
					<< " can't attack " << target
					<< " because he is dead." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ClapTrap " << this->_name
					<< " can't attack " << target
					<< " because he has no energy left." << std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_attackDamage
				<< " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ClapTrap " << this->_name
					<< " can't take damage because he is dead."
					<< std::endl;
		return ;
	}
	if (this->_hitPoints <= amount) {
		std::cout	<< "ClapTrap " << this->_name
					<< " died after taking " << amount
					<< " points of damage... RIP" << std::endl;
		this->_hitPoints = 0;
	} else {
		std::cout	<< "ClapTrap " << this->_name
					<< " takes " << amount
					<< " points of damage! (" << this->_hitPoints - amount
					<< " HP left)" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ClapTrap " << this->_name
					<< " can't be repaired because he is dead."
					<< std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ClapTrap " << this->_name
					<< " can't be repaired because he has no energy left."
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name
				<< " is repaired for " << amount
				<< " points of damage! (" << this->_hitPoints + amount
				<< " HP left)" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}
