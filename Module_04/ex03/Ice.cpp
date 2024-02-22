/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:14:39 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/22 11:00:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout	<< GREEN << ALIGN("(Ice)")
				<< this->getType() << " is created !"
				<< RESET << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	std::cout	<< YELLOW << ALIGN("(Ice)")
				<< this->getType() << " is created !"
				<< RESET << std::endl;
	*this = src;
}

Ice::~Ice()
{
	std::cout	<< RED << ALIGN("(Ice)")
				<< this->getType() << " is destroyed..."
				<< RESET << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		this->AMateria::operator=(rhs);
	return *this;
}

Ice	*Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout	<< ALIGN("(Ice)")
				<< "* shoots an ice bolt at " << target.getName() << " *"
				<< std::endl;
}
