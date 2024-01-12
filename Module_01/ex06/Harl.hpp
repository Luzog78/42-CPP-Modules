/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:33:58 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 07:52:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
	
	public:
		Harl();
		~Harl();

		void	complain(std::string level) const;
};

#endif
