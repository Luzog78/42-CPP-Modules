/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/29 05:43:59 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "Usage: ./convert number" << std::endl;
		return 1;
	}

	ScalarConverter::convert(av[1]);

	return 0;
}
