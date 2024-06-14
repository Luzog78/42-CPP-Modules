/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:22:18 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"


ATarget::ATarget() {
}


ATarget::ATarget(std::string type) {
	this->type = type;
}


ATarget::ATarget(const ATarget &src) {
	*this = src;
}


ATarget	&ATarget::operator=(const ATarget &rhs) {
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}


ATarget::~ATarget() {
}


/* ************************************************************************** */


void	ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}


/* ************************************************************************** */


const std::string	&ATarget::getType() const {
	return type;
}
