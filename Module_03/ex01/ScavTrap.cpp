/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:17:44 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 14:13:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout	<< GREEN
				<< "ScavTrap " << this->_name << " is born !"
				<< RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout	<< RED
				<< "ScavTrap " << this->_name << " is destroyed..."
				<< RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void	ScavTrap::attack(std::string const &target) {
	if (this->_hitPoints == 0) {
		std::cout	<< "ScavTrap " << this->_name
					<< " can't attack " << target
					<< " because he is dead." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout	<< "ScavTrap " << this->_name
					<< " can't attack " << target
					<< " because he has no energy left." << std::endl;
		return ;
	}
	std::cout	<< "ScavTrap " << this->_name
				<< " attacks " << target
				<< ", causing " << this->_attackDamage
				<< " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate() {
	std::cout	<< "ScavTrap " << this->_name
				<< " has entered in Gate keeper mode." << std::endl;
}
