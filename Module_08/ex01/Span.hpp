/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:55:31 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/11 01:52:52 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <iostream>
# include <vector>
# include <algorithm>
# include <ctime>
# include <cstdlib>
# include <set>

class Span {
	private:
		unsigned int		max;
		std::vector<int>	nums;
	
	public:
		Span(unsigned int max);
		Span(const Span &src);
		~Span();
		Span	&operator=(const Span &rhs);

		void	addNumber(int number);
		void	addNumber(std::vector<int> &numbers);
		int		shortestSpan();
		int		longestSpan();

		class SpanException : public std::exception {
		};

		class SpanFullException : public SpanException {
			public:
				virtual const char	*what() const throw();
		};

		class SpanTooSmallException : public SpanException {
			public:
				virtual const char	*what() const throw();
		};
};

std::vector<int>	generateNumbers(unsigned int count, int min, int max);

#endif
