/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:42:36 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/19 14:42:41 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        Intern someRandomIntern;

        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "criminal");
        AForm* form4 = someRandomIntern.makeForm("unknown form", "target");

        if (form1) {
            std::cout << *form1 << std::endl;
            b1.signForm(*form1);
            b1.executeForm(*form1);
            delete form1;
        }

        if (form2) {
            std::cout << *form2 << std::endl;
            b1.signForm(*form2);
            b1.executeForm(*form2);
            delete form2;
        }

        if (form3) {
            std::cout << *form3 << std::endl;
            b1.signForm(*form3);
            b1.executeForm(*form3);
            delete form3;
        }

        if (form4) {
            delete form4;
        }

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
