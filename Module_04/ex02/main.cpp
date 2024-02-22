/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:14 by ysabik            #+#    #+#             */
/*   Updated: 2024/02/22 10:01:35 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	print_ideas(Animal *animal, int n_ideas = 3)
{
	for (int i = 0; i < n_ideas; i++)
		std::cout	<< "(" << animal->getType() << ")  "
					<< "Idea " << i << ": |"
					<< animal->getBrain()->getIdea(i) << "|"
					<< std::endl;
}

int	main(void)
{
	Animal	*animals[10];
	
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();

	std::cout << std::endl;

	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	std::cout << std::endl;

	Animal	*giraffe = new Dog();
	Animal	*eagle = new Cat();

	eagle->getBrain()->setIdea(0, "I'm a bird");
	eagle->getBrain()->setIdea(1, "I'm a predator");
	eagle->getBrain()->setIdea(2, "I'm a hunter");

	print_ideas(giraffe);
	print_ideas(eagle);
	
	std::cout	<< "---------" << std::endl
				<< "Copying the " << eagle->getType()
				<< " brain to the " << giraffe->getType()
				<< ":" << std::endl;
	giraffe->setBrain(new Brain(*eagle->getBrain()));
	std::cout	<< "---------" << std::endl;

	print_ideas(giraffe);
	print_ideas(eagle);

	delete giraffe;
	delete eagle;

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];
	return 0;
}
