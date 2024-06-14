/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:52:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <vector>

# include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string	name;
		std::string	effects;

	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &src);
		ASpell	&operator=(const ASpell &rhs);
		virtual ~ASpell();

		virtual ASpell	*clone() const = 0;
		void			launch(const ATarget &target) const;

		std::string		getName() const;
		std::string		getEffects() const;
};

#endif
