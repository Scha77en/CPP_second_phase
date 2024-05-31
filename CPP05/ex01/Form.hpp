/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:29 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 11:29:43 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:

    
    // orthodox canonical form

    Form();

    Form(const char* name, int gradeRequiredToSign, int gradeRequiredToExecute);

    Form(const Form& copy);

    Form& operator=(const Form& copy);

    ~Form();
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Constructor
    Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    // Member function
    void beSigned(const Bureaucrat& b);

};

// Overload of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
