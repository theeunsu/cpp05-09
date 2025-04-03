/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:27:49 by eahn              #+#    #+#             */
/*   Updated: 2025/04/03 23:32:26 by eahn             ###   ########.fr       */
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

// Ford-Johnson sort implementation using std::vector
void PmergeMe::fordJohnsonSort(std::vector<int>& vec)
{
	if (vec.size() <= 1) // already sorted if size is 1 or 0
		return;
	
	std::vector<std::pair<int, int>> pairs; // to store pairs (a, b) with a <= b
	int i = 0;
	while (i + 1 < static_cast<int>(vec.size()))
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b)); // store the pair
		++i;
		++i; // move to the next pair
	}
	if (i < static_cast<int>(vec.size())) // if there's an odd element left
	{
		pairs.push_back(std::make_pair(vec[i], -1)); // leftover element with dummy value(-1)
	}	

	std::vector<int> mainChain;
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (pairs[j].second != -1) // ignore leftover
			mainChain.push_back(pairs[j].second); // collect larger values (second one)
	}

	fordJohnsonSort(mainChain); // recursively sort the larger values first

	for (size_t j = 0; j < pairs.size(); ++j)
	{
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), pairs[j].first), pairs[j].first);
		// insert(position, value)
	}
	vec = mainChain; // update the original vector
}

// Ford-Johnson sort implementation using std::deque
void PmergeMe::fordJohnsonSort(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;
	
	std::deque<std::pair<int, int>> pairs; 
	int i = 0;
	while (i + 1 < static_cast<int>(deq.size()))
	{
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		++i;
		++i;
	}
	if (i < static_cast<int>(deq.size()))
	{
		pairs.push_back(std::make_pair(deq[i], -1)); // leftover element with dummy value(-1)
	}

	std::deque<int> mainChain;
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (pairs[j].second != -1) // ignore leftover
			mainChain.push_back(pairs[j].second);
	}

	fordJohnsonSort(mainChain); // recursively sort the larger values first

	for (size_t j = 0; j < pairs.size(); ++j)
	{
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), pairs[j].first), pairs[j].first);
	}

	deq = mainChain; // update the original deque
}
