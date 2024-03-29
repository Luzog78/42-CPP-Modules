/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:12:06 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 04:44:42 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		grade = rhs.getGrade();
	return *this;
}

const std::string	Bureaucrat::getName() const {
	return name;
}

int	Bureaucrat::getGrade() const {
	return grade;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

void	Bureaucrat::incrementGrade() {
	setGrade(grade - 1);
}

void	Bureaucrat::decrementGrade() {
	setGrade(grade + 1);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
