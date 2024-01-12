/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:54:35 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 10:48:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main() {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout	<<	a	<< std::endl;
	std::cout	<<	++a	<< std::endl;
	std::cout	<<	a	<< std::endl;
	std::cout	<<	a++	<< std::endl;
	std::cout	<<	a	<< std::endl;
	std::cout	<<	b	<< std::endl;
	std::cout	<<	Fixed::max(a, b)	<< std::endl;

	return 0;
}
