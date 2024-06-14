/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:31:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"


Warlock::Warlock() {
}


Warlock::Warlock(std::string name, std::string title) {
	this->name = name;
	this->title = title;

	std::cout << name << ": This looks like another boring day." << std::endl;
}


Warlock::Warlock(const Warlock &src) {
	*this = src;
}


Warlock	&Warlock::operator=(const Warlock &rhs) {
	if (this != &rhs) {
		name = rhs.name;
		title = rhs.title;
		spells = rhs.spells;
	}
	return *this;
}


Warlock::~Warlock() {
	for (size_t i = 0; i < spells.size(); i++)
		delete spells[i];

	std::cout << name << ": My job here is done!" << std::endl;
}


/* ************************************************************************** */


void	Warlock::introduce() const {
	std::cout << name << ": I am " + name + ", " + title + "!" << std::endl;
}


void	Warlock::learnSpell(ASpell *spell) {
	if (spell == NULL)
		return;

	for (size_t i = 0; i < spells.size(); i++)
		if (spells[i]->getName() == spell->getName())
			return;

	spells.push_back(spell);
}


void	Warlock::forgetSpell(std::string spellName) {
	for (std::vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++)
		if ((*it)->getName() == spellName) {
			delete *it;
			spells.erase(it);
			break;
		}
}


void	Warlock::launchSpell(std::string spellName, ATarget &target) const {
	for (size_t i = 0; i < spells.size(); i++)
		if (spells[i]->getName() == spellName) {
			target.getHitBySpell(*(spells[i]));
			break;
		}
}


/* ************************************************************************** */


const std::string	&Warlock::getName() const {
	return name;
}


const std::string	&Warlock::getTitle() const {
	return title;
}


void	Warlock::setTitle(const std::string &title) {
	this->title = title;
}
