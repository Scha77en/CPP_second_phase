/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:31:41 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/31 15:57:02 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat bureaucrat("Bob", 1);

    AForm* form;

    form = intern.makeForm("shrubbery creation", "Home");
    if (form) {
        form->beSigned(bureaucrat);
        form->execute(bureaucrat);
        delete form;
    }

    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        form->beSigned(bureaucrat);
        form->execute(bureaucrat);
        delete form;
    }

    form = intern.makeForm("presidential pardon", "Ford Prefect");
    if (form) {
        form->beSigned(bureaucrat);
        try {
            form->executeAction(bureaucrat);
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        delete form;
    }

    form = intern.makeForm("nonexistent form", "Nobody");
    if (form) {
        delete form;
    }

    return 0;
}
