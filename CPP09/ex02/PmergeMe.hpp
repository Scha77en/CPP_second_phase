/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:38:31 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/06 07:01:03 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <vector>
#include <deque>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <ctime>
#include <utility>
#include <iomanip>
#include <stdexcept>

class PmergeMe {
private:
    int                                 struggler;
    std::vector<std::pair<int, int> >   vec_pairs;
    std::deque<std::pair<int, int> >    deq_pairs;
    size_t                              n_size;


public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe& operator=(const PmergeMe &copy);

    void sortVector();
    void sortDeque();
    void clear(void);

    void sort_array_v(std::vector<std::pair<int, int> >& arr);
    void sort_array_d(std::deque<std::pair<int, int> >& arr);
    
    void print_vector(std::vector<std::pair<int, int> >& arr);
    void print_deque(std::deque<std::pair<int, int> >& deq);

    std::vector<size_t> g_jacobsthalsequence(int n);
    std::vector<size_t> g_real_sequence(std::vector<size_t> jacobsthals_s, size_t size);
    std::deque<size_t> g_jacobsthalsequence_d(int n);
    std::deque<size_t> g_real_sequence_d(std::deque<size_t> jacobsthals_s, size_t size);
    void parseInput(int argc, char** argv);
    void sort();
};

#endif
