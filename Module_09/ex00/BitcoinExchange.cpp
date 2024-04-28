/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:39:43 by ysabik            #+#    #+#             */
/*   Updated: 2024/04/27 12:54:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		rates = rhs.rates;
	}
	return *this;
}

bool	BitcoinExchange::parseRates(std::string file) {
	std::string	content = getFileContent(file);
	if (content.empty())
		return false;

	std::stringstream	ss(content);
	std::string			line;
	while (std::getline(ss, line, '\n')) {
		parseRateLine(line);
	}
	return true;
}

void	BitcoinExchange::parseRateLine(std::string line) {
	if (std::count(line.begin(), line.end(), ',') != 1)
		return ;

	std::string	date = line.substr(0, line.find(','));
	std::string	rate = line.substr(line.find(',') + 1);

	if (!isDate(date) || !isDouble(rate))
		return ;

	rates[date] = std::strtod(rate.c_str(), NULL);
}

double	BitcoinExchange::getRate(std::string at) const {
	std::string	nearest = getNearestRate(at);
	if (nearest.empty())
		return 0;
	return rates.at(nearest);
}

std::string	BitcoinExchange::getNearestRate(std::string at) const {
	if (rates.find(at) != rates.end())
		return at;

	std::string	nearest = "";
	for (std::map<std::string, double>::const_iterator it = rates.begin(); it != rates.end(); it++) {
		if (compDates(it->first, at) == -1
			&& (nearest.empty() || compDates(it->first, nearest) == 1))
			nearest = it->first;
	}
	return nearest;
}

bool	BitcoinExchange::parseRecords(std::string file) {
	std::string	content = getFileContent(file);
	if (content.empty())
		return false;

	std::stringstream	ss(content);
	std::string			line;
	while (std::getline(ss, line, '\n')) {
		parseRecordLine(line);
	}
	return true;
}

static bool	_isRecordValid(std::string line) {
	if (line.length() < 4 || std::count(line.begin(), line.end(), '|') != 1
		|| std::count(line.begin(), line.end(), ' ') != 2
		|| line.find_first_of(' ') != line.find('|') - 1
		|| line.find_last_of(' ') != line.find('|') + 1)
		return false;
	return true;
}

void	BitcoinExchange::parseRecordLine(std::string line) {
	if (line.empty() || line == "date | value")
		return;
	if (!_isRecordValid(line)) {
		std::cerr << "Error: Invalid record => " << line << std::endl;
		return;
	}

	std::string	date = line.substr(0, line.find('|') - 1);
	std::string	amount = line.substr(line.find('|') + 2);

	if (!isDate(date)) {
		if (date.empty())
			std::cerr << "Error: Empty date => " << line << std::endl;
		else
			std::cerr << "Error: Invalid date => " << date << std::endl;
		return;
	} else if (!isDouble(amount)) {
		if (amount.empty())
			std::cerr << "Error: Empty value => " << line << std::endl;
		else
			std::cerr << "Error: Invalid value => " << amount << std::endl;
		return;
	}

	double btc = std::strtod(amount.c_str(), NULL);
	if (errno == ERANGE || btc > 1000.0) {
		if (amount[0] == '-')
			std::cerr << "Error: Negative value => " << amount << std::endl;
		else
			std::cerr << "Error: Value too large => " << amount << std::endl;
		errno = 0;
		return;
	} else if (btc < 0) {
		std::cerr << "Error: Negative value => " << btc << std::endl;
		return;
	}

	long double	value = btc * this->getRate(date);
	std::cout << date << " => " << btc << " = " << value << std::endl;
}

std::string	getFileContent(std::string filename) {
	if (filename.empty()) {
		std::cerr << "Error: Filename is empty" << std::endl;
		return "";
	}

	if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".csv") {
		std::cerr << "Error: Filetype is not CSV: " << filename << std::endl;
		return "";
	}

	std::ifstream	ifs(filename.c_str());
	if (!ifs || !ifs.is_open()) {
		std::cerr << "Error: Can't open file: " << filename << std::endl;
		return "";
	}

	std::string		content;
	std::getline(ifs, content, '\0');
	if (content.empty()) {
		std::cerr << "Error: Empty file: " << filename << std::endl;
		return "";
	}

	ifs.close();
	return content;
}

static int	_stoi(std::string s) {
	if (s.empty())
		return 0;

	int	i;
	std::istringstream(s) >> i;
	return i;
}

bool	isDate(std::string date) {
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string	data = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);

	for (std::string::iterator it = data.begin(); it != data.end(); it++) {
		if (!std::isdigit(*it))
			return false;
	}

	int		year = _stoi(date.substr(0, 4));
	int		month = _stoi(date.substr(5, 2));
	int		day = _stoi(date.substr(8, 2));
	bool	leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	int		daysInMonth[] = {31, leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

bool	isDouble(std::string rate) {
	if (rate.empty())
		return false;

	if (rate == "nan" || rate == "+inf" || rate == "-inf")
		return true;

	if (rate[0] == '+' || rate[0] == '-')
		rate = rate.substr(1);

	if (rate.empty())
		return false;

	for (std::string::iterator it = rate.begin(); it != rate.end(); it++) {
		if (!std::isdigit(*it) && *it != '.')
			return false;
	}

	return std::count(rate.begin(), rate.end(), '.') <= 1;
}

static int	_comp(int a, int b) {
	return a < b ? -1 : a > b;
}


/**
 * @brief Compare two dates
 * 
 * @param date1 First date
 * @param date2 Second date
 * 
 * @return `date1 < date2`: `-1` || `date1 == date2`: `0` || `date1 > date2`: `1`
 */
int		compDates(std::string date1, std::string date2) {
	if (!isDate(date1) || !isDate(date2))
		return 0;

	std::string	year1 = date1.substr(0, 4);
	std::string	year2 = date2.substr(0, 4);
	if (year1 != year2)
		return _comp(_stoi(year1), _stoi(year2));

	std::string	month1 = date1.substr(5, 2);
	std::string	month2 = date2.substr(5, 2);
	if (month1 != month2)
		return _comp(_stoi(month1), _stoi(month2));

	std::string	day1 = date1.substr(8, 2);
	std::string	day2 = date2.substr(8, 2);
	if (day1 != day2)
		return _comp(_stoi(day1), _stoi(day2));
	
	return 0;
}
