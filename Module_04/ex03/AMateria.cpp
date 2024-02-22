/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:08:34 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/22 11:03:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout	<< GREEN << ALIGN("(AMateria)")
				<< this->type << "is created !"
				<< RESET << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	std::cout	<< YELLOW << ALIGN("(AMateria)")
				<< this->type << "is created !"
				<< RESET << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	std::cout	<< RED << ALIGN("(AMateria)")
				<< this->type << "is destroyed..."
				<< RESET << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string const	&AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout	<< ALIGN("(AMateria)")
				<< "* uses " << this->type << " on " << target.getName() << " *"
				<< std::endl;
}
