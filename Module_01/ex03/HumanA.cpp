/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:52:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:58:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
				_name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void	HumanA::attack() {
	std::cout	<< this->_name
				<< " attacks with their "
				<< this->_weapon.getType()
				<< std::endl;
}
