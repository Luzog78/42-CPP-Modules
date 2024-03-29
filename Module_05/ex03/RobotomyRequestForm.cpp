/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 05:16:03 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:21:23 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", 72, 45), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	AForm(src), target(src.target) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

const std::string	RobotomyRequestForm::getTarget() const {
	return target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecRequirement())
		throw AForm::GradeTooLowException();

	std::cout	<< "* Drilling noises... *" << std::endl;

	if (std::rand() % 2)
		std::cout	<< "Haha ! " << target << " has been robotomized !" << std::endl;
	else
		std::cout	<< "Oh no.. " << target << "'s robotomization failed.." << std::endl;
}
