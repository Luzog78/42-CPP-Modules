/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:10 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:38:54 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), brain(new Brain()) {
	std::cout	<< GREEN
				<< "(Dog)     " << this->type << " is born !"
				<< RESET << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src), brain(new Brain()) {
	std::cout	<< YELLOW
				<< "(Dog)     " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout	<< RED
				<< "(Dog)     " << this->type << " is destroyed..."
				<< RESET << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(Dog const &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout	<< "(Dog)     " << this->type << ": "
				<< "* Woof *" << std::endl;
}

Brain	*Dog::getBrain() const {
	return this->brain;
}

void	Dog::setBrain(Brain *brain) {
	delete this->brain;
	this->brain = brain;
}
