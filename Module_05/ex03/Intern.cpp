/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:30:55 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 07:12:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {
}

Intern	&Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(const std::string formName, const std::string target) {
	std::map<std::string, AForm*>	map;

	map["shrubbery creation"] = new ShrubberyCreationForm(target);
	map["robotomy request"] = new RobotomyRequestForm(target);
	map["presidential pardon"] = new PresidentialPardonForm(target);

	AForm	*ret = 0;

	std::map<std::string, AForm*>::iterator it = map.begin();
	while (it != map.end()) {
		if (it->first == formName)
			ret = it->second;
		else
			delete it->second;
		it++;
	}
	
	if (ret)
		std::cout	<< "Intern creates " << target << std::endl;
	else
		std::cout	<< RED << "Intern can't create a '" << formName
					<< "'... What is that ??" << RESET << std::endl;

	return ret;
}
