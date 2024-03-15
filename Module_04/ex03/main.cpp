/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:32:37 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 10:00:16 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main() {
	IMateriaSource	*src = new MateriaSource();

	AMateria		*ice = new Ice();
	AMateria		*cure = new Cure();
	
	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter		*me = new Character("me");
	AMateria		*tmp;
	AMateria		*tmp2;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	ICharacter		*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;

	delete ice;
	delete cure;

	delete src;

	return 0;
}
