/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 21:35:17 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"


Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
}


Fwoosh::Fwoosh(const Fwoosh &src) : ASpell(src) {
}


Fwoosh	&Fwoosh::operator=(const Fwoosh &rhs) {
	ASpell::operator=(rhs);
	return *this;
}


Fwoosh::~Fwoosh() {
}


/* ************************************************************************** */


Fwoosh	*Fwoosh::clone() const {
	return new Fwoosh(*this);
}


/* ************************************************************************** */
