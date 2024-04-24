/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:54:55 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/24 18:23:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack &src) : std::stack<T, Container>(src) {}
		~MutantStack() {}
		MutantStack	&operator=(const MutantStack &rhs) {
			if (this != &rhs)
				std::stack<T, Container>::operator=(rhs);
			return *this;
		}

		typedef typename Container::iterator iterator;

		iterator	begin() {
			return this->c.begin();
		}

		iterator	end() {
			return this->c.end();
		}
};

#endif
