/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:28:21 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 18:50:47 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "include.hpp"

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(Brain const &src);
		~Brain();

		Brain	&operator=(Brain const &rhs);

		std::string	*getIdeas();
		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);
};

#endif
