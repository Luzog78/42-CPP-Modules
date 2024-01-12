/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:45:33 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:49:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout	<< "Address of String:    " << &str << std::endl
				<< "Address of Pointer:   " << ptr << std::endl
				<< "Address of Reference: " << &ref << std::endl;

	std::cout	<< std::endl;

	std::cout	<< "Value of String:    " << str << std::endl
				<< "Value of Pointer:   " << *ptr << std::endl
				<< "Value of Reference: " << ref << std::endl;

	return 0;
}
