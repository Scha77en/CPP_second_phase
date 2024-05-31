/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:26:02 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 17:38:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// orthodox canonical form

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(copy), target(copy.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this == &copy) {
        return *this;
    }
    AForm::operator=(copy);
    target = copy.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    try {
        bool state = executeAction(executor);
        if (state == true) {
            std::cout << "Drilling Noises..." << std::endl;
            std::srand(time(0));
            if (rand() % 2 == 0) {
                std::cout << target << " has been robotomized successfully." << std::endl;
            } else {
                throw std::runtime_error("Robotomization failed.");
            }
        }
    }
    catch (std::exception& e) {
        std::cerr << executor.getName() << " couldn’t execute " << getName() << " because " << e.what() << std::endl;
    }
}
