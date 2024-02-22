/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:02 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 17:40:17 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("CommonAnimal") {
	std::cout	<< GREEN
				<< "(Animal)  " << this->type << " is born !"
				<< RESET << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout	<< GREEN
				<< "(Animal)  " << this->type << " is born !"
				<< RESET << std::endl;
}

Animal::Animal(Animal const &src) {
	std::cout	<< YELLOW
				<< "(Animal)  " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

Animal::~Animal() {
	std::cout	<< RED
				<< "(Animal)  " << this->type << " is destroyed..."
				<< RESET << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

void	Animal::makeSound() const {
	std::cout	<< "(Animal)  " << this->type << ": "
				<< "* Little shy noise *" << std::endl;
}
