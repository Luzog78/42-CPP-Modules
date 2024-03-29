/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:24:46 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:13:39 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int signRequirement, int execRequirement) :
	name(name), signRequirement(signRequirement),
	execRequirement(execRequirement), isSigned(false) {
	if (signRequirement < 1 || execRequirement < 1)
		throw AForm::GradeTooHighException();
	if (signRequirement > 150 || execRequirement > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) :
	name(src.name), signRequirement(src.signRequirement),
	execRequirement(src.execRequirement), isSigned(src.isSigned) {
}

AForm::~AForm() {
}

AForm	&AForm::operator=(const AForm &rhs) {
	if (this != &rhs)
		isSigned = rhs.isSigned;
	return *this;
}

const std::string	AForm::getName() const {
	return name;
}

int	AForm::getSignRequirement() const {
	return signRequirement;
}

int	AForm::getExecRequirement() const {
	return execRequirement;
}

bool	AForm::getIsSigned() const {
	return isSigned;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (isSigned)
		throw AForm::FormAlreadySignedException();
	if (bureaucrat.getGrade() > signRequirement)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

const char	*AForm::FormAlreadySignedException::what() const throw() {
	return "Form is already signed";
}

std::ostream	&operator<<(std::ostream &o, const AForm &rhs) {
	o	<< rhs.getName() << ", AForm"
		<< " sign requirement " << rhs.getSignRequirement()
		<< " and exec requirement " << rhs.getExecRequirement();
	return o;
}
