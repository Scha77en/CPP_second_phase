/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:31:41 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/31 15:23:51 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    Bureaucrat a("Bob", 1);
    Bureaucrat b("Alice", 150);
    Bureaucrat c("Charlie", 20);

    ShrubberyCreationForm shrubbery;
    RobotomyRequestForm robotomy("home");
    PresidentialPardonForm pardon("home");

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;

    // std::cout << shrubbery << std::endl;
    // std::cout << robotomy << std::endl;
    // std::cout << pardon << std::endl;

    try {
        a.signAForm(shrubbery);
        a.executeForm(shrubbery);
        shrubbery.execute(a);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        b.signAForm(robotomy);
        b.executeForm(robotomy);
        robotomy.execute(b);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        c.signAForm(pardon);
        c.executeForm(pardon);
        pardon.execute(c);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}