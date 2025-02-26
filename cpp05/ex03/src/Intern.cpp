/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:38:28 by eahn              #+#    #+#             */
/*   Updated: 2025/02/26 23:54:51 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other; // Since Intern has no member variables, this is empty
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other; // Since Intern has no member variables, this is empty
	return *this;
}

Intern::~Intern() {}

//makeForm() function
AForm* Intern::makeForm (const std::string& formName, const std::string& target)
{
	AForm* ret = nullptr;

	std::string formList[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int formIdx = -1;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formList[i])
		{
			formIdx = i;
			break ;
		}
	}

	switch (formIdx)
	{
		case 0:
			std::cout << "* Intern creates " << formName << std::endl;
			ret = new ShrubberyCreationForm(target);
			break ;
		case 1:
			std::cout << "* Intern creates " << formName << std::endl;
			ret = new RobotomyRequestForm(target);
			break ;
		case 2:
			std::cout << "* Intern creates " << formName << std::endl;
			ret = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << "* Intern could not creat form: '" << formName << "' does not exist." << std::endl;
			break ;
	}
	return ret;
}
