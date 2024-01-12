/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:34:03 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 08:16:40 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

bool	getCommand(std::string command, std::string input) {
	if (command.length() < input.length())
		return false;
	for (unsigned int i = 0; i < input.length(); i++)
		if (isspace(input[i]))
			break;
		else if (tolower(command[i]) != tolower(input[i]))
			return false;
	return true;
}

int	main() {
	Harl		harl;
	std::string	input;
	
	while (1) {
		if (!std::cin.eof())
			std::cout << "Enter a complaining level: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "Bye." << std::endl;
			break;
		} else if (getCommand(input, "exit"))
			break;
		else {
			harl.complain(input);
			std::cout << std::endl;
		}
	}
	
	return 0;
}
