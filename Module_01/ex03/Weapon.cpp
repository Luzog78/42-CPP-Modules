/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:52:20 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:57:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::~Weapon() {
}

std::string const	&Weapon::getType() const {
	return this->_type;
}

void				Weapon::setType(std::string type) {
	this->_type = type;
}
