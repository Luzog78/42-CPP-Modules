/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:07:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"


Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {
}


Polymorph::Polymorph(const Polymorph &src) : ASpell(src) {
}


Polymorph	&Polymorph::operator=(const Polymorph &rhs) {
	ASpell::operator=(rhs);
	return *this;
}


Polymorph::~Polymorph() {
}


/* ************************************************************************** */


Polymorph	*Polymorph::clone() const {
	return new Polymorph(*this);
}


/* ************************************************************************** */
