/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:48:20 by eahn              #+#    #+#             */
/*   Updated: 2025/03/04 18:48:39 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    
    std::string input(argv[1]);
    ScalarConverter::convert(input);
    
    return 0;
}
