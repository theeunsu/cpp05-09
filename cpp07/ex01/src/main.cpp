/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:55:12 by eahn              #+#    #+#             */
/*   Updated: 2025/03/11 22:10:01 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";
}

int main ()
{
    // test int
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "int array: ";
    iter(arr, 5, printElement<int>);
    std::cout << std::endl;

    // test double
    double arr2[] = {1.1, 2.2, 3.3};
    std::cout << "double array: ";
    iter(arr2, 3, printElement<double>);
    std::cout << std::endl;

    // test char
    char arr3[] = {'a', 'b', 'c', 'd'};
    std::cout << "char array: ";
    iter(arr3, 4, printElement<char>);
    std::cout << std::endl;

    // test string
    std::string arc4[] = {"Hello", "World", "42"};
    std::cout << "string array: ";
    iter(arc4, 3, printElement<std::string>);
    std::cout << std::endl;

}
