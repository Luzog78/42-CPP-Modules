/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:04 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 19:26:17 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "include.hpp"
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain		*brain;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &src);
		virtual	~Animal();

		Animal	&operator=(Animal const &rhs);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
		Brain			*getBrain() const;
		void			setBrain(Brain *brain);
};

#endif
