/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:55:36 by eahn              #+#    #+#             */
/*   Updated: 2025/03/11 22:13:08 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <typename T, typename Func> // T: type of array, Func: function or function object
void iter (T *array, size_t length, Func func)
{
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]); // for each element in array, apply func
	}
}


#endif
