/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 04:55:14 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	Form		form("Form", 149, 150);

	std::cout	<< form << std::endl << std::endl;

	Bureaucrat	bureaucrat("Bureaucrat", 150);

	std::cout	<< bureaucrat << std::endl;
	bureaucrat.signForm(form);

	std::cout	<< std::endl;

	bureaucrat.incrementGrade();
	std::cout	<< bureaucrat << std::endl;
	bureaucrat.signForm(form);

	return 0;
}
