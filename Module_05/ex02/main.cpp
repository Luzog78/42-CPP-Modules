/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:22:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void ft_title(const std::string title) {
	std::cout	<< CYAN << "=== === === ~~~ " << title
				<< " ~~~ === === ===" << RESET << std::endl;
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


	std::cout << std::endl;


	ft_title("ShrubberyCreationForm");
	ShrubberyCreationForm	shrubbery("home");
	std::cout << shrubbery << std::endl << std::endl;

	ceo.executeForm(shrubbery);
	std::cout << std::endl;

	employee.signForm(shrubbery);
	secretary.signForm(shrubbery);
	manager.signForm(shrubbery);
	ceo.signForm(shrubbery);
	std::cout << std::endl;

	employee.executeForm(shrubbery);
	secretary.executeForm(shrubbery);
	manager.executeForm(shrubbery);
	ceo.executeForm(shrubbery);
	std::cout << std::endl;


	std::cout << std::endl;


	ft_title("RobotomyRequestForm");
	RobotomyRequestForm	robotomy("Bender");
	std::cout << robotomy << std::endl << std::endl;

	ceo.executeForm(robotomy);
	std::cout << std::endl;

	employee.signForm(robotomy);
	secretary.signForm(robotomy);
	manager.signForm(robotomy);
	ceo.signForm(robotomy);
	std::cout << std::endl;

	employee.executeForm(robotomy);
	secretary.executeForm(robotomy);
	manager.executeForm(robotomy);
	ceo.executeForm(robotomy);
	ceo.executeForm(robotomy);
	ceo.executeForm(robotomy);
	std::cout << std::endl;


	std::cout << std::endl;


	ft_title("PresidentialPardonForm");
	PresidentialPardonForm	presidential("Trump");
	std::cout << presidential << std::endl << std::endl;

	ceo.executeForm(presidential);
	std::cout << std::endl;

	employee.signForm(presidential);
	secretary.signForm(presidential);
	manager.signForm(presidential);
	ceo.signForm(presidential);
	std::cout << std::endl;

	employee.executeForm(presidential);
	secretary.executeForm(presidential);
	manager.executeForm(presidential);
	ceo.executeForm(presidential);
	std::cout << std::endl;

	return 0;
}
