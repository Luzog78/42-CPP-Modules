/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 07:16:59 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void ft_title(const std::string title) {
	std::cout	<< CYAN << "=== === === ~~~ " << title
				<< " ~~~ === === ===" << RESET << std::endl;
}

void ft_handle(const std::string title, const std::string request, const std::string target,
	Bureaucrat &employee, Bureaucrat &secretary, Bureaucrat &manager, Bureaucrat &ceo, Intern &intern) {
	ft_title(title);
	AForm	*form = intern.makeForm(request, target);
	if (!form)
		return;
	std::cout << *form << std::endl << std::endl;

	ceo.executeForm(*form);
	std::cout << std::endl;

	employee.signForm(*form);
	secretary.signForm(*form);
	manager.signForm(*form);
	ceo.signForm(*form);
	std::cout << std::endl;

	employee.executeForm(*form);
	secretary.executeForm(*form);
	manager.executeForm(*form);
	ceo.executeForm(*form);
	std::cout << std::endl;

	delete form;
}

int	main() {
	std::srand(std::time(0));

	ft_title("Team Presentation");
	Bureaucrat	employee("Employee", 150);
	Bureaucrat	secretary("Secretary", 100);
	Bureaucrat	manager("Manager", 50);
	Bureaucrat	ceo("CEO", 1);

	std::cout << employee << std::endl;
	std::cout << secretary << std::endl;
	std::cout << manager << std::endl;
	std::cout << ceo << std::endl;

	Intern	intern;

	std::cout << std::endl;

	ft_handle("ShrubberyCreationForm", "shrubbery creation", "home",
		employee, secretary, manager, ceo, intern);

	std::cout << std::endl;

	ft_handle("RobotomyRequestForm", "robotomy request", "Bender",
		employee, secretary, manager, ceo, intern);

	std::cout << std::endl;

	ft_handle("PresidentialPardonForm", "presidential pardon", "Trump",
		employee, secretary, manager, ceo, intern);

	std::cout << std::endl;

	ft_handle("Unknown", "Unknown Form Request", "TARGET",
		employee, secretary, manager, ceo, intern);

	return 0;
}
