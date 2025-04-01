/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:18:47 by eahn              #+#    #+#             */
/*   Updated: 2025/04/02 00:21:21 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RNP_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN
{
	private: 

	public:
		RPN(); // Default constructor
		RPN(const RPN &other); // Copy constructor
		RPN &operator=(const RPN &other); // Copy Assignment operator
		~RPN(); // Destructor)

};

#endif
