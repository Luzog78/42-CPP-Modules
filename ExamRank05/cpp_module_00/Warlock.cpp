/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 21:05:49 by ysabik           ###   ########.fr       */
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
	}
	return *this;
}


Warlock::~Warlock() {
	std::cout << name << ": My job here is done!" << std::endl;
}


/* ************************************************************************** */


void	Warlock::introduce() const {
	std::cout << name << ": I am " + name + ", " + title + "!" << std::endl;
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
