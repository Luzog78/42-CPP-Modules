/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:58:51 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/29 14:09:34 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *array, size_t size, void (*f)(const T &)) {
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	iter(T *array, size_t size, void (*f)(T &)) {
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif
