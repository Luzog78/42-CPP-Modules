/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:34:03 by ysabik            #+#    #+#             */
/*   Updated: 2024/06/14 22:58:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug() const {
	std::cout	<< "[ DEBUG ] " << std::endl
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!"
				<< std::endl << std::endl;
}

void	Harl::info() const {
	std::cout	<< "[ INFO ] " << std::endl
				<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn't put enough bacon in my burger! If you did, "
				<< "I wouldn't be asking for more!"
				<< std::endl << std::endl;
}

void	Harl::warning() const {
	std::cout	<< "[ WARNING ] " << std::endl
				<< "I think I deserve to have some extra bacon for free. "
				<< "I've been coming foryears whereas you started working "
				<< "here since last month."
				<< std::endl << std::endl;
}

void	Harl::error() const {
	std::cout	<< "[ ERROR ] " << std::endl
				<< "This is unacceptable! "
				<< "I want to speak to the manager now."
				<< std::endl << std::endl;
}

void	Harl::complain(std::string level) const {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++ ;
	switch (i) {
		case 0:
			this->debug();
			/* fallthrough */
		case 1:
			this->info();
			/* fallthrough */
		case 2:
			this->warning();
			/* fallthrough */
		case 3:
			this->error();
			break ;
		default:
			std::cout	<< "[ Probably complaining about "
						<< "insignificant problems ]" << std::endl;
	}
}
