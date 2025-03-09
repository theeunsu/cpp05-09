/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:20:06 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 23:27:33 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Identify.hpp"
#include "../inc/Generate.hpp"
#include <iostream> // std::cout std::endl

int main ()
{
	Base* obj = generate(); // generate random class between A, B, C

	std::cout << "Identifying using pointer: ";
	identify(obj); // identify using pointer

	std::cout << "Identifying using reference: ";
	identify(*obj); // identify using reference

	// std::cout << "Testing nullptr:" << std::endl;
    // identify(nullptr); // check nullptr

	delete obj; // delete dynamically allocated object
	return 0;
}
