/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:06 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 17:50:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout	<< GREEN
				<< "(Cat)     " << this->type << " is born !"
				<< RESET << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout	<< YELLOW
				<< "(Cat)     " << this->type << " is born !"
				<< RESET << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	std::cout	<< RED
				<< "(Cat)     " << this->type << " is destroyed..."
				<< RESET << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout	<< "(Cat)     " << this->type << ": "
				<< "* Meow *" << std::endl;
}
