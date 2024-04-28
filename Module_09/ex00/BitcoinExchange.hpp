/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:39:34 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/27 12:06:28 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <algorithm>

class BitcoinExchange {
	private:
		std::map<std::string, double>	rates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

		bool		parseRates(std::string file);
		void		parseRateLine(std::string line);

		double		getRate(std::string at) const;
		std::string	getNearestRate(std::string at) const;

		bool		parseRecords(std::string file);
		void		parseRecordLine(std::string line);
};

std::string	getFileContent(std::string filename);
bool		isDate(std::string date);
bool		isDouble(std::string rate);
int			compDates(std::string date1, std::string date2);

#endif
