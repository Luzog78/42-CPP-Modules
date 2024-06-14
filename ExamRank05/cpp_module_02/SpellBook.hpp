/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:42:17 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include "ASpell.hpp"

class SpellBook {
	private:
		std::vector<ASpell*>	spells;

		SpellBook(const SpellBook &src);
		SpellBook	&operator=(const SpellBook &rhs);

	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spellName);
		ASpell*	createSpell(const std::string &spellName) const;
};

#endif
