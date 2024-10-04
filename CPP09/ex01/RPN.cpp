/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:04:01 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/03 21:23:12 by aouhbi           ###   ########.fr       */
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

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

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

bool RPN::isnumber(const std::string& token) {
    for (size_t i = 0; i < token.size(); i++) {
        if (!std::isdigit(token[i])) return false;
    }
    return true;
}

float RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<float> stack;

    while (iss >> token) {
        if (isnumber(token)) {
            stack.push(std::stoi(token));
        } else if (isOperator(token)) {
            if (stack.size() < 2) throw std::runtime_error("Invalid expression");
            float b = stack.top(); stack.pop();
            float a = stack.top(); stack.pop();
            stack.push(performOperation(token, a, b));
            if (stack.top() > INTMAX_MAX || stack.top() < INTMAX_MIN) throw std::runtime_error("The result is out of range");
        } else {
            throw std::runtime_error("Invalid token in expression");
        }
    }

    if (stack.size() != 1) throw std::runtime_error("Invalid expression");
    return stack.top();
}
