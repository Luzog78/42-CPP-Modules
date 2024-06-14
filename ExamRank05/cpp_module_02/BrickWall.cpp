/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:10:02 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"


BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {
}


BrickWall::BrickWall(const BrickWall &src) : ATarget(src) {
}


BrickWall	&BrickWall::operator=(const BrickWall &rhs) {
	ATarget::operator=(rhs);
	return *this;
}


BrickWall::~BrickWall() {
}


/* ************************************************************************** */


BrickWall	*BrickWall::clone() const {
	return new BrickWall(*this);
}


/* ************************************************************************** */
