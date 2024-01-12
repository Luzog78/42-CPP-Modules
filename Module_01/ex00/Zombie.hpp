/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:22:56 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 06:38:42 by ysabik           ###   ########.fr       */
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
		void	announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
