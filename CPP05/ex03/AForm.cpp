/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:08:45 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/19 14:08:48 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

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

// Implementation of AForm destructor
AForm::~AForm() {}

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
    }
    isSigned = true;
}

// Implementation of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeRequiredToSign()
       << ", grade required to execute: " << f.getGradeRequiredToExecute();
    return os;
}
