/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:53:14 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 00:57:14 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
    Data myData = {"Bobo", 30};

	std::cout << "Original Data Address: " << &myData << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data Address: " << deserializedPtr << std::endl;

	if (deserializedPtr == &myData)
		std::cout << "Success! The deserialized pointer matches the original." << std::endl;
	else
		std::cout << "Error! The deserialized pointer does not match the original." << std::endl;
	
	std::cout << "Deserialized Data -> Name: " << deserializedPtr->name <<  ", Age: " << deserializedPtr->age << std::endl;

	return 0;
}
