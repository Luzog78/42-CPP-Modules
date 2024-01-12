/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:22:45 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:34:35 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {

	std::cout << "Creating a zombie by calling newZombie !" << std::endl;
	Zombie *heapZombie = newZombie("Heap's Zombie");
	heapZombie->announce();

	std::cout << std::endl;

	std::cout << "Creating a zombie by calling randomChump !" << std::endl;
	randomChump("Stack's Zombie");

	std::cout << std::endl;

	std::cout << "Kill the heapZombie to avoid memory leaks !" << std::endl;
	delete heapZombie;

	return 0;
}
