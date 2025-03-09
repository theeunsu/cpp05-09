/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:15:27 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 01:17:05 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib> // rand srand
#include <ctime> // time

Base* generate() 
{
	srand(time(NULL)); // random seed (each execution, different result)
	int random = rand() % 3; // random number between 0 and 2

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}
