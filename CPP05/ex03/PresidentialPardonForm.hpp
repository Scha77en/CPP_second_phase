/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:27:13 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/30 17:35:24 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:

    // orthodox canonical form
    
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
    ~PresidentialPardonForm();

    // Getters
    const std::string& getTarget() const;

    // Execute function
    void execute(const Bureaucrat& executor) const;
};

#endif
