/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:29:32 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/07 13:55:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {
    
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}
ScalarConverter::~ScalarConverter() {
    
}

void ScalarConverter::convert(const std::string& literal) {

    try {
        ScalarConverter sc;
        if (sc.isChar(literal)) {
            sc.convertFromChar(literal);
        } else if (sc.isInt(literal)) {
            sc.convertFromInt(literal);
        } else if (sc.isFloat(literal)) {
            sc.convertFromFloat(literal);
        } else if (sc.isDouble(literal)) {
            sc.convertFromDouble(literal);
        } else {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string& literal) {
    if (literal.length() == 1 && literal[0] != ' ' && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string& literal) {
    std::stringstream ss(literal);
    int i;

    if (ss >> i && ss.eof())
        return true;
      return false;  
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return true;
    }
    char *endptr;

    std::strtof(literal.c_str(), &endptr);
    if (errno == HUGE_VALF)
        throw std::overflow_error("Overflow");
    else if (errno == -HUGE_VALF)
        throw std::underflow_error("Underflow");
    return *endptr == 'f' && *(endptr + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return true;
    }
    char *endptr;

    std::strtod(literal.c_str(), &endptr);
    if (errno == HUGE_VAL)
        throw std::overflow_error("Overflow");
    else if (errno == -HUGE_VAL)
        throw std::underflow_error("Underflow");
    return *endptr == '\0';
}

void ScalarConverter::convertFromChar(const std::string& literal) {
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& literal) {
    int i = std::atoi(literal.c_str());
    if (i >= 32 && i <= 126) {
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& literal) {
    float f = std::strtof(literal.c_str(), NULL);
    if (std::isnan(f) || std::isinf(f) || f < 32 || f > 126) {
        std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    }
    if (f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()) || std::isnan(f)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& literal) {
    double d = std::strtod(literal.c_str(), NULL);
    if (std::isnan(d) || std::isinf(d) || d < 32 || d > 126) {
        std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
