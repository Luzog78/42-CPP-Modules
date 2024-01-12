/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:33:58 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 10:49:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug() const {
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!" << std::endl;
}

void	Harl::info() const {
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn't put enough bacon in my burger! If you did, "
				<< "I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning() const {
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I've been coming foryears whereas you started working "
				<< "here since last month." << std::endl;
}

void	Harl::error() const {
	std::cout	<< "This is unacceptable! "
				<< "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const {
	void (Harl::*funcs[4])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool 		found = false;

	for (int i = 0; i < 4 && !found; i++)
		if ((found = !levels[i].compare(level)))
			(this->*funcs[i])();
	
	if (!found)
		std::cout << "I'm lost, I don't know what to do!" << std::endl;
}
