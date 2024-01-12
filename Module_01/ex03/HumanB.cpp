/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:52:13 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 07:00:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void	HumanB::attack() {
	if (this->_weapon == NULL)
		std::cout	<< this->_name
					<< " has no weapon to attack with"
					<< std::endl;
	else
		std::cout	<< this->_name
					<< " attacks with their "
					<< this->_weapon->getType()
					<< std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
