/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:18:25 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 06:40:05 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array {
	private:
		T		*array;
		size_t	_size;

	public:
		Array() : array(0), _size(0) {
		}

		Array(size_t n) : array(new T[n]), _size(n) {
			for (size_t i = 0; i < _size; i++)
				array[i] = T();
		}

		Array(Array const &src) {
			*this = src;
		}
		
		~Array() {
			delete[] array;
		}

		Array	&operator=(Array const &src) {
			if (this != &src) {
				delete[] array;
				_size = src._size;
				array = new T[_size];
				for (size_t i = 0; i < _size; i++)
					array[i] = src.array[i];
			}
			return *this;
		}

		T		&operator[](size_t i) {
			if (i >= _size)
				throw std::out_of_range("Index out of bounds");
			return array[i];
		}

		size_t	size() const {
			return _size;
		}
};

#endif
