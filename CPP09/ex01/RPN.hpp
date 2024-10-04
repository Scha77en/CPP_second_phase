/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:03:53 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/03 21:23:29 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
public:
    RPN();
    ~RPN();

    float evaluate(const std::string& expression);
    bool  isnumber(const std::string& token);

private:
    bool isOperator(const std::string& token);
    float performOperation(const std::string& token, float a, float b);
};

#endif
