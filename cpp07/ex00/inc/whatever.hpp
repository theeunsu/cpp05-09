/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:43:07 by eahn              #+#    #+#             */
/*   Updated: 2025/03/11 21:47:53 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream> // std::cout std::endl

// function Swap
template <typename T> // generic type
void swap (T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// function Min
template <typename T>
T min (const T &a, const T &b)
{
	return (a < b) ? a : b;
}

// function Max
template <typename T>
T max (const T &a, const T &b)
{
	return (a > b) ? a : b;
}

#endif


// in C each type needs to have its own function 
// ex: swap_int(int *a, int *b), swap_float(float *a, float *b)...
