/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:57:31 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator() {
}


TargetGenerator::TargetGenerator(const TargetGenerator &src) {
	*this = src;
}


TargetGenerator	&TargetGenerator::operator=(const TargetGenerator &rhs) {
	if (this != &rhs) {
		targets = rhs.targets;
	}
	return *this;
}


TargetGenerator::~TargetGenerator() {
	for (size_t i = 0; i < targets.size(); i++)
		delete targets[i];
}


/* ************************************************************************** */


void	TargetGenerator::learnTargetType(ATarget *target) {
	if (target == NULL)
		return;

	for (size_t i = 0; i < targets.size(); i++)
		if (targets[i]->getType() == target->getType())
			return;

	targets.push_back(target->clone());
}


void	TargetGenerator::forgetTargetType(std::string targetsType) {
	for (std::vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++)
		if ((*it)->getType() == targetsType) {
			delete *it;
			targets.erase(it);
			break;
		}
}


ATarget*	TargetGenerator::createTarget(const std::string &targetsType) const {
	for (size_t i = 0; i < targets.size(); i++)
		if (targets[i]->getType() == targetsType)
			return targets[i]->clone();
	return NULL;
}


/* ************************************************************************** */
