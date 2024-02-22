/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:50 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/22 11:01:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout	<< GREEN << ALIGN("(MateriaSource)")
				<< "MateriaSource is created !"
				<< RESET << std::endl;
	for (int i = 0; i < SOURCE_SIZE; i++)
		this->source[i] = NULL;
	this->count = 0;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	std::cout	<< YELLOW << ALIGN("(MateriaSource)")
				<< "MateriaSource is created !"
				<< RESET << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout	<< RED << ALIGN("(MateriaSource)")
				<< "MateriaSource is destroyed..."
				<< RESET << std::endl;
	for (int i = 0; i < this->count; i++)
		delete this->source[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < this->count; i++)
			delete this->source[i];
		for (int i = 0; i < SOURCE_SIZE; i++)
			this->source[i] = rhs.source[i]->clone();
		this->count = rhs.count;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (this->count < SOURCE_SIZE)
	{
		this->source[this->count] = m->clone();
		this->count++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->count; i++)
		if (this->source[i]->getType() == type)
			return this->source[i]->clone();
	return NULL;
}
