/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:27:25 by eahn              #+#    #+#             */
/*   Updated: 2025/04/01 23:39:24 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main (int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./bitcoin [input file]" << std::endl;
		return 1;
	}

	try 
	{
		BitcoinExchange btc("data.csv"); // Load database
		btc.processInputFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
