/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:03:59 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/29 05:30:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &src) {
	(void) src;
}

uintptr_t	Serializer::serialize(Data *data) {
	return reinterpret_cast<uintptr_t>(data);
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
