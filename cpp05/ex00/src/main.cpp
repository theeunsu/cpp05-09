/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:11:16 by eahn              #+#    #+#             */
/*   Updated: 2025/02/27 14:31:57 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main () 
{
	std::cout << "\n==== Bureaucrat Creation Test ====" << std::endl;

	try
	{
		std::cout << "Creating Bob with grade 2..."	<< std::endl;
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		std::cout << "Incrementing Bob's grade (should be 1)..." << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;

		std::cout << "Incrementing Bob's grade again (should throw exception)..." << std::endl;
		bob.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}


	std::cout << "\n=== Invalid Bureaucrat Test ===" << std::endl;

	try 
	{
		std::cout << "Creating Nana with grade 0 (should throw exception)..." << std::endl;
		Bureaucrat Bob("Nana", 0);
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Creating Haha with grade 151 (should throw exception)..." << std::endl;
		Bureaucrat Haha("Haha", 151);
	} catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
