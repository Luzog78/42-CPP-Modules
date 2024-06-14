/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:00:10 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "Fwoosh.hpp"
# include "Dummy.hpp"

class Warlock {
	private:
		std::string				name;
		std::string				title;
		std::vector<ASpell*>	spells;

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
