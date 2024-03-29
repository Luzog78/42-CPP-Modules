/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 05:12:02 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 05:41:37 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("PresidentialPardonForm", 25, 5), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	AForm(src), target(src.target) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

const std::string	PresidentialPardonForm::getTarget() const {
	return target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecRequirement())
		throw AForm::GradeTooLowException();

	std::cout	<< target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
