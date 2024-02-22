/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:37:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 18:52:40 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout	<< GREEN
				<< "[Brain]   A brain has been created !"
				<< RESET << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout	<< YELLOW
				<< "[Brain]   A brain has been created !"
				<< RESET << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout	<< RED
				<< "[Brain]   A brain has been destroyed..."
				<< RESET << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::string	*Brain::getIdeas()
{
	return this->ideas;
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return "I have no idea...";
	return this->ideas[i];
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	this->ideas[i] = idea;
}
