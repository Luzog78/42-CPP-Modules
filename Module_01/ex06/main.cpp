/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:34:03 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 08:18:24 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	Harl	harl;
	harl.complain(argv[1]);

	return 0;
}
