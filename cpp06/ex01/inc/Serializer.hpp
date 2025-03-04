/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:16:09 by eahn              #+#    #+#             */
/*   Updated: 2025/03/05 00:21:15 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint> // unitptr_t

class Serializer
{
	private:
		Serializer(); // private constructor: cannot be instantiated -> utility class
		Serializer(const Serializer&); // no need to put other cause it won't be used
		Serializer& operator=(const Serializer&); // no need to put other cause it won't be used
		~Serializer(); // destructor
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif
