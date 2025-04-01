/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:27:27 by eahn              #+#    #+#             */
/*   Updated: 2025/04/01 16:57:00 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string> // std::string
#include <fstream> // std::ifstream
#include <sstream> // std::stringstream
#include <map> // std::map

class BitcoinExchange
{
	public:
		// Orthodox Canonical Form
		BitcoinExchange(); // Default constructor
		BitcoinExchange(const BitcoinExchange &other); // Copy constructor
		BitcoinExchange &operator=(const BitcoinExchange &other); // Copy Assignment operator
		~BitcoinExchange(); // Destructor

		// Custom constructor
		BitcoinExchange(const std::string& dbFilename);

		// Main logic
		void processInputFile(const std::string& inputFilename) const;

	private:
		std::map<std::string, float> _exchangeRates;

		// Utility functions (private)
		void loadDatabase(const std::string& filename);
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string &valueStr, float& value) const;
		std::string trim(const std::string& str) const;
};

#endif
