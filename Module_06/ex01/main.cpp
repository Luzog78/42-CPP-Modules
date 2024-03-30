/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:21:30 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:10:01 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {

	Data	data = {true, 'a', 42, 42.42};

	std::cout << "Data: (" << &data << ")" << std::endl;
	std::cout << "  foo: " << data.foo << std::endl;
	std::cout << "  bar: " << data.bar << std::endl;
	std::cout << "  baz: " << data.baz << std::endl;
	std::cout << "  quux: " << data.quux << std::endl;
	std::cout << std::endl;

	uintptr_t	*raw = Serializer::serialize(&data);

	std::cout << "Raw: " << raw << std::endl;
	std::cout << std::endl;

	Data		*newData = Serializer::deserialize(raw);

	std::cout << "newData:" << std::endl;
	std::cout << "  foo: " << newData->foo << std::endl;
	std::cout << "  bar: " << newData->bar << std::endl;
	std::cout << "  baz: " << newData->baz << std::endl;
	std::cout << "  quux: " << newData->quux << std::endl;

	return 0;
}
