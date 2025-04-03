/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:18:47 by eahn              #+#    #+#             */
/*   Updated: 2025/04/03 17:02:06 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream> // for std::istringstream
#include <stdexcept> // for std::runtime_error
#include <cctype> // for std::isdigit

class RPN
{
	public:
		RPN(); // Default constructor
		RPN(const RPN &other); // Copy constructor
		RPN &operator=(const RPN &other); // Copy Assignment operator
		~RPN(); // Destructor

		int evaluate(const std::string &expression);

	private:
		bool isOperator(char c) const;
		int applyOperation(int a, int b, char op) const;

};

#endif
