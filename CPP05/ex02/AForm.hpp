/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:09:29 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/02 15:59:16 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:

    // orthodox canonical form

    AForm();

    AForm(const char* name, int gradeRequiredToSign, int gradeRequiredToExecute);

    AForm(const AForm& copy);

    AForm& operator=(const AForm& copy);

    ~AForm();
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Constructor
    AForm(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    // Member function
    void    beSigned(const Bureaucrat& b);
    virtual void    execute(Bureaucrat const & executor) const = 0;

    void executeAction(const Bureaucrat& executor) const;
};

// Overload of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // FORM_HPP
