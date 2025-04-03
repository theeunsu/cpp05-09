/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:28:02 by eahn              #+#    #+#             */
/*   Updated: 2025/04/03 23:35:18 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main (int ac, char **av)
{
	try
	{
		PmergeMe sorter;
		sorter.parseInput(ac, av);
		sorter.run();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;	
}


// Notes on performance comparison:
// - std::vector uses contiguous memory, leading to better cache locality.
//   → This generally results in faster performance with large datasets.
// - std::deque uses a segmented memory model (multiple small blocks),
//   which reduces cache efficiency as data size grows.
// - For small input sizes, deque can be slightly faster due to efficient block-based insertion.
// - However, with large data (e.g. 3000+ elements), vector consistently outperforms deque.
