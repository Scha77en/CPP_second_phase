/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:16:56 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/04 05:42:59 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <set>

int main(int argc, char** argv) {
    if (argc <= 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    PmergeMe sorter;


    std::set<int> unique_numbers;

    std::cout << "arguments number = " << argc - 1 << std::endl;

    for (int i = 1; i < argc; i++) {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            std::cerr << "Error: Invalid input" << std::endl;
            return 1;
        }
        if (unique_numbers.find(num) != unique_numbers.end()) {
            std::cerr << "Error: Duplicate number found" << std::endl;
            return 1;
        }
        unique_numbers.insert(num);
    }


    unique_numbers.clear();

    try {
        sorter.parseInput(argc, argv);
        std::cout << "Before: ";
        for (int i = 1; i < argc; i++) {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
        sorter.sort();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}