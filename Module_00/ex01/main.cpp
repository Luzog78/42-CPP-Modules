/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:20:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 05:00:27 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwsomePhonebook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string	command;

	while (1) {
		if (!std::cin.eof())
			std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cout << std::endl << "Bye." << std::endl;
			break;
		} else if (getCommand(command, "EXIT"))
			break;
		else if (getCommand(command, "ADD")) {
			std::string firstName = askForInput("First name");
			if (firstName.empty())
				continue;
			std::string lastName = askForInput("Last name");
			if (firstName.empty())
				continue;
			std::string nickname = askForInput("Nickname");
			if (firstName.empty())
				continue;
			std::string phoneNumber = askForInput("Phone number");
			if (firstName.empty())
				continue;
			std::string darkestSecret = askForInput("Darkest secret");
			if (firstName.empty())
				continue;
		
			phoneBook.addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
		} else if (getCommand(command, "SEARCH"))
			if (!(command = getArg(command, 1)).empty())
				if (command.length() == 1
					&& command[0] >= '1' && command[0] <= '8')
					phoneBook.printContact(command[0] - '1');
				else
					std::cout << "Invalid index" << std::endl;
			else
				phoneBook.printAllContacts();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
