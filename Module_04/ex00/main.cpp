/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:57:14 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/15 09:19:31 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal	*meta = new Animal();
	const Animal	*cat = new Cat();
	const Animal	*dog = new Dog();

	std::cout << std::endl;

	const WrongAnimal	*wmeta = new WrongAnimal();
	const WrongAnimal	*wcat = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta->getType():  " << meta->getType() << std::endl;
	std::cout << "cat->getType():   " << cat->getType() << std::endl;
	std::cout << "dog->getType():   " << dog->getType() << std::endl;
	std::cout << std::endl;
	std::cout << "wmeta->getType(): " << wmeta->getType() << std::endl;
	std::cout << "wcat->getType():  " << wcat->getType() << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	cat->makeSound();
	dog->makeSound();
	std::cout << std::endl;
	wmeta->makeSound();
	wcat->makeSound();
	((WrongCat *) wcat)->makeSound();
	std::cout << std::endl;

	delete meta;
	delete cat;
	delete dog;
	std::cout << std::endl;
	delete wmeta;
	delete wcat;
	return 0;
}
