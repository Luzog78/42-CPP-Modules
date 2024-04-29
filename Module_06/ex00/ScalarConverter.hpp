/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:44:22 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/29 05:42:41 by ysabik           ###   ########.fr       */
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
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &rhs);

	public:
		static void	convert(std::string input);
};

#endif
