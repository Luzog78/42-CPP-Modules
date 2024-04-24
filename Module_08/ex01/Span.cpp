/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:59:51 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/11 01:55:44 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int max) : max(max) {
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {
}

Span	&Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		max = rhs.max;
		nums = rhs.nums;
	}
	return *this;
}

void	Span::addNumber(int number) {
	if (nums.size() >= max)
		throw Span::SpanFullException();
	nums.push_back(number);
}

void	Span::addNumber(std::vector<int> &numbers) {
	if (nums.size() + numbers.size() > max)
		throw Span::SpanFullException();
	nums.insert(nums.end(), numbers.begin(), numbers.end());
}

int	Span::shortestSpan() {
	if (nums.size() < 2)
		throw Span::SpanTooSmallException();

	std::vector<int>	tmp = nums;
	std::sort(tmp.begin(), tmp.end());

	int	min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++) {
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

int	Span::longestSpan() {
	if (nums.size() < 2)
		throw Span::SpanTooSmallException();

	std::vector<int>	tmp = nums;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

const char	*Span::SpanFullException::what() const throw() {
	return "Span is full!";
}

const char	*Span::SpanTooSmallException::what() const throw() {
	return "Span is too small!";
}

std::vector<int>	generateNumbers(unsigned int count, int min, int max) {
	long long	mmin = min;
	long long	mmax = max;
	std::vector<int>	nums(count);

	for (unsigned int i = 0; i < count; i++)
		nums[i] = (int) ((long long) std::rand() % (mmax - mmin + 1) + mmin);
	
	return nums;
}
