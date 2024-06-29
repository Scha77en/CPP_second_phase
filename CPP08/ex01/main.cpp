/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:59:31 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/28 16:12:04 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl; // Should output 2
        std::cout << sp.longestSpan() << std::endl; // Should output 14
        sp.addNumber(10); // Should throw an exception

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> moreNumbers(arr, arr + sizeof(arr) / sizeof(int));
        Span sp2 = Span(15);
        sp2.addNumbers(moreNumbers.begin(), moreNumbers.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Span span = Span(1);
        std::cout << span.shortestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span span = Span(5);
        span.addNumber(1);
        std::cout << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

