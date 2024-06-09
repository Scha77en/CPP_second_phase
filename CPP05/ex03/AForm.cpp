/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:15:15 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/02 15:50:58 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150) {}

AForm::AForm(const char* name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::~AForm() {}

AForm::AForm(const AForm& copy) : name(copy.name),
                            isSigned(copy.isSigned),
                            gradeRequiredToSign(copy.gradeRequiredToSign),
                            gradeRequiredToExecute(copy.gradeRequiredToExecute)
{}

AForm& AForm::operator=(const AForm& copy) {
    if (this == &copy) {
        return *this;
    }
    this->isSigned = copy.isSigned;
    return *this;
}

// Implementation of exception what() methods
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Implementation of AForm constructor
AForm::AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Implementation of getters
const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

// Implementation of beSigned method
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeRequiredToSign) {
        throw GradeTooLowException();
        return;
    }
    isSigned = true;
}

void AForm::executeAction(const Bureaucrat& executor) const {
    if (!isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeRequiredToExecute) {
        throw GradeTooLowException();
    }
}

// Implementation of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeRequiredToSign()
       << ", grade required to execute: " << f.getGradeRequiredToExecute();
    return os;
}
