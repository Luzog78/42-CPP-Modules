/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 02:20:54 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 04:26:25 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(std::string firstName, std::string lastName,
				std::string nickname, std::string phoneNumber,
				std::string darkestSecret);
		~Contact();
		void		setFirstName(std::string firstName);
		std::string	getFirstName() const;
		void		setLastName(std::string lastName);
		std::string	getLastName() const;
		void		setNickname(std::string nickname);
		std::string	getNickname() const;
		void		setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber() const;
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getDarkestSecret() const;
};

#endif
