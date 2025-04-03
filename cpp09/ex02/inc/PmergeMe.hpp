/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:27:51 by eahn              #+#    #+#             */
/*   Updated: 2025/04/03 17:35:08 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector> // std::vector
#include <deque> // std::deque
#include <iostream> 
#include <string> // std::string
#include <stdexcept> // std::runtime_error
#include <sstream> // std::istringstream
#include <ctime> // std::clock
#include <cstdlib> // std::atoi()
#include <climits> // INT_MAX

class PmergeMe
{
	public:
		PmergeMe(); // Default constructor
		PmergeMe(const PmergeMe &other); // Copy constructor
		PmergeMe &operator=(const PmergeMe &other); // Copy Assignment operator
		~PmergeMe(); // Destructor

		void parseInput (int ac, char **av);
		void run();

	private:
		std::vector<int> vectorInput;
		std::deque<int> dequeInput;

		void validateAndStore(const std::string& str);
		void fordJohnsonSort(std::vector<int>& vec);
		void fordJohnsonSort(std::deque<int>& deq);

		template<typename Container>
		void printContainer(const Container& c, const std::string& label);
};

#endif
