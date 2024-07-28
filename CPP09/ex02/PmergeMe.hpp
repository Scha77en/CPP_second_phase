/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:38:31 by aouhbi            #+#    #+#             */
/*   Updated: 2024/07/28 19:54:12 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> vec;
    std::deque<int> deq;

    void sortVector();
    void merge_sort_vector(std::vector<int>& arr);
    
    void sortDeque();
    void mergeInsertSortVector(std::vector<int>& arr, int left, int right);
    void mergeInsertSortDeque(std::deque<int>& arr, int left, int right);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    
    void print_vector(std::vector<int>& arr);
    void print_sequence(std::vector<size_t> sequance);

    std::vector<size_t> g_jacobsthalsequence(int n);
    std::vector<size_t> g_real_sequence(std::vector<size_t> jacobsthal_s, int pend_size);

public:
    PmergeMe();
    ~PmergeMe();

    void parseInput(int argc, char** argv);
    void sort();
};

#endif

// #ifndef PMERGEME_HPP
// #define PMERGEME_HPP

// #include <vector>
// #include <deque>
// #include <stdexcept>
// #include <iostream>
// #include <string>
// #include <sstream>
// #include <chrono>

// class PmergeMe {
// public:
//     static void mergeInsertSortVector(std::vector<int>& arr);
//     static void mergeInsertSortDeque(std::deque<int>& arr);

// private:
//     static void mergeInsertSortUtilVector(std::vector<int>& arr, int left, int right);
//     static void mergeInsertSortUtilDeque(std::deque<int>& arr, int left, int right);

//     static void mergeVector(std::vector<int>& arr, int left, int mid, int right);
//     static void mergeDeque(std::deque<int>& arr, int left, int mid, int right);

//     static void insertionSortVector(std::vector<int>& arr, int left, int right);
//     static void insertionSortDeque(std::deque<int>& arr, int left, int right);
// };

// #endif
