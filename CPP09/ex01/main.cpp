/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:03:44 by aouhbi            #+#    #+#             */
/*   Updated: 2024/07/06 10:06:05 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Please provide an RPN expression as an argument." << std::endl;
        return 1;
    }

    RPN rpn;

    try {
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
