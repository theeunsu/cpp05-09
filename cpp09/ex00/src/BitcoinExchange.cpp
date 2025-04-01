/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:27:22 by eahn              #+#    #+#             */
/*   Updated: 2025/04/02 00:10:52 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_exchangeRates = other._exchangeRates;
}

// Copy Assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_exchangeRates = other._exchangeRates;
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Costum Constructor (loads DB)
BitcoinExchange::BitcoinExchange(const std::string& dbFilename)
{
	loadDatabase(dbFilename);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename); // C++11
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line; // ex: "2025-03-28, 1234.56"
	std::getline(file, line); // Skip header line

	while (std::getline(file, line))
	{
		std::stringstream ss(line); 
		std::string date, rateStr;

		if (!std::getline(ss, date, ',')) continue; // date = "2025-03-28"
		if (!std::getline(ss, rateStr)) continue; // rateStr = "1234.56"

		try
		{
			float rate = std::stof(rateStr); // C++11 string to float
			_exchangeRates[trim(date)] = rate; // key: "2025-03-28", value: 1234.56
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: invalid rate format in line => " << line << std::endl;
		}
	}
}

void BitcoinExchange::processInputFile(const std::string& inputFilename) const
{
	std::ifstream file(inputFilename); 
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return;
	}

	std::string line;
	bool hasValidLine = false;

	// skip header line
	if (!std::getline(file, line))
	{
		std::cerr << "Error: empty input file." << std::endl;
		return;
	}

	while (std::getline(file, line))
	{
		// skip empty lines
		if (trim(line).empty())
			continue;
		
		std::stringstream ss(line);
		std::string datePart, valuePart;

		// split "date | value"
		if (!std::getline(ss, datePart, '|') || !std::getline(ss, valuePart))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(datePart);
		std::string valueStr = trim(valuePart);

		// check date format
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		// check value formait + convert to float
		float value = 0.0f;
		if (!isValidValue(valueStr, value))
		{
			continue; // error message printed in isValidValue
		}

		// lower_bound(date): find first element whose key is equal or greater
		auto it = _exchangeRates.lower_bound(date); // auto : c++11 (=std::map<std::string, float>::iterator)
		if (it == _exchangeRates.end() || it->first != date)
		{
			if (it == _exchangeRates.begin())
			{
				std::cerr << "Error: no earlier date found in DB for => " << date << std::endl;
				continue;
			}
			--it; // use the closest lower (earlier) date
		}

		float rate = it->second;
		float result = rate * value;

		std::cout << date << " => " << value << " = " << result << std::endl;
		hasValidLine = true;
	}
	if (!hasValidLine)
		std::cerr << "Error: no valid line found in input file." << std::endl;
	file.close();
}

std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos) // no position found
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}

	try 
	{
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31 )
			return false;
		
		static const int daysInMonth[12] =
		{
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};

		// for leap year
		if (month == 2)
		{
			bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
			if (day > (isLeapYear ? 29 : 28))
				return false;
		}
		else 
		{
			if (day > daysInMonth[month - 1])
				return false;
		}
		return true;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error: invalid date format => " << date 
				<< " ("<< e.what() << ")" << std::endl;
		return false;
	}
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float& value) const
{
	try
	{
		value = std::stof(valueStr);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: bad value => " << valueStr
				<< " (" << e.what() << ")" << std::endl;
		return false;
	}

	if (value < 0.0f)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	if (value > 1000.0f)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

/*
/ Example of input file:
/_ExchangeRates = {
    "2011-01-01" → 0.25,
    "2011-01-03" → 0.30,
    "2011-01-09" → 0.32,
|
*/
