/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:11:20 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/31 13:39:40 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// orthodox canonical form

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm(copy), target(copy.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this == &copy)
        return *this;
    AForm::operator=(copy);
    target = copy.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    try {
        bool state = executeAction(executor);
        if (state == true) {
            std::string filename = target + "_shrubbery";
            std::ofstream file(filename);
            if (!file.is_open())
                throw std::runtime_error("Failed to open file.");
            file << "       _-_" << std::endl;
            file << "    /~~   ~~\\" << std::endl;
            file << " /~~         ~~\\" << std::endl;
            file << "{               }" << std::endl;
            file << " \\  _-     -_  /" << std::endl;
            file << "   ~  \\ //  ~" << std::endl;
            file << "_- -   | | _- _" << std::endl;
            file << "  _ -  | |   -_" << std::endl;
            file << "      // \\" << std::endl;
            file.close();
            if (file.fail())
                throw std::runtime_error("Error writing to file.");
        }
        else
            throw std::runtime_error("Shrubbery Creation failed.");
    }
   catch (std::exception& e) {
        std::cerr << executor.getName() << " couldn’t execute " << getName() << " because " << e.what() << std::endl;
    }
}
