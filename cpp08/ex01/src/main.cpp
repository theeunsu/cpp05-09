/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:51:26 by eahn              #+#    #+#             */
/*   Updated: 2025/03/27 22:03:46 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Span.hpp"

int main()
{
	try
	{
		// Create a span with capacity of 5
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
		std::cout << "Longest span: " << sp.longestSpan() << std::endl; // 14

		// Try to add a number to a full span
		sp.addNumber(42); // should throw an exception
	}
	catch (const std::exception& e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n--- Mass Test ---" << std::endl;
	try
	{
		Span bigSpan(10000);
		for (int i = 0; i < 10000; i++)
			bigSpan.addNumber(i * 2); // even numbers: 0, 2, 4, 6, 8, ...
		
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl; // 2
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl; // 19998
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}

	std::cout << "\n--- Iterator Range Test ---" << std::endl;
	try
	{
		std::vector<int> numbers;
		for (int i = 100; i < 110; ++i)
			numbers.push_back(i);
		
		Span rangedSpan(10);
		rangedSpan.addNumber(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << rangedSpan.shortestSpan() << std::endl; // 1
		std::cout << "Longest span: " << rangedSpan.longestSpan() << std::endl; // 9
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Exception] " << e.what() << std::endl;
	}
	
	return 0;
}
