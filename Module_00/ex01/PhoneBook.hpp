/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:15:09 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 04:32:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_nbContacts;
		int		_index;

		void	_printTenChars(std::string str) const;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(Contact contact);
		void	printAllContacts() const;
		void	printContact(int index) const;
};

#endif
