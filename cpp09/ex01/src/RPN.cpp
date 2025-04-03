/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:19:53 by eahn              #+#    #+#             */
/*   Updated: 2025/04/03 15:49:33 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

// Default constructor
RPN::RPN() {}

// Copy constructor
RPN::RPN(const RPN &other)
{
	(void)other;
}

// Copy assignment operator
RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

// Destructor
RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperation(int a, int b, char op) const
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			return a / b;
		default:
			throw std::runtime_error("Error: Invalid operator");
	}
}

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression); 
	std::string token;

	while (iss >> token) // parse expression by whitespace
	{
		if (token.length() == 1 && isOperator(token[0])) // if operator
		{
			if (stack.size() < 2) // check if there are 2 numbers to operate on
				throw std::runtime_error("Error: Not enough operands");
			int b = stack.top(); stack.pop(); // Last In First Out
			int a = stack.top(); stack.pop();
			int result = applyOperation(a, b, token[0]);
			stack.push(result);
		}
		else if (token.length() == 1 && std::isdigit(token[0]))
		{
			stack.push(token[0] - '0'); // convert char to int
		}
		else
		{
			throw std::runtime_error("Error: Invalid token");
		}
	}
	if (stack.size() != 1) // check if there is only one result left
		throw std::runtime_error("Error: Invalid expression");

	return stack.top();
}
