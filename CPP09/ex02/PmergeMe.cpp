/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:03:38 by aouhbi            #+#    #+#             */
/*   Updated: 2024/08/23 15:32:49 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <random>
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
		if (!(iss >> num) || num < 0) {
			throw std::runtime_error("Error: Invalid input");
		}
		if (i % 2 == 0)
		{
			vec_pairs.push_back(std::make_pair(std::stoi(argv[i - 1]), num));
			deq_pairs.push_back(std::make_pair(std::stoi(argv[i - 1]), num));
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

	if (arr.size() < 2) {
		std::sort(arr.begin(), arr.end());
		for (size_t i = 0; i < arr.size(); i++) {
			main_chain.push_back(arr[i].first);
			main_chain.push_back(arr[i].second);
		}
		if (struggler != -1)
			main_chain.push_back(struggler);
		std::sort(main_chain.begin(), main_chain.end());
		for (size_t i = 0; i < main_chain.size(); i++)
			std::cout << main_chain[i] << " ";
		std::cout << std::endl;
		std::cout << "After: ";
		for(size_t i = 0; i < main_chain.size(); i++)
			std::cout << main_chain[i] << " ";
		std::cout << std::endl;
		return ;
	}
	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i].first < arr[i].second)
			std::swap(arr[i].first, arr[i].second);
	}
	std::sort(arr.begin(), arr.end());
	main_chain.push_back(arr[0].second);
	main_chain.push_back(arr[0].first);
	for (size_t i = 1; i < arr.size(); i++) {
		main_chain.push_back(arr[i].first);
		pend_chain.push_back(arr[i].second);
	}

	std::vector<size_t> jacobsthals_s = g_jacobsthalsequence(arr.size() + 2);

	std::vector<size_t> real_sequance = g_real_sequence(jacobsthals_s, pend_chain.size());

	for (size_t i = 0; i < real_sequance.size(); i++) {
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[real_sequance[i]]);
		main_chain.insert(it, pend_chain[real_sequance[i]]);
	}
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

void PmergeMe::print_sequence(std::vector<size_t> sequance) {
	for (size_t i = 0; i < sequance.size(); i++)
		std::cout << sequance[i] << " ";
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

std::vector<size_t> PmergeMe::g_real_sequence(std::vector<size_t> jacobsthal_s, size_t pend_size) {
	std::vector<size_t> real_sequence;
	size_t i = 0;
	bool	out_limit = false;

	while (1)
	{
		size_t x = jacobsthal_s[i];
		while (x >= pend_size) {
			x--;
			out_limit = true;
		}
		if (real_sequence.size() < jacobsthal_s.size())
			real_sequence.push_back(x);
		else
			break;
		if (out_limit) {
			x--;
			while (find(jacobsthal_s.begin(), jacobsthal_s.end(), x) == jacobsthal_s.end()) {
				real_sequence.push_back(x);
				x--;
			}
			break;
		}
		x--;
		while (find(jacobsthal_s.begin(), jacobsthal_s.end(), x) == jacobsthal_s.end()) {
			real_sequence.push_back(x);
			x--;
			if ((ssize_t)x < 0)
				break;
		}
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
