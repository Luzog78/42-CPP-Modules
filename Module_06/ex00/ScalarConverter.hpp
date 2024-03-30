/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:44:22 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:19:29 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>

enum Pseudo {
	NaN,
	Inf,
	NInf,
	Number
};

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		virtual ~ScalarConverter() = 0;
		virtual ScalarConverter	&operator=(const ScalarConverter &rhs) = 0;

		static void	convert(std::string input);
};

#endif
