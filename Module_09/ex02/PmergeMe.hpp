/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:45:54 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/28 19:39:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <cerrno>
# include <cmath>
# include <ctime>

# define RESET		std::string("\033[00m")
# define DIM		std::string("\033[02m")
# define RED		std::string("\033[31m")
# define GREEN		std::string("\033[32m")
# define YELLOW		std::string("\033[33m")
# define MAGENTA	std::string("\033[35m")
# define CYAN		std::string("\033[36m")

typedef unsigned long long	ull;

class Pair {
	public:
		int	min;
		int	max;

		Pair();
		Pair(int min, int max);
		Pair(const Pair &src);
		~Pair();
		Pair	&operator=(const Pair &rhs);
		bool	operator==(const Pair &other);
};

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &rhs);

		static std::vector<int>	parse(int ac, char **av);

		template <typename Container, typename PairContainer>
		static Container		sort(Container &list, PairContainer ppairs);

		template <typename PairContainer>
		static Pair		findPairFromMax(PairContainer &pairs, int max);
		static size_t	jacobsthal(int n);
		template <typename Container>
		static int		binarySearch(Container &list, int target, int left, int right);
};

template <typename T, typename S>
int	posOf(S &container, T elem);

#endif
