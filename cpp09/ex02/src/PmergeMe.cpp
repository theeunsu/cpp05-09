/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:27:49 by eahn              #+#    #+#             */
/*   Updated: 2025/04/03 18:28:47 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

// Copy assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vectorInput = other.vectorInput;
		this->dequeInput = other.dequeInput;
	}
	return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Parse input and store in vector and deque
void PmergeMe::validateAndStore(const std::string& str)
{
	char* end;
	long val = std::strtol(str.c_str(), &end, 10); // &end point to the first invalid character
	if (*end != '\0' || val < 0 || val > INT_MAX)
		throw std::runtime_error("Error: Invalid input value: " + str);
	vectorInput.push_back(static_cast<int>(val));
	dequeInput.push_back(static_cast<int>(val));
}

void PmergeMe::parseInput(int ac, char** av)
{
	if (ac < 2)
		throw std::runtime_error("Error: No input provided");
	for (int i = 1; i < ac; ++i)
		validateAndStore(av[i]);
}

void PmergeMe::run()
{
	printContainer(vectorInput, "Before");

	clock_t startVec = clock();
	fordJohnsonSort(vectorInput);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	fordJohnsonSort(dequeInput);
	clock_t endDeq = clock();

	printContainer(vectorInput, "After");

	std::cout << "Time to process a range of " << vectorInput.size()
			<< " elements with std::vector: "
			<< static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl; 
			// convert tick count to microseconds
	std::cout << "Time to process a range of " << dequeInput.size()
			<< " elements with std::deque: "
			<< static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;
}

template<typename Container>
void PmergeMe::printContainer(const Container& c, const std::string& label)
{
	std::cout << label << ": ";
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
