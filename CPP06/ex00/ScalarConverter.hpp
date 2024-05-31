/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:28:45 by aouhbi            #+#    #+#             */
/*   Updated: 2024/05/25 16:17:46 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    bool is_dot = false;
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    bool isChar(const std::string& literal);
    bool isInt(const std::string& literal);
    bool isFloat(const std::string& literal);
    bool isDouble(const std::string& literal);

    void convertFromChar(const std::string& literal);
    void convertFromInt(const std::string& literal);
    void convertFromFloat(const std::string& literal);
    void convertFromDouble(const std::string& literal);
};

#endif
