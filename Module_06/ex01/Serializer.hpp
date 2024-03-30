/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:00:13 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:19:20 by ysabik           ###   ########.fr       */
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
	public:
		Serializer();
		Serializer(const Serializer &src);
		virtual ~Serializer() = 0;
		virtual Serializer	&operator=(const Serializer &rhs) = 0;

		static uintptr_t	*serialize(Data *data);
		static Data			*deserialize(uintptr_t *raw);
};

#endif
