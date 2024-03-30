/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:23:11 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:33:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {
}

Base	*generate(void) {
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p) {
	std::cout << "Pointer " << p << " is <";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << ">" << std::endl;
}

void	identify(Base &p) {
	std::cout << "Reference " << &p << " is <";
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "A";
	} catch (std::exception &e) {
		try {
			(void) dynamic_cast<B &>(p);
			std::cout << "B";
		} catch (std::exception &e) {
			try {
				(void) dynamic_cast<C &>(p);
				std::cout << "C";
			} catch (std::exception &e) {
				std::cout << "Unknown";
			}
		}
	}
	std::cout << ">" << std::endl;
}
