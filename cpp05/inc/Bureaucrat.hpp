/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:35:41 by eahn              #+#    #+#             */
/*   Updated: 2025/02/20 15:51:55 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <stdexcept>

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
		std::string getName() const;
		int getGrade() const;

		// Grade control
		void incrementGrade();
		void decrementGrade();

		// Exeption classes (no need for OCF)
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLawException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif