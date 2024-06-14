/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 21:46:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"


Dummy::Dummy() : ATarget("Target Practice Dummy") {
}


Dummy::Dummy(const Dummy &src) : ATarget(src) {
}


Dummy	&Dummy::operator=(const Dummy &rhs) {
	ATarget::operator=(rhs);
	return *this;
}


Dummy::~Dummy() {
}


/* ************************************************************************** */


Dummy	*Dummy::clone() const {
	return new Dummy(*this);
}


/* ************************************************************************** */
