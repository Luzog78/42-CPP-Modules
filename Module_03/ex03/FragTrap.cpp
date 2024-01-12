/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:05:37 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 14:13:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout	<< GREEN
				<< "FragTrap " << this->_name << " is born !"
				<< RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout	<< RED
				<< "FragTrap " << this->_name << " is destroyed..."
				<< RESET << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout	<< "FragTrap " << this->_name
				<< " is asking for high fives !!" << std::endl;
}
