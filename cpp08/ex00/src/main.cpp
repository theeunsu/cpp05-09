/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:01:38 by eahn              #+#    #+#             */
/*   Updated: 2025/03/26 15:34:09 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main()
{
    // Test1: vector
    std::vector<int> vec;
    for (int i = 0; i < 10 ; ++i)
        vec.push_back(i * 2); // 0, 2, 4, ..., 18 | push_back: to add values to container
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Vector: " << e.what() << std::endl;
    }
        
    // Test2: list
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i + 10); // 10, 11, 12, 13, 14
    
    try 
    {
        std::list<int>::iterator it = easyfind(lst, 12);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "List: " << e.what() << std::endl;
    }

    // not found
    try
    {
        easyfind(vec, 100);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Not found: " << e.what() << std::endl;
    }
    
    return 0;
}