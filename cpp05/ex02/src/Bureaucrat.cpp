/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:46:09 by eahn              #+#    #+#             */
/*   Updated: 2025/02/24 00:13:15 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

// OCF
Bureaucrat::Bureaucrat(void) : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getter
std::string const &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

// Grade control
void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade += 1;
}

// Exeption classes (no need for OCF)
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!\n";
}

// Sign form
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this); // Bureaucrat tries to sign the form
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what();
	}
	
}

// Operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
