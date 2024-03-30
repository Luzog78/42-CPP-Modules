/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:30:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main() {
	std::srand(std::time(0));

	for (int i = 0; i < 10; i++) {
		if (i)
			std::cout << std::endl;

		Base	*base = generate();

		identify(base);
		identify(*base);

		delete base;
	}

	return 0;
}
