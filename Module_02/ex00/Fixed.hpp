/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:54:35 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 08:56:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		static const int	_bits = 8;
		int					_value;
	
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);
		Fixed	&operator=(Fixed const &rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
