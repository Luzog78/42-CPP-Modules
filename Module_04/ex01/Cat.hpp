/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:24:27 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

		Cat	&operator=(Cat const &rhs);

		void	makeSound() const;
		Brain	*getBrain() const;
		void	setBrain(Brain *brain);
};

#endif
