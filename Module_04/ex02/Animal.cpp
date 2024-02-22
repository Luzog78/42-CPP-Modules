/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:02 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 19:24:16 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("CommonAnimal"), brain(new Brain()) {
	std::cout	<< GREEN
				<< "(Animal)  " << this->type << " is born !"
				<< RESET << std::endl;
}

Animal::Animal(std::string type) : type(type), brain(new Brain()) {
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
	delete this->brain;
}

Animal	&Animal::operator=(Animal const &rhs) {
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

Brain	*Animal::getBrain() const {
	return this->brain;
}

void	Animal::setBrain(Brain *brain) {
	delete this->brain;
	this->brain = brain;
}