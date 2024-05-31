/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:25:24 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 14:43:25 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;

public:
    
    // orthodox canonical form

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

    // Getters
    const std::string& getTarget() const;
};

#endif
