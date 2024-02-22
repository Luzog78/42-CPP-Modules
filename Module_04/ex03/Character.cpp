/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:20:20 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/22 11:02:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : name(name)
{
	std::cout	<< GREEN << ALIGN("(Character)")
				<< this->name << " is created !"
				<< RESET << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	std::cout	<< YELLOW << ALIGN("(Character)")
				<< this->name << " is created !"
				<< RESET << std::endl;
	*this = src;
}

Character::~Character()
{
	std::cout	<< RED << ALIGN("(Character)")
				<< this->name << " is destroyed..."
				<< RESET << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character	&Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

std::string const	&Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORY_SIZE)
		this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE && this->inventory[idx])
		this->inventory[idx]->use(target);
}
