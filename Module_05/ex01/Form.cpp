/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:24:46 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 05:01:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int signRequirement, int execRequirement) :
	name(name), signRequirement(signRequirement),
	execRequirement(execRequirement), isSigned(false) {
	if (signRequirement < 1 || execRequirement < 1)
		throw Form::GradeTooHighException();
	if (signRequirement > 150 || execRequirement > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) :
	name(src.name), signRequirement(src.signRequirement),
	execRequirement(src.execRequirement), isSigned(src.isSigned) {
}

Form::~Form() {
}

Form	&Form::operator=(const Form &rhs) {
	if (this != &rhs)
		this->isSigned = rhs.isSigned;
	return *this;
}

const std::string	Form::getName() const {
	return this->name;
}

int	Form::getSignRequirement() const {
	return this->signRequirement;
}

int	Form::getExecRequirement() const {
	return this->execRequirement;
}

bool	Form::getIsSigned() const {
	return this->isSigned;
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->signRequirement)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream	&operator<<(std::ostream &o, const Form &rhs) {
	o	<< rhs.getName() << ", form"
		<< " sign requirement " << rhs.getSignRequirement()
		<< " and exec requirement " << rhs.getExecRequirement();
	return o;
}
