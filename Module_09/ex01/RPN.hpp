/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:04:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/27 13:33:04 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
	private:
		std::stack<double>	stack;

		bool	pushSign(char c);

	public:
		RPN();
		RPN(const RPN &src);
		~RPN();
		RPN	&operator=(const RPN &rhs);

		bool	exec(std::string &str);
};

#endif
