/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:06:35 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"


Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {
}


Fireball::Fireball(const Fireball &src) : ASpell(src) {
}


Fireball	&Fireball::operator=(const Fireball &rhs) {
	ASpell::operator=(rhs);
	return *this;
}


Fireball::~Fireball() {
}


/* ************************************************************************** */


Fireball	*Fireball::clone() const {
	return new Fireball(*this);
}


/* ************************************************************************** */
