/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:10 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 17:40:17 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout	<< GREEN
				<< "(Dog)     " << this->type << " is born !"
				<< RESET << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout	<< YELLOW
				<< "(Dog)     " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout	<< RED
				<< "(Dog)     " << this->type << " is destroyed..."
				<< RESET << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout	<< "(Dog)     " << this->type << ": "
				<< "* Woof *" << std::endl;
}
