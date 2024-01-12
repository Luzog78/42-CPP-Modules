/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:54:37 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 09:40:17 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(int const value) {
	this->_value = value << this->_bits;
}

Fixed::Fixed(float const value) {
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs) {
	this->_value = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator==(Fixed const &rhs) {
	return this->_value == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const &rhs) {
	return this->_value != rhs.getRawBits();
}

bool	Fixed::operator>(Fixed const &rhs) {
	return this->_value > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const &rhs) {
	return this->_value < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const &rhs) {
	return this->_value >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const &rhs) {
	return this->_value <= rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &rhs) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed	&Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	this->_value++;
	return tmp;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp (*this);
	this->_value--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	return (Fixed &) a < b ? a : b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	return (Fixed &) a > b ? a : b;
}

int		Fixed::getRawBits() const {
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int		Fixed::toInt() const {
	return this->_value >> this->_bits;
}

float	Fixed::toFloat() const {
	return (float) this->_value / (float) (1 << this->_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}
