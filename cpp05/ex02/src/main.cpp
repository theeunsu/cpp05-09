/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:11:16 by eahn              #+#    #+#             */
/*   Updated: 2025/02/24 00:11:11 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
    std::cout << "==== ShrubberyCreationForm Test ====" << std::endl;

    Bureaucrat bob("Bob", 1);  // 높은 등급의 Bureaucrat
    ShrubberyCreationForm form("garden"); // "garden_shrubbery" 파일을 생성할 것

    std::cout << "\n[ Before Signing ]" << std::endl;
    std::cout << form << std::endl;

    std::cout << "\n[ Bob Tries to Sign the Form ]" << std::endl;
    bob.signForm(form);  // ✅ 서명 성공 (Bob의 등급 1 ≤ 145)

    std::cout << "\n[ Bob Tries to Execute the Form ]" << std::endl;
    try {
        form.execute(bob); // ✅ 실행 성공 (Bob의 등급 1 ≤ 137)
    } catch (const std::exception& e) {
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }

    std::cout << "\n[ After Execution ]" << std::endl;
    std::cout << form << std::endl;

    return 0;
}
