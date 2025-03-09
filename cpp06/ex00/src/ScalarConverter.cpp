/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:37:15 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 23:03:19 by eahn             ###   ########.fr       */
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
    return (str.length() == 1 && isprint(str[0]) && !std::isdigit(str[0]));
}

// Check if the string is an int
bool ScalarConverter::isInt(std::string const &str)
{
    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++)
    {
        if (!isdigit(str[i])) return false;
    }
    return true;
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
    bool hasDot = false;

    if (str == "-inf" || str == "+inf" || str == "nan") return true; // special literals

    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (hasDot) // more than one dot
                return false;
            hasDot = true;
        }
        else if (!isdigit(str[i]))
            return false;
    }
    
    return hasDot;
}

Type ScalarConverter::checkType(std::string const &str)
{
    if (isChar(str))
        return CHAR;
    else if (isInt(str))
        return INT;
    else if (isFloat(str))
        return FLOAT;
    else if (isDouble(str))
        return DOUBLE;
    return EXCEPTION;
}

void ScalarConverter::handleSpecialLiterals(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl; // 🔥 "nanf" → "nan"
    }
    else if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "float: " << str << "f" << std::endl; // 🔥 float 버전도 추가 출력
        std::cout << "double: " << str << std::endl;
    }
}


void ScalarConverter::handleChar(const std::string &str)
{
    char c = str[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl; // promotion
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl; // promotion
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl; // promotion    
}

void ScalarConverter::handleInt(const std::string &str)
{
    int intVal;
    try {
        intVal = std::stoi(str); // 문자열을 int로 변환
    } catch (const std::exception &e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (intVal < 32 || intVal > 126) 
        std::cout << "Non displayable" << std::endl;
    else if (intVal >= 48 && intVal <= 57)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(intVal) << "'" << std::endl; // Demotion

    std::cout << "int: " << intVal << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(intVal) << "f" << std::endl; // promotion
    std::cout << "double: " << static_cast<double>(intVal) << std::endl; // promotion
}

void ScalarConverter::handleFloat(const std::string &str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        handleSpecialLiterals(str);
        return;
    }
    double val = std::stod(str);
    std::cout << "char: ";
    if (val >= 0 && val <= 127)
    {
        char c = static_cast<char>(val); // demotion
        if (isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl; // demotion

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << val << std::endl; // promotion
}

void ScalarConverter::handleDouble(const std::string &str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        handleSpecialLiterals(str);
        return;
    }
    double val = std::stod(str);
    std::cout << "char: ";
    if (val >= 0 && val <= 127)
    {
        char c = static_cast<char>(val); // demotion
        if (isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl; // demotion

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl; // demotion
    std::cout << "double: " << val << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    Type type = checkType(str);
    switch (type)
    {
        case CHAR:
            handleChar(str);
            break;
        case INT:
            handleInt(str);
            break;
        case FLOAT:
            handleFloat(str);
            break;
        case DOUBLE:
            handleDouble(str);
            break;
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}
