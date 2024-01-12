/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:05:56 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 04:26:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName,
					std::string nickname, std::string phoneNumber,
					std::string darkestSecret) :
					_firstName(firstName), _lastName(lastName),
					_nickname(nickname), _phoneNumber(phoneNumber),
					_darkestSecret(darkestSecret) {
}

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""),
						_phoneNumber(""), _darkestSecret("") {
}

Contact::~Contact() {
}

std::string	Contact::getFirstName() const {
	return this->_firstName;
}

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

std::string	Contact::getLastName() const {
	return this->_lastName;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

std::string	Contact::getNickname() const {
	return this->_nickname;
}

void	Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string	Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
