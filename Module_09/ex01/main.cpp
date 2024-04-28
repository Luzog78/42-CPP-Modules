/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:39:31 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/27 13:41:31 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}

	RPN			rpn;
	std::string	str(av[1]);

	if (!rpn.exec(str)) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
