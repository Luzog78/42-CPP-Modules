/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAwsomePhonebook.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:51:25 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 03:56:09 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_AWSOME_PHONEBOOK_HPP
# define MY_AWSOME_PHONEBOOK_HPP

# include "PhoneBook.hpp"

bool		isNumber(std::string str);
std::string	getArg(std::string input, int index);
bool		getCommand(std::string command, std::string input);
std::string	askForInput(std::string message);

#endif