/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:30:55 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 04:51:50 by ysabik           ###   ########.fr       */
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
	std::string	requests[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm	*forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	AForm	*ret = 0;

	for (int i = 0; i < 3; i++)
		if (formName == requests[i])
			ret = forms[i];
		else
			delete forms[i];
	
	if (ret)
		std::cout	<< "Intern creates " << target << std::endl;
	else
		std::cout	<< RED << "Intern can't create a '" << formName
					<< "'... What is that ??" << RESET << std::endl;

	return ret;
}
