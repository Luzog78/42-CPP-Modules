/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:57:40 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:19:37 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include "ScalarConverter.hpp"

# define CHAR_MIN		-128
# define CHAR_MAX		127

# define INT_MIN		-2147483648
# define INT_MAX		2147483647

# define FLOAT_MIN		-3.40282e+38
# define FLOAT_MAX		3.40282e+38

# define DOUBLE_MIN		-1.79769e+308
# define DOUBLE_MAX		1.79769e+308

class Converter {
	private:
		std::string	input;

		char	c;
		int		i;
		float	f;
		double	d;

		bool	cConverted;
		bool	iConverted;
		Pseudo	fPseudo;
		Pseudo	dPseudo;

	public:
		Converter(std::string input);
		Converter(const Converter &src);
		~Converter();
		Converter	&operator=(const Converter &rhs);

		void	convertInputToDouble();
		void	convertDoubleToChar();
		void	convertDoubleToInt();
		void	convertDoubleToFloat();

		std::string	getInput() const;
		char		getChar() const;
		int			getInt() const;
		float		getFloat() const;
		double		getDouble() const;

		bool	isCharConverted() const;
		bool	isIntConverted() const;
		bool	isFloatConverted() const;
		bool	isDoubleConverted() const;
		Pseudo	getFloatPseudo() const;
		Pseudo	getDoublePseudo() const;
		
		void	printChar() const;
		void	printInt() const;
		void	printFloat() const;
		void	printDouble() const;
};

#endif
