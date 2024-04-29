/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:00:13 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/29 05:40:59 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data {
	bool	foo;
	char	bar;
	int		baz;
	double	quux;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer	&operator=(const Serializer &rhs);

	public:
		static uintptr_t	serialize(Data *data);
		static Data			*deserialize(uintptr_t raw);
};

#endif
