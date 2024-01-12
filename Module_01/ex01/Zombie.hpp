/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:22:56 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:40:30 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void		announce();
		std::string	getName() const;
		void		setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
