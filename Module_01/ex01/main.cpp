/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:22:45 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:42:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	int N = 5;

	std::cout << "Creating a zombie horde of size " << N << std::endl;
	Zombie *horde = zombieHorde(N, "Horde's Zombie");

	std::cout << std::endl;

	std::cout << "Announcing the horde !" << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << std::endl;

	std::cout << "Kill the horde to avoid memory leaks !" << std::endl;
	delete [] horde;

	return 0;
}
