/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/29 05:38:43 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main() {
	std::srand(std::time(0));

	for (int i = 0; i < 10; i++) {
		Base	*base = generate();

		identify(base);
		identify(*base);
		
		std::cout << std::endl;

		delete base;
	}

	identify(0);

	return 0;
}
