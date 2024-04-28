/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:39:31 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/28 17:13:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::clock_t	chrono;

void	resetTime() {
	chrono = std::clock();
}

ull	getTime() {
	return std::clock() - chrono;
}

void	printTime(size_t range, std::string type, ull time) {
	std::cout	<< "Time to process a range of " << YELLOW << range << RESET
				<< " elements with " << MAGENTA << type << RESET
				<< " : " << CYAN;
	if (time < 1000)
		std::cout	<< std::setw(10) << time << " µs";
	else if (time < 1000000)
		std::cout	<< std::setw(10) << std::setprecision(3) << std::fixed
					<< time / (long double) 1000 << " ms";
	else
		std::cout	<< std::setw(10) << std::setprecision(6) << std::fixed
					<< time / (long double) 1000000 << " s";
	std::cout	<< RESET << std::endl;
}

template <typename T>
void	printContainer(std::string message, T container) {
	std::cout << message;
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
	std::cout << RESET << std::endl;
}

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ./PmergeMe numbers..." << std::endl;
		return 1;
	}

	std::vector<int>	numbers = PmergeMe::parse(ac, av);
	std::deque<int>		numbersDeque = std::deque<int>(numbers.begin(), numbers.end());
	size_t				size = numbers.size();

	if (size == 0)
		return 1;


	printContainer("Before ............... : " + RED, numbers);
	std::cout << std::endl;

	resetTime();
	std::vector<int>	sortedVec = PmergeMe::sort(numbers, std::vector<Pair>());
	ull					timeToProcessVecor = getTime();

	printContainer("After with " + MAGENTA + "std::vector" + RESET + " : " + GREEN, sortedVec);

	resetTime();
	std::deque<int>		sortedDeq = PmergeMe::sort(numbersDeque, std::deque<Pair>());
	ull					timeToProcessDeque = getTime();


	printContainer("After with " + MAGENTA + "std::deque " + RESET + " : " + GREEN, sortedDeq);
	std::cout << std::endl;

	printTime(size, "std::vector", timeToProcessVecor);
	printTime(size, "std::deque ", timeToProcessDeque);

	return 0;
}
