/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:55:14 by eahn              #+#    #+#             */
/*   Updated: 2025/02/27 14:34:26 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form; // Forward declaration

class Bureaucrat 
{
	private:
		const std::string name;
		int grade;

	public:
		// OCF
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade); 
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Getter
		std::string const &getName() const;
		int getGrade() const;

		// Grade control
		void incrementGrade();
		void decrementGrade();

		// Sign form
		void signForm(Form& form);

		// Exeption classes (no need for OCF)
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

// Operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

# endif
