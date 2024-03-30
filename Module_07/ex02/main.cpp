/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:54:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 06:40:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {

	Array<int> intArray(5);

	std::cout << "intArray empty: ";
	for (size_t i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < intArray.size(); i++)
		intArray[i] = i * i;

	std::cout << "intArray filled with squares: ";
	for (size_t i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "intArray size: " << intArray.size() << std::endl << std::endl;


	Array<std::string> stringArray(3);

	std::cout << "stringArray empty: ";
	for (size_t i = 0; i < stringArray.size(); i++)
		std::cout << "\"" << stringArray[i] << "\" ";
	std::cout << std::endl << std::endl;

	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";

	std::cout << "stringArray filled: ";
	for (size_t i = 0; i < stringArray.size(); i++)
		std::cout << "\"" << stringArray[i] << "\" ";
	std::cout << std::endl << std::endl;

	std::cout << "stringArray size: " << stringArray.size() << std::endl << std::endl;

	try {
		std::cout << "Trying to access out of bounds..." << std::endl;
		std::cout << stringArray[3] << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
