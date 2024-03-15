/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:04:24 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:52:02 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "include.hpp"
# include "ICharacter.hpp"

class AMateria {
	protected:
		std::string		type;

	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual	~AMateria();

		AMateria	&operator=(AMateria const &rhs);

		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
