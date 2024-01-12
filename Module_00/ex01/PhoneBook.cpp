/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:16:34 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 04:38:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _nbContacts(0), _index(0) {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::addContact(Contact contact) {
	if (this->_nbContacts < MAX_CONTACTS)
		this->_nbContacts++;
	if (this->_index >= MAX_CONTACTS)
		this->_index = 0;
	this->_contacts[this->_index++] = contact;
}

void	PhoneBook::printAllContacts() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		std::cout << std::setw(10) << i << "|";
		this->_printTenChars(this->_contacts[i].getFirstName());
		std::cout << "|";
		this->_printTenChars(this->_contacts[i].getLastName());
		std::cout << "|";
		this->_printTenChars(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::printContact(int index) const {
	if (index >= 0 && index < MAX_CONTACTS) {
		std::cout << "First name: " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	} else if (index >= 0 && index < this->_nbContacts)
		std::cout << "Contact not found" << std::endl;
	else
		std::cout << "Invalid index" << std::endl;
}

void	PhoneBook::_printTenChars(std::string str) const {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}
