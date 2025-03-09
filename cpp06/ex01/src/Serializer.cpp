/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:24:11 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 23:08:15 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}


// OCF (Not used for utility class)
Serializer::Serializer() {} // private constructor: cannot be instantiated
Serializer::Serializer(const Serializer&) {} // no need to put other cause it won't be used
Serializer& Serializer::operator=(const Serializer&) { return *this; } // no need to put other cause it won't be used
Serializer::~Serializer() {} // destructor

// reinterpret_cast is used to convert a pointer into an integer type or vice versa
