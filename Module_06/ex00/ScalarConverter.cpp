/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:53:44 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 03:27:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Converter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void) src;
}

void	ScalarConverter::convert(std::string input) {
	Converter	converter(input);
	
	converter.convertInputToDouble();
	converter.convertDoubleToChar();
	converter.convertDoubleToInt();
	converter.convertDoubleToFloat();

	converter.printChar();
	converter.printInt();
	converter.printFloat();
	converter.printDouble();
}
