/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:16:48 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:51:19 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout	<< GREEN << ALIGN("(Cure)")
				<< this->getType() << " is created !"
				<< RESET << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src) {
	std::cout	<< YELLOW << ALIGN("(Cure)")
				<< this->getType() << " is created !"
				<< RESET << std::endl;
	*this = src;
}

Cure::~Cure() {
	std::cout	<< RED << ALIGN("(Cure)")
				<< this->getType() << " is destroyed..."
				<< RESET << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs) {
	if (this != &rhs)
		this->AMateria::operator=(rhs);
	return *this;
}

Cure	*Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter &target) {
	std::cout	<< std::setw(WIDTH) << ALIGN("(Cure)")
				<< "* heals " << target.getName() << "'s wounds *"
				<< std::endl;
}
