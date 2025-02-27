/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:11:16 by eahn              #+#    #+#             */
/*   Updated: 2025/02/27 15:27:01 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void printHeader (const std::string& title)
{
    std::cout << "\n==== " << title << " ====\n" << std::endl;
}

int main() {
    printHeader("Bureaucrat Creation");
    Bureaucrat high ("Trumpi", 1);
    Bureaucrat mid ("Nana", 50);
    Bureaucrat low ("Bobo", 150);

    printHeader("Form Creation");
    ShrubberyCreationForm shrubbery("CreationForm");
    RobotomyRequestForm robotomy("RequestForm");
    PresidentialPardonForm pardon("PardonForm");

    std::cout << shrubbery;
    std::cout << robotomy;
    std::cout << pardon;

    printHeader("Bureaucrat Sign Form");
    try 
    {
        high.signForm(shrubbery);
        high.signForm(robotomy);
        high.signForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cerr << "Exeption: " << e.what() << std::endl;
    }

    printHeader("Bureaucrat Execute Form");
    try
    {
        high.executeForm(shrubbery);
        mid.executeForm(robotomy);
        high.executeForm(pardon);
        low.executeForm(pardon);
    }
    catch (std::exception & e)
    {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }

    printHeader("Reading Shrubbery File");
    std::ifstream file("CreationForm_shrubbery");
    if (file)
    {
        std::cout << file.rdbuf() << std::endl; //rdbuf() reads the entire file
    }
    else
    {
        std::cerr << "Error: Shrubbery file not found!" << std::endl;
    }

    return 0;
}


// // Test RobotomyRequestForm probability
// int main() {
//     printHeader("Bureaucrat Creation");
//     Bureaucrat trumpi("Trumpi", 1);
//     Bureaucrat nana("Nana", 50);  
//     Bureaucrat bobo("Bobo", 150);

//     printHeader("RobotomyRequestForm Test");
//     RobotomyRequestForm robotomy("Bender");

//     std::cout << robotomy << std::endl;

//     printHeader("Signing RobotomyRequestForm");
//     trumpi.signForm(robotomy);  // sign succeeded (Trumpi 등급 1 ≤ 72)

//     //// Randomly determine seed
// 	// std::srand(std::time(0)); // determine seed based on current time

//     printHeader("Executing RobotomyRequestForm Multiple Times");
//     for (int i = 0; i < 10; i++) {  // check 5 times
//         std::cout << "\nExecution Attempt #" << (i + 1) << std::endl;
//         try {
//             trumpi.executeForm(robotomy);  // 
//         } catch (const std::exception& e) {
//             std::cerr << "Execution failed: " << e.what() << std::endl;
//         }
//     }

//     return 0;
// }
