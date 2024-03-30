/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:54:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 06:12:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	sum = 0;

void	print_s(const std::string &s) {
	std::cout << "\"" << s << "\" ";
}

void	print_s_len(const std::string &s) {
	std::cout << s.length() << " ";
}

void	print_i(const int &i) {
	std::cout << i << " ";
}

void	print_square(const int &i) {
	std::cout << i * i << " ";
}

void	print_cube(const int &i) {
	std::cout << i * i * i << " ";
}

void	incr_sum(const int &i) {
	sum += i;
}

int main() {
	
	int		intArray[5] = {1, 2, 3, 4, 5};

	std::cout << "intArray: ";
	iter(intArray, 5, print_i);
	std::cout << std::endl << std::endl;
	
	std::cout << "intArray squared: ";
	iter(intArray, 5, print_square);
	std::cout << std::endl << std::endl;

	std::cout << "intArray cubed: ";
	iter(intArray, 5, print_cube);
	std::cout << std::endl << std::endl;

	iter(intArray, 5, incr_sum);
	std::cout << "sum of intArray: " << sum << std::endl << std::endl;

	std::cout << "-------" << std::endl << std::endl;

	std::string	strArray[5] = {"one", "two", "three", "four", "five"};

	std::cout << "strArray: ";
	iter(strArray, 5, print_s);
	std::cout << std::endl << std::endl;

	std::cout << "strArray length: ";
	iter(strArray, 5, print_s_len);
	std::cout << std::endl;

	return 0;
}
