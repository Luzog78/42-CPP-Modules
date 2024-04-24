/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:54:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/24 17:04:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void find(std::vector<int> intVector, int i) {
	std::cout << "Trying to find " << i << " in intVector..." << std::endl;
	try {
		std::vector<int>::iterator	it = easyfind(intVector, i);
		size_t						pos = it - intVector.begin();

		std::cout << "Found at position: " << pos
					<< " (" << it.base() << ")" << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main() {
	std::vector<int> intVector(10);
	
	for (size_t i = 0; i < intVector.size(); i++)
		intVector[i] = i * i;

	std::cout << "intVector: ";
	for (size_t i = 0; i < intVector.size(); i++)
		std::cout << intVector[i] << " ";
	std::cout << std::endl << std::endl;

	find(intVector, 4);
	std::cout << std::endl;
	find(intVector, 25);
	std::cout << std::endl;
	find(intVector, -1);

	return 0;
}
