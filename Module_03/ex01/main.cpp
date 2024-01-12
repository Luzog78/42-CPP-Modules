/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:58:44 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 14:00:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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

	return 0;
}
