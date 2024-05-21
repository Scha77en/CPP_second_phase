/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:36:06 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/20 11:33:32 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1(NULL, 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        // This will throw GradeTooHighException
        b1.incrementGrade();
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
        std::cout << b2 << std::endl;
        // This will throw GradeTooLowException
        b2.decrementGrade();
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // This will throw GradeTooHighException
        Bureaucrat b3("Charlie", 0);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // This will throw GradeTooLowException
        Bureaucrat b4("David", 151);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
