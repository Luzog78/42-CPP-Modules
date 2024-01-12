/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:58:44 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 11:15:53 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {

	ClapTrap	a("Luky Luke");

	a.attack("The Bad Guys");
	a.takeDamage(5);
	a.beRepaired(5);

	return 0;
}
