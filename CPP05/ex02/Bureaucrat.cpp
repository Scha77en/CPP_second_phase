/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:15:56 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 19:13:46 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Implementation of Bureaucrat constructors

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const char* name, int grade) : grade(grade) {
    if (name == NULL)
        this->name = "Default";
    else
        this->name = name;
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this == &copy) {
        return *this;
    }
    this->name = copy.name;
    this->grade = copy.grade;
    return *this;
}

// Implementation of the methods of the Exception classes
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Overload of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150) {
        throw GradeTooLowException();
    }
    grade++;
}

// Getters
const std::string &Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::signAForm(AForm& f) const {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

// Implementation of executeForm method
void Bureaucrat::executeForm(AForm const & form) const {
    try {
        bool state = form.executeAction(*this);
        if (state)
            std::cout << name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cerr << name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {}
