/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:08:29 by eahn              #+#    #+#             */
/*   Updated: 2025/02/23 22:47:42 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"


AForm::AForm() : name("Default AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), 
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

// Getter
std::string const &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

// Exception classes
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!\n";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed yet!\n";
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform)
{
	out << "AForm: " << Aform.getName() 
	<< ", Signed: " << (Aform.getIsSigned() ? "Yes" : "No") 
	<< ", Grade to sign: " << Aform.getGradeToSign() 
	<< ", Grade to execute: " << Aform.getGradeToExecute() << std::endl;
	return out;
}
