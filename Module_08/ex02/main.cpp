/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:54:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/24 18:23:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main() {
	MutantStack<int>	mstack;

	std::cout << "Pushing [ 5 17 ]..." << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top:  " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Popping..." << std::endl;
	mstack.pop();

	std::cout << "Top:  " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Pushing [ 3 10 737 0 ]..." << std::endl;
	mstack.push(3);
	mstack.push(10);
	mstack.push(737);
	// [...]
	mstack.push(0);

	std::cout << "Top:  " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Popping..." << std::endl;
	mstack.pop();
	std::cout << "Popping..." << std::endl;
	mstack.pop();

	std::cout << "Top:  " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	std::cout << "Iterator:   " << *it << std::endl;
	std::cout << "++Iterator: " << *++it << std::endl;
	std::cout << "--Iterator: " << *--it << std::endl;
	std::cout << std::endl;

	std::cout << "End iterator:     " << *ite << std::endl;
	std::cout << "End iterator - 1: " << *(ite - 1) << std::endl;
	std::cout << std::endl;

	std::cout << "Iterating: [ ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "]" << std::endl;
	std::cout << std::endl;

	std::stack<int>	s(mstack);

	std::cout << "Stack size: " << s.size() << std::endl;
	std::cout << "Stack top:  " << s.top() << std::endl;

	return 0;
}
