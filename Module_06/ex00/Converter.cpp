/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:14:38 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 04:44:24 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string input) :
	input(input), c(0), i(0), f(0), d(0),
	cConverted(false), iConverted(false), fPseudo(NaN), dPseudo(NaN) {
}

Converter::Converter(const Converter &src) : 
	input(src.getInput()), c(0), i(0), f(0), d(0),
	cConverted(false), iConverted(false), fPseudo(NaN), dPseudo(NaN) {
	*this = src;
}

Converter::~Converter() {
}

Converter	&Converter::operator=(const Converter &rhs) {
	if (this != &rhs) {
		input = rhs.input;
		c = rhs.c;
		i = rhs.i;
		f = rhs.f;
		d = rhs.d;
		cConverted = rhs.cConverted;
		iConverted = rhs.iConverted;
		fPseudo = rhs.fPseudo;
		dPseudo = rhs.dPseudo;
	}
	return *this;
}

void	Converter::convertInputToDouble() {
	if (input.empty() || input.length() > 4930)
		return;
	if (input.length() == 1 && !std::isdigit(input[0])) {
		d = input[0];
		dPseudo = Number;
		return;
	} else if (input == "+inf" || input == "+inff")
		dPseudo = Inf;
	else if (input == "-inf" || input == "-inff")
		dPseudo = NInf;
	else if (input == "nan" || input == "nanf")
		dPseudo = NaN;
	else {
		char		*longRest;
		long long	longVal = strtoll(input.c_str(), &longRest, 10);
		char		*doubleRest;
		long double	doubleVal = strtold(input.c_str(), &doubleRest);
		
		if (!longRest) {
			if (longVal >= INT_MIN && longVal <= INT_MAX) {
				d = static_cast<double>(longVal);
				dPseudo = Number;
			}
		} else {
			if (*doubleRest == 'f' && *(doubleRest + 1) == '\0') {
				if (doubleVal >= FLOAT_MIN && doubleVal <= FLOAT_MAX) {
					d = static_cast<float>(doubleVal);
					dPseudo = Number;
				}
			} else if (*doubleRest == '\0') {
				if (doubleVal >= DOUBLE_MIN && doubleVal <= DOUBLE_MAX) {
					d = static_cast<double>(doubleVal);
					dPseudo = Number;
				}
			}
		}
	}
}

void	Converter::convertDoubleToChar() {
	if (dPseudo != Number)
		return;
	if (d >= CHAR_MIN && d <= CHAR_MAX) {
		c = static_cast<char>(d);
		cConverted = true;
	}
}

void	Converter::convertDoubleToInt() {
	if (dPseudo != Number)
		return;
	if (d >= INT_MIN && d <= INT_MAX) {
		i = static_cast<int>(d);
		iConverted = true;
	}
}

void	Converter::convertDoubleToFloat() {
	if (!isDoubleConverted())
		return;
	if (dPseudo == Inf || d > FLOAT_MAX)
		fPseudo = Inf;
	else if (dPseudo == NInf || d < FLOAT_MIN)
		fPseudo = NInf;
	else {
		f = static_cast<float>(d);
		fPseudo = Number;
	}
}

std::string	Converter::getInput() const {
	return input;
}

char	Converter::getChar() const {
	return c;
}

int	Converter::getInt() const {
	return i;
}

float	Converter::getFloat() const {
	return f;
}

double	Converter::getDouble() const {
	return d;
}

bool	Converter::isCharConverted() const {
	return cConverted;
}

bool	Converter::isIntConverted() const {
	return iConverted;
}

bool	Converter::isFloatConverted() const {
	return fPseudo != NaN;
}

bool	Converter::isDoubleConverted() const {
	return dPseudo != NaN;
}

Pseudo	Converter::getFloatPseudo() const {
	return fPseudo;
}

Pseudo	Converter::getDoublePseudo() const {
	return dPseudo;
}

void	Converter::printChar() const {
	if (isCharConverted()) {
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	} else
		std::cout << "char: impossible" << std::endl;
}

void	Converter::printInt() const {
	if (isIntConverted())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	Converter::printFloat() const {
	if (isFloatConverted()) {
		if (fPseudo == Inf)
			std::cout << "float: +inff" << std::endl;
		else if (fPseudo == NInf)
			std::cout << "float: -inff" << std::endl;
		else if (f == static_cast<long long>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	} else
		std::cout << "float: nanf" << std::endl;
}

void	Converter::printDouble() const {
	if (isDoubleConverted()) {
		if (dPseudo == Inf)
			std::cout << "double: +inf" << std::endl;
		else if (dPseudo == NInf)
			std::cout << "double: -inf" << std::endl;
		else if (d == static_cast<long long>(d))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	} else
		std::cout << "double: nan" << std::endl;
}
