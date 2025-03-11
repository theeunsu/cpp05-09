/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:47:57 by eahn              #+#    #+#             */
/*   Updated: 2025/03/11 21:51:39 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"


int main( void ) 
{
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}

// int main ()
// {
// 	// int test
// 	int a = 2, b = 3;
//     ::swap(a, b);
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
//     std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
//     std::cout << "-----------------------------" << std::endl;

// 	// double test
// 	double x = 4.2, y = 3.14;
//     ::swap(x, y);
//     std::cout << "x = " << x << ", y = " << y << std::endl;
//     std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
//     std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
//     std::cout << "-----------------------------" << std::endl;

// 	// char test
// 	char c1 = 'A', c2 = 'Z';
//     ::swap(c1, c2);
//     std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
//     std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
//     std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;
//     std::cout << "-----------------------------" << std::endl;
	
// }
