/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 23:04:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"


SpellBook::SpellBook() {
}


SpellBook::SpellBook(const SpellBook &src) {
	*this = src;
}


SpellBook	&SpellBook::operator=(const SpellBook &rhs) {
	if (this != &rhs) {
		spells = rhs.spells;
	}
	return *this;
}


SpellBook::~SpellBook() {
	for (size_t i = 0; i < spells.size(); i++)
		delete spells[i];
}


/* ************************************************************************** */


void	SpellBook::learnSpell(ASpell *spell) {
	if (spell == NULL)
		return;

	for (size_t i = 0; i < spells.size(); i++)
		if (spells[i]->getName() == spell->getName())
			return;

	spells.push_back(spell->clone());
}


void	SpellBook::forgetSpell(std::string spellName) {
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
		if ((*it)->getName() == spellName) {
			delete *it;
			spells.erase(it);
			break;
		}
}


ASpell*	SpellBook::createSpell(const std::string &spellName) const {
	for (size_t i = 0; i < spells.size(); i++)
		if (spells[i]->getName() == spellName)
			return spells[i]->clone();
	return NULL;
}


/* ************************************************************************** */
