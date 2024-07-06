/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:04:01 by aouhbi            #+#    #+#             */
/*   Updated: 2024/07/06 10:43:19 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cctype>

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(const std::string& token, int a, int b) {
    if (token == "+") return a + b;
    if (token == "-") return a - b;
    if (token == "*") return a * b;
    if (token == "/") {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Invalid operator");
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<int> stack;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else if (isOperator(token)) {
            if (stack.size() < 2) throw std::runtime_error("Invalid expression");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(performOperation(token, a, b));
        } else {
            throw std::runtime_error("Invalid token in expression");
        }
    }

    if (stack.size() != 1) throw std::runtime_error("Invalid expression");
    return stack.top();
}
