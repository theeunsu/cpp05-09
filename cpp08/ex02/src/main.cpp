/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:12:22 by eahn              #+#    #+#             */
/*   Updated: 2025/03/27 22:33:14 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "--- MutantStack ---" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	std::cout << "Iterating through MutantStack: " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	for (; it != ite; ++it)
		std::cout << *it << std::endl;

	std::cout << "\n--- Comparison with std::list ---" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	std::cout << "Iterating through std::list: " << std::endl;
	for (; lit != lite; ++lit)
		std::cout << *lit << std::endl;

	return 0;
}
