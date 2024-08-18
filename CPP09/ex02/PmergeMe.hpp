/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:38:31 by aouhbi            #+#    #+#             */
/*   Updated: 2024/08/11 10:01:53 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <utility>
#include <iomanip>
#include <stdexcept>

class PmergeMe {
private:
    int struggler;
    std::vector<std::pair<int, int> > vec_pairs;
    std::deque<std::pair<int, int> > deq_pairs;

    void sortVector();
    void merge_sort_vector(std::vector<std::pair<int, int> >& arr);
    
    void sortDeque();
    void mergeInsertSortVector(std::vector<int>& arr, int left, int right);
    void mergeInsertSortDeque(std::deque<int>& arr, int left, int right);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);

    std::vector<std::pair<int, int> > set_vec_pairs(std::vector<int>& vec);
    std::deque<std::pair<int, int> > set_deq_pairs(std::deque<int>& deq);
    
    void print_vector(std::vector<std::pair<int, int> >& arr);
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
