/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:21:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"


ASpell::ASpell() {
}


ASpell::ASpell(std::string name, std::string effects) {
	this->name = name;
	this->effects = effects;
}


ASpell::ASpell(const ASpell &src) {
	*this = src;
}


ASpell	&ASpell::operator=(const ASpell &rhs) {
	if (this != &rhs) {
		name = rhs.name;
		effects = rhs.effects;
	}
	return *this;
}


ASpell::~ASpell() {
}


/* ************************************************************************** */


void	ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}


/* ************************************************************************** */


std::string	ASpell::getName() const {
	return name;
}


std::string	ASpell::getEffects() const {
	return effects;
}
