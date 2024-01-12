/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:15:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 14:42:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
												ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout	<< GREEN
				<< "DiamondTrap " << this->_name << " is born !"
				<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src),
												ScavTrap(src), FragTrap(src) {
	*this = src;
}

DiamondTrap::~DiamondTrap() {
	std::cout	<< RED
				<< "DiamondTrap " << this->_name << " is destroyed..."
				<< RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void	DiamondTrap::attack(std::string const &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout	<< "My name is " << this->_name
				<< " and my ClapTrap name is " << ClapTrap::_name
				<< std::endl;
}
