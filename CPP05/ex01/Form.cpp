/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:15:15 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/19 11:15:21 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Implementation of exception what() methods
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Implementation of Form constructor
Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Implementation of getters
const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

// Implementation of beSigned method
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

// Implementation of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << f.getGradeRequiredToSign()
       << ", grade required to execute: " << f.getGradeRequiredToExecute();
    return os;
}
