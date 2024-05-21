/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:20:59 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/20 11:39:44 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat {
private:
    std::string name;
    int grade;

public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    // Constructor
    Bureaucrat(const char* name, int grade);

    // Getters
    const std::string& getName() const ;

    int getGrade() const ;

    // Increment and Decrement functions
    void incrementGrade();

    void decrementGrade();

    // Sign form function
    void signForm(Form& f) const;
};

// Overload of the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
