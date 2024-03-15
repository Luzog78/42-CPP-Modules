/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:12 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:38:59 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(Dog const &src);
		~Dog();

		Dog	&operator=(Dog const &rhs);

		void	makeSound() const;
		Brain	*getBrain() const;
		void	setBrain(Brain *brain);
};

#endif
