/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:20:59 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 10:35:55 by aouhbi           ###   ########.fr       */
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
    // orthodox canonical form

    Bureaucrat();

    Bureaucrat(const char* name, int grade);

    Bureaucrat(const Bureaucrat& copy);

    Bureaucrat& operator=(const Bureaucrat& copy);

    ~Bureaucrat();

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

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
