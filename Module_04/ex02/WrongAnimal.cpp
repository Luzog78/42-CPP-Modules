/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:13:33 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 17:50:45 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout	<< GREEN
				<< "(WrongAnimal)  " << this->type << " is born !"
				<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout	<< GREEN
				<< "(WrongAnimal)  " << this->type << " is born !"
				<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout	<< YELLOW
				<< "(WrongAnimal)  " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout	<< RED
				<< "(WrongAnimal)  " << this->type << " is destroyed..."
				<< RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

void	WrongAnimal::makeSound() const {
	std::cout	<< "(WrongAnimal)  " << this->type << ": "
				<< "* HUGE DEAFENING NOISE *" << std::endl;
}
