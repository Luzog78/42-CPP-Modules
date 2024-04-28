/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:03:56 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/28 15:09:11 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {
}

RPN	&RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		stack = rhs.stack;
	}
	return *this;
}

bool	RPN::exec(std::string &str) {
	stack = std::stack<double>();
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue ;
		if (str[i] >= '0' && str[i] <= '9') {
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				return false;
			stack.push(str[i] - '0');
		} else if (str[i] == '+' || str[i] == '-'
			|| str[i] == '*' || str[i] == '/') {
			if (!pushSign(str[i]))
				return false;
		} else
			return false;
	}

	if (stack.size() != 1)
		return false;

	std::cout << stack.top() << std::endl;
	return true;
}

bool	RPN::pushSign(char c) {
	if (stack.size() < 2)
		return false;

	double	a = stack.top();
	stack.pop();
	double	b = stack.top();
	stack.pop();

	if (c == '+')
		stack.push(b + a);
	else if (c == '-')
		stack.push(b - a);
	else if (c == '*')
		stack.push(b * a);
	else if (c == '/') {
		if (a == 0)
			return false;
		stack.push(b / a);
	}
	return true;
}
