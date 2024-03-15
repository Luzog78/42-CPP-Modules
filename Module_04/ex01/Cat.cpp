/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:06 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:36:20 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), brain(new Brain()) {
	std::cout	<< GREEN
				<< "(Cat)     " << this->type << " is born !"
				<< RESET << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src), brain(new Brain()) {
	std::cout	<< YELLOW
				<< "(Cat)     " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	std::cout	<< RED
				<< "(Cat)     " << this->type << " is destroyed..."
				<< RESET << std::endl;
	delete this->brain;
}

Cat	&Cat::operator=(Cat const &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout	<< "(Cat)     " << this->type << ": "
				<< "* Meow *" << std::endl;
}

Brain	*Cat::getBrain() const {
	return this->brain;
}

void	Cat::setBrain(Brain *brain) {
	delete this->brain;
	this->brain = brain;
}
