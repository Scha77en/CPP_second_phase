/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:38:31 by aouhbi            #+#    #+#             */
/*   Updated: 2024/08/23 15:24:26 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
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
    int                                 struggler;
    std::vector<std::pair<int, int> >   vec_pairs;
    std::deque<std::pair<int, int> >    deq_pairs;
    size_t                              n_size;

    void sortVector();
    void merge_sort_vector(std::vector<std::pair<int, int> >& arr);

    void sortDeque();
    
    void print_vector(std::vector<std::pair<int, int> >& arr);
    void print_deque(std::deque<std::pair<int, int> >& deq);
    void print_sequence(std::vector<size_t> sequance);

    std::vector<size_t> g_jacobsthalsequence(int n);
    std::vector<size_t> g_real_sequence(std::vector<size_t> jacobsthals_s, size_t size);

public:
    PmergeMe();
    ~PmergeMe();

    void parseInput(int argc, char** argv);
    void sort();
};

#endif
