/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:21:45 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/19 11:21:57 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        Form f1("Form1", 3, 5);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 4);
        Form f2("Form2", 3, 5);
        std::cout << b2 << std::endl;
        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // This will throw GradeTooHighException
        Form f3("Form3", 0, 5);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // This will throw GradeTooLowException
        Form f4("Form4", 151, 5);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
