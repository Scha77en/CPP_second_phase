/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:40:48 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/31 15:54:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy) {
	(void)copy;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	try {
		const std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
		for (int i = 0; i < 3; i++) {
			if (formName == formTypes[i]) {
				std::cout << "Intern creates " << formName << std::endl;
				return (forms[i]);
			}
			delete forms[i];
	}
		throw FormNotFoundException();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

const char* Intern::FormNotFoundException::what() const throw() {
	return ("Form not found");
}