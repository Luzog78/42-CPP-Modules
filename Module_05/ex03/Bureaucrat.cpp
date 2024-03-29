/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:12:06 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:14:27 by ysabik           ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout	<< name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr	<< RED << name << " coulnd't sign " << form.getName()
					<< " because " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form) {
	try {
		form.execute(*this);
		std::cout	<< name << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr	<< RED << name << " coulnd't executed " << form.getName()
					<< " because " << e.what()<< RESET  << std::endl;
	}
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
