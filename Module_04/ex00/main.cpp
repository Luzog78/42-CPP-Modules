/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:14 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/20 13:27:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Dog();

	std::cout << std::endl;

	const WrongAnimal	*mmeta = new WrongAnimal();
	const WrongAnimal	*ii = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta->getType():  " << meta->getType() << std::endl;
	std::cout << "i->getType():     " << i->getType() << std::endl;
	std::cout << "j->getType():     " << j->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "mmeta->getType(): " << mmeta->getType() << std::endl;
	std::cout << "ii->getType():    " << ii->getType() << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;
	mmeta->makeSound();
	ii->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	std::cout << std::endl;
	delete mmeta;
	delete ii;
	return 0;
}
