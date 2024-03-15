/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:22:33 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 08:55:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout	<< GREEN
				<< "(WrongCat)     " << this->type << " is born !"
				<< RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout	<< YELLOW
				<< "(WrongCat)     " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout	<< RED
				<< "(WrongCat)     " << this->type << " is destroyed..."
				<< RESET << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout	<< "(WrongCat)     " << this->type << ": "
				<< "* MOOOOWWW *" << std::endl;
}
