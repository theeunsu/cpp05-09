/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:17:09 by eahn              #+#    #+#             */
/*   Updated: 2025/03/09 01:40:46 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream> // std::cout std::endl

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // if p is pointing to A = true
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::bad_cast&) {}

	std::cout << "Unknown" << std::endl;
}


// Base* p는 nullptr 체크로 안전하게 변환 가능하므로 예외 처리가 필요 없음
// -> even if dynamic_cast fails, it will return nullptr without crashing
// Base& p는 nullptr이 불가능하기 때문에 예외 처리가 필요함
