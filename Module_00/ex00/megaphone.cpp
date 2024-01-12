/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:35:04 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/11 23:18:51 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	bool	space;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++)
				if (isspace(argv[i][j]) && space)
					continue;
				else {
					std::cout << (char) toupper(argv[i][j]);
					space = isspace(argv[i][j]);
				}
			if (space)
				continue;
			std::cout << " ";
			space = true;
		}
	std::cout << std::endl;
	return 0;
}
