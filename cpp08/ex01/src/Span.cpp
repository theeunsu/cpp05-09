/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:37:37 by eahn              #+#    #+#             */
/*   Updated: 2025/03/27 21:50:15 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

// Default constructor
Span::Span() : _maxSize() {}

// Constructor with max size
Span::Span(unsigned int N) : _maxSize(N) {}

// Copy constructor
Span::Span(const Span& other)
{
	*this = other;
}

// Copy assignment operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

// Destructor
Span::~Span() {}


// Add a single number to the container
void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	
	std::vector<int> temp = _numbers; // Make a copy to sort
	std::sort(temp.begin(), temp.end());

	int minSpan = temp[1] - temp[0];
	for (size_t i = 2; i < temp.size(); ++i)
	{
		int span = temp[i] - temp[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return maxVal - minVal;
}
