/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:54:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/24 17:16:45 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	foo() {
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;

	std::cout << "Try to add '42' in a span" << std::endl;
	try {
		sp.addNumber(42);
	} catch (Span::SpanException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	bar() {
	Span	sp = Span(150);

	try {
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	} catch (Span::SpanException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::vector<int>	numbers = generateNumbers(30, 0, 1000);

	std::cout << ">> [ ";
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	
	sp.addNumber(numbers);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;
}

void	bazz() {
	Span	sp = Span(150);

	try {
		std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	} catch (Span::SpanException &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::vector<int>	numbers = generateNumbers(25, -10000, 10000);
	std::set<int>		unique_set(numbers.begin(), numbers.end());
	std::vector<int>	unique_vec(unique_set.begin(), unique_set.end());

	std::cout << ">> [ ";
	for (std::vector<int>::iterator it = unique_vec.begin(); it != unique_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	
	sp.addNumber(unique_vec);

	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;
}

void	quux(unsigned int count = 1000000, int min = INT_MIN, int max = INT_MAX) {
	Span				sp = Span(count);
	std::vector<int>	numbers = generateNumbers(count, min, max);

	sp.addNumber(numbers);

	std::cout << "Generated " << count << " numbers between " << min << " and " << max << std::endl;
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest:  " << sp.longestSpan() << std::endl;
}

int	main() {
	std::srand(std::time(0));

	foo();

	std::cout << std::endl << "---" << std::endl << std::endl;

	bar();

	std::cout << std::endl << "---" << std::endl << std::endl;

	bazz();

	std::cout << std::endl << "---" << std::endl << std::endl;

	quux(10000);
	std::cout << std::endl;
	quux(100000);
	std::cout << std::endl;
	quux(1000000);
	std::cout << std::endl;
	quux(10000000);

	return 0;
}
