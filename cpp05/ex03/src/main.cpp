/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:11:16 by eahn              #+#    #+#             */
/*   Updated: 2025/02/27 00:09:03 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"


void printHeader (const std::string& title)
{
    std::cout << "\n==== " << title << " ====\n" << std::endl;
}

int main() 
{
    printHeader("Intern test");

    Intern intern;

    AForm* form1 = intern.makeForm("shrubbery creation", "Bobo");
    AForm* form2 = intern.makeForm("robotomy request", "Nana");
    AForm* form3 = intern.makeForm("presidential pardon", "Trumpi");
    AForm* form4 = intern.makeForm("invalid form", "Error");

    //to check if the form is created
    if (form1)
        delete form1;
    if (form2)
        delete form2;
    if (form3) 
        delete form3;
    if (form4)  
        delete form4;   

    return 0;
}
