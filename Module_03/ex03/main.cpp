/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:58:44 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 14:37:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {

	ClapTrap	a("Luky Luke");

	a.attack("The Bad Guys");
	a.takeDamage(5);
	a.beRepaired(5);

	ScavTrap	b("Cole Cassidy");

	b.attack("The Bad Boys");
	b.takeDamage(5);
	b.beRepaired(5);
	b.guardGate();

	FragTrap	c("John Wayne");

	c.attack("The Bad Persons");
	c.takeDamage(5);
	c.beRepaired(5);
	c.highFivesGuys();

	DiamondTrap	d("Doc");
	
	d.attack("The Bad Beings");
	d.takeDamage(5);
	d.beRepaired(5);
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();

	return 0;
}
