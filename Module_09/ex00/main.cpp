/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:39:31 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/27 12:52:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./btc filename" << std::endl;
		return 1;
	}

	BitcoinExchange	exchange;
	if (!exchange.parseRates("data.csv")
		|| !exchange.parseRecords(av[1]))
		return 1;

	return 0;
}
