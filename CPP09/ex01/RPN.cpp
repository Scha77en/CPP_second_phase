/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:04:01 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/06 06:54:13 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cctype>

RPN::RPN() {}

RPN::~RPN() {}

float RPN::performOperation(const std::string& token, float a, float b) {
    if (token == "+") return a + b;
    if (token == "-") return a - b;
    if (token == "*") return a * b;
    if (token == "/") {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Invalid operator");
}

float RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<float> stack;

    while (iss >> token) {
        if (token.size() != 1)
            throw std::runtime_error("numbers must be between 0 and 9 integers");
        
        if (std::isdigit(token[0])) 
            stack.push(std::atoi(token.c_str()));
        else {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            float b = stack.top(); stack.pop();
            float a = stack.top(); stack.pop();
            stack.push(performOperation(token, a, b));

            if (stack.top() > INT_MAX || stack.top() < INT_MIN)
                throw std::runtime_error("The result is out of range");
        }
    }

    if (stack.size() != 1) throw std::runtime_error("Invalid expression");
    return stack.top();
}
