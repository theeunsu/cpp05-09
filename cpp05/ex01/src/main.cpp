/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:11:16 by eahn              #+#    #+#             */
/*   Updated: 2025/02/23 23:11:49 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main ()
{
	std::cout << "=== Bureaucrat and Form Test ===" << std::endl;

	Bureaucrat bob("Bob", 50);
	Bureaucrat nana("Nana", 150);

	Form taxForm("Tax Form", 100, 50);
	Form reportForm("Report Form", 40, 20);

	std::cout << "\n[ Before Signing ]" << std::endl;
	std::cout << taxForm;
	std::cout << reportForm;

	std::cout << "\n[ Bob tries to sign forms ]" << std::endl;
	bob.signForm(taxForm); // Bob(50) > Tax Form(100) -> success
	bob.signForm(reportForm); // Bob(50) > Report Form(40) -> fail

	std::cout << "\n[ Nana tries to sign forms ]" << std::endl;
	nana.signForm(taxForm); // Nana(150) > Tax Form(100) -> fail
	nana.signForm(reportForm); // Nana(150) > Report Form(40) -> fail

	std::cout << "\n[ After Signing ]" << std::endl;
	std::cout << taxForm;
	std::cout << reportForm;

	std::cout << "\n[ Testing invalid form creation ]" << std::endl;
	{
		try 
		{
			Form f("Invalid Form", 0, 50); // GradeTooHighException
			std::cout << f << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception caught: " << e.what();
		}
		try
		{
			Form f("Invalid Form", 100, 200); // GradeTooHighException
			std::cout << f << std::endl;
		} catch(const std::exception& e)
		{
			std::cout << "Exception caught: " << e.what();
		}		
	}
	return 0;
}
