/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:20:06 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 01:23:12 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/identify.hpp"
#include "../inc/generate.hpp"
#include <iostream> // std::cout std::endl

int main ()
{
	Base* obj = generate(); // generate random class between A, B, C

	std::cout << "Identifying using pointer: ";
	identify(obj); // identify using pointer

	std::cout << "Identifying using reference: ";
	identify(*obj); // identify using reference

	delete obj; // delete dynamically allocated object
	return 0;
}
