/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:50:58 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 04:40:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwsomePhonebook.hpp"

bool	isNumber(std::string str) {
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

std::string	getArg(std::string input, int index) {
	for (unsigned int i = 0; i < input.length(); i++)
		if (isspace(input[i]))
			index--;
		else if (index == 0)
			return input.substr(i);
	return "";
}

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

std::string	askForInput(std::string message) {
	std::string	input = "";

	while (input.empty()) {
		if (std::cin.eof())
			return "";
		std::cout << message << ": ";
		std::getline(std::cin, input);
	}
	return input;
}
