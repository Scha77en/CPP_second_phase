/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:03:38 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/04 05:40:05 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
// #include <random>
#include <iostream>
#include <sys/_types/_ssize_t.h>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv) {
	struggler = -1;
	for (int i = 1; i < argc; ++i) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][j] == ' ')
				throw std::runtime_error("Error: Invalid input");
		}
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num < 0 || iss.rdbuf()->in_avail() != 0) {
			throw std::runtime_error("Error: Invalid input");
		}
		if (i % 2 == 0)
		{
			vec_pairs.push_back(std::make_pair(atoi(argv[i - 1]), num));
			deq_pairs.push_back(std::make_pair(atoi(argv[i - 1]), num));
		}
		else if (i + 1 == argc)
			struggler = num;
		}
}

void PmergeMe::sort() {
	clock_t start;
	float vecTime, deqTime;
	
	start = clock();
	sortVector();
	std::cout << "-------------------" << std::endl;
	vecTime = (float)( clock() - start) / (CLOCKS_PER_SEC / 1000);
	start = clock();
	sortDeque();
	deqTime = (float)( clock() - start) / (CLOCKS_PER_SEC / 1000);

	std::cout << "Time to process a range of " << n_size << " elements with std::vector : " 
			  << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << n_size << " elements with std::deque : " 
			  << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}

void PmergeMe::sortVector() {
	merge_sort_vector(vec_pairs);
}

void PmergeMe::sortDeque() {
	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	if (deq_pairs.size() < 2) {
		std::sort(deq_pairs.begin(), deq_pairs.end());
		for (size_t i = 0; i < deq_pairs.size(); i++) {
			main_chain.push_back(deq_pairs[i].first);
			main_chain.push_back(deq_pairs[i].second);
		}
		if (struggler != -1)
			main_chain.push_back(struggler);
		std::sort(main_chain.begin(), main_chain.end());
		for (size_t i = 0; i < main_chain.size(); i++)
			std::cout << main_chain[i] << " ";
		std::cout << std::endl;
		return ;
	}
	for (size_t i = 0; i < deq_pairs.size(); i++) {
		if (deq_pairs[i].first < deq_pairs[i].second)
			std::swap(deq_pairs[i].first, deq_pairs[i].second);
	}
	std::sort(deq_pairs.begin(), deq_pairs.end());
	main_chain.push_back(deq_pairs[0].second);
	main_chain.push_back(deq_pairs[0].first);
	for (size_t i = 1; i < deq_pairs.size(); i++) {
		main_chain.push_back(deq_pairs[i].first);
		pend_chain.push_back(deq_pairs[i].second);
	}
	std::vector<size_t> jacobsthals_s = g_jacobsthalsequence(deq_pairs.size() + 2);

	std::vector<size_t> real_sequance = g_real_sequence(jacobsthals_s, pend_chain.size());

	for (size_t i = 0; i < real_sequance.size(); i++) {
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[real_sequance[i]]);
		main_chain.insert(it, pend_chain[real_sequance[i]]);
	}
	real_sequance.clear();
	if (struggler != -1)
		main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
}

void    PmergeMe::merge_sort_vector(std::vector<std::pair<int, int> >& arr)
{
	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	std::cout << "array size = " << arr.size() << std::endl;
	if (arr.size() == 1) {
		if (arr[0].first < arr[0].second) {
			main_chain.push_back(arr[0].first);
			main_chain.push_back(arr[0].second);
		}
		else {
			main_chain.push_back(arr[0].second);
			main_chain.push_back(arr[0].first);
		}
		if (struggler != -1)
			main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
		return ;
	}
	// if (arr.size() < 2) {
	// 	std::sort(arr.begin(), arr.end());
	// 	for (size_t i = 0; i < arr.size(); i++) {
	// 		main_chain.push_back(arr[i].first);
	// 		main_chain.push_back(arr[i].second);
	// 	}
	// 	if (struggler != -1)
	// 		main_chain.push_back(struggler);
	// 	std::sort(main_chain.begin(), main_chain.end());
	// 	for (size_t i = 0; i < main_chain.size(); i++)
	// 		std::cout << main_chain[i] << " ";
	// 	std::cout << std::endl;
	// 	std::cout << "After: ";
	// 	for(size_t i = 0; i < main_chain.size(); i++)
	// 		std::cout << main_chain[i] << " ";
	// 	std::cout << std::endl;
	// 	return ;
	// }
	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i].first < arr[i].second)
			std::swap(arr[i].first, arr[i].second);
	}
	// std::sort(arr.begin(), arr.end());
	// for (size_t i = 1; i < arr.size(); i++) {
		// sorting the array pairs by the first element
		
	// }
	sort_array_v(arr);
	std::cout << "< 1 >" << std::endl;
	// main_chain.push_back(arr[0].second);
	// main_chain.push_back(arr[0].first);
	for (size_t i = 0; i < arr.size(); i++) {
		main_chain.push_back(arr[i].first);
		pend_chain.push_back(arr[i].second);
	}
	std::cout << "< 2 >" << std::endl;

	std::vector<size_t> jacobsthals_s = g_jacobsthalsequence(arr.size() + 2);
	for (size_t i = 0; i < jacobsthals_s.size(); i++)
		std::cout << jacobsthals_s[i] << " ";
	std::cout << std::endl;

	std::vector<size_t> real_sequance = g_real_sequence(jacobsthals_s, pend_chain.size());
	std::cout << "real sequence size = " << real_sequance.size() << std::endl;
	for (size_t i = 0; i < real_sequance.size(); i++)
		std::cout << real_sequance[i] << " ";
	std::cout << std::endl;
	
	for (size_t i = 0; i < real_sequance.size(); i++) {
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[real_sequance[i]]);
		main_chain.insert(it, pend_chain[real_sequance[i]]);
	}
	std::cout << "< 3 >" << std::endl;
	real_sequance.clear();
	if (struggler != -1)
		main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
	n_size = main_chain.size();
	std::cout << "main chain size = " << main_chain.size() << std::endl;
	std::cout << "-------------------" << std::endl;
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
}

std::vector<size_t> PmergeMe::g_jacobsthalsequence(int n) {
	std::vector<size_t> sequence;
	sequence.push_back(0);
	sequence.push_back(1);
	for (int i = 2; i < n; ++i) {
		sequence.push_back(sequence[i - 1] + 2 * sequence[i - 2]);
	}
	for (int j = 0; j < 2; j++) {
		sequence.erase(sequence.begin());
	}
	return sequence;
}

// sorting the array vector pairs by the first element
void	PmergeMe::sort_array_v(std::vector<std::pair<int, int> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = i + 1; j < arr.size(); j++) {
			if (arr[i].first > arr[j].first)
				std::swap(arr[i], arr[j]);
		}
	}
}

// sorting the array deque pairs by the first element
void	PmergeMe::sort_array_d(std::deque<std::pair<int, int> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = i + 1; j < arr.size(); j++) {
			if (arr[i].first > arr[j].first)
				std::swap(arr[i], arr[j]);
		}
	}
}

std::vector<size_t> PmergeMe::g_real_sequence(std::vector<size_t> jacobsthal_s, size_t pend_size) {
	std::vector<size_t> real_sequence;
	size_t i = 0;
	bool	out_limit = false;

	// generating the rael sequence

	// lopping through the jacobsthal sequence
	
	while (1) {
		ssize_t x = (ssize_t)jacobsthal_s[i];
		while (x >= (ssize_t)pend_size) {
			out_limit = true;
			// if (x == (ssize_t)pend_size)
			// 	break;
			x--;
		}
		
		while (std::find(real_sequence.begin(), real_sequence.end(), x) == real_sequence.end()) {
			std::cout << "pushing x = " << x << std::endl;
			real_sequence.push_back(x);
			x--;
			if (x < 0)
				break;
			// std::cout << "x = " << x << std::endl;
		}
		if (out_limit)
			break;
		i++;
	}
	return real_sequence;
}

void	PmergeMe::print_vector(std::vector<std::pair<int, int> >& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i].first << " " << arr[i].second << std::endl;
	std::cout << "array size = " << arr.size() << std::endl;
}

void	PmergeMe::print_deque(std::deque<std::pair<int, int> >& deq)
{
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i].first << " " << deq[i].second << std::endl;
	std::cout << "deque size = " << deq.size() << std::endl;
}
