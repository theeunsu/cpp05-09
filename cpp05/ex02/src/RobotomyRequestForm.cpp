/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:19:01 by eahn              #+#    #+#             */
/*   Updated: 2025/02/24 00:34:58 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Default RobotomyRequestForm", 72, 45), target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // Call parent class copy assignment operator
		this->target = other.target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if(!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	// Randomly determine seed
	std::srand(std::time(0)); // determine seed based on current time

	std::cout << "Drilling noises..." << std::endl;

	if (std::rand() % 2 == 0)
	{
		std::cout << target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomization failed on " << target << "!" << std::endl;
	}
}
