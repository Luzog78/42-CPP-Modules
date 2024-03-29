/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 04:44:36 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	ft_bureaucrat(const std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout	<< bureaucrat << std::endl;
	} catch(const std::exception& e) {
		std::cerr	<< "Error (on '" << name << "', " << grade << "): "
					<< e.what() << std::endl;
	}
}

int	main() {

	for (int i = 0; i < 26; i++)
		ft_bureaucrat(std::string(1, 'A' + i), i * 10 - 49);

	return 0;
}
