/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:27:38 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 17:38:51 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// canonical form

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm(copy), target(copy.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this == &copy) {
        return *this;
    }
    AForm::operator=(copy);
    target = copy.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    try {
        bool state = executeAction(executor);
        if (state == true)
            std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        else
            throw std::runtime_error("Presidential Pardon failed.");
    }
    catch (std::exception& e) {
        std::cerr << executor.getName() << " couldn’t execute " << getName() << " because " << e.what() << std::endl;
    }
}
