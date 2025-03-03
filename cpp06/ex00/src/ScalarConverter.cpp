/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:37:15 by eahn              #+#    #+#             */
/*   Updated: 2025/03/03 17:29:26 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

// consturctor & destructor (to prevent instantiation)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// Check if the string is a char
bool ScalarConverter::isChar(std::string const &str)
{
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

// Check if the string is an int
bool ScalarConverter::isInt(std::string const &str)
{
    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    for (; i < str.length(); i++)
    {
        if (!isdigit(str[i])) return false;
    }
    return !str.empty();
}

// Check if the string is a float
bool ScalarConverter::isFloat(std::string const &str)
{
    return str.back() == 'f' && isDouble(str.substr(0, str.length() - 1));
}

// Check if the string is a double
bool ScalarConverter::isDouble(const std::string &str)
{
    size_t i = (str[0] == '+' || str[0] == '-') ? 1 :0;
    bool hasDoc = false;
    
    
}