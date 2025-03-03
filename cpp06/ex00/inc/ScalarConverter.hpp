/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:25:51 by eahn              #+#    #+#             */
/*   Updated: 2025/03/03 12:38:23 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream> // std::cout, std::endl
#include <cstdlib> // stoi, stof, stod, strtod...
#include <cmath> // modf, isnan, isinf..
#include <iomanip> // std::setprecision(n), std::fixed..
#include <limits> // max, min.. 

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    EXCEPTION
};

class ScalarConverter
{
    private:
        // Check Type Function
        static bool isChar(std::string const &str);
        static bool isInt(std::string const &str);
        static bool isFloat(std::string const &str);
        static bool isDouble(std::string const &str);
        static Type checkType(std::string const &str);

        // Convert Function
        static void handleChar(std::string const &str);
        static void handleInt(std::string const &str);
        static void handleFloat(std::string const &str);
        static void handleDouble(std::string const &str);
        static void handleSpecialLiterals(std::string const &str);
        static void handleException();
        
        ScalarConverter(); // private constructor: cannot be instantiated
        ScalarConverter(ScalarConverter const &other); // copy constructor
        ScalarConverter &operator=(ScalarConverter const &other); // copy assignment operator
        ~ScalarConverter(); // destructor
    
    public:
        static void convert(std::string const &str);
};

#endif