/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:56:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "ASpell.hpp"
# include "ATarget.hpp"

# include "SpellBook.hpp"
# include "Fwoosh.hpp"
# include "Fireball.hpp"
# include "Polymorph.hpp"

# include "TargetGenerator.hpp"
# include "Dummy.hpp"
# include "BrickWall.hpp"

class Warlock {
	private:
		std::string	name;
		std::string	title;
		SpellBook	spellBook;

		Warlock();
		Warlock(const Warlock &src);
		Warlock	&operator=(const Warlock &rhs);
	
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		void				introduce() const;
		void				learnSpell(ASpell *spell);
		void				forgetSpell(std::string spellName);
		void				launchSpell(std::string spellName, ATarget &target) const;

		const std::string	&getName() const;
		const std::string	&getTitle() const;
		void				setTitle(const std::string &title);
};

#endif
