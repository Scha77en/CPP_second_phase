/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:03:38 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/06 07:01:01 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <sys/_types/_ssize_t.h>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {
	this->clear();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy) {
		struggler = copy.struggler;
		vec_pairs = copy.vec_pairs;
		deq_pairs = copy.deq_pairs;
		n_size = copy.n_size;
	}
	return *this;
}
void PmergeMe::clear(void) {
	struggler = -1;
	vec_pairs.clear();
	deq_pairs.clear();
	n_size = 0;
}
void PmergeMe::parseInput(int argc, char** argv) {
	this->clear();
	for (int i = 1; i < argc; ++i) {
		std::istringstream iss(argv[i]);
		int num;
		if (!iss.str().find(' ') || !iss.str().find('\t') || !iss.str().find('-')
			|| !(iss >> num) || num < 0 || iss.peek() != EOF) {
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
	vecTime = (float)( clock() - start) / (CLOCKS_PER_SEC / 1000);
	start = clock();
	sortDeque();
	deqTime = (float)( clock() - start) / (CLOCKS_PER_SEC / 1000);

	std::cout << "Time to process a range of " << n_size << " elements with std::vector : " 
			  << std::fixed << std::setprecision(5) << vecTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << n_size << " elements with std::deque : " 
			  << std::fixed << std::setprecision(5) << deqTime << " ms" << std::endl;
}

void PmergeMe::sortVector() {
	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	if (vec_pairs.size() == 1) {
		if (vec_pairs[0].first < vec_pairs[0].second) {
			main_chain.push_back(vec_pairs[0].first);
			main_chain.push_back(vec_pairs[0].second);
		}
		else {
			main_chain.push_back(vec_pairs[0].second);
			main_chain.push_back(vec_pairs[0].first);
		}
		if (struggler != -1)
			main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
		std::cout << "After:  ";
		for (size_t i = 0; i < main_chain.size(); i++)
			std::cout << main_chain[i] << " ";
		std::cout << std::endl;
		return ;
	}
	for (size_t i = 0; i < vec_pairs.size(); i++) {
		if (vec_pairs[i].first < vec_pairs[i].second)
			std::swap(vec_pairs[i].first, vec_pairs[i].second);
	}
	sort_array_v(vec_pairs);
	for (size_t i = 0; i < vec_pairs.size(); i++) {
		main_chain.push_back(vec_pairs[i].first);
		pend_chain.push_back(vec_pairs[i].second);
	}

	std::vector<size_t> jacobsthals_s = g_jacobsthalsequence(vec_pairs.size() + 2);

	std::vector<size_t> real_sequance = g_real_sequence(jacobsthals_s, pend_chain.size());

	for (size_t i = 0; i < real_sequance.size(); i++) {
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[real_sequance[i]]);
		main_chain.insert(it, pend_chain[real_sequance[i]]);
	}
	real_sequance.clear();
	if (struggler != -1)
		main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
	n_size = main_chain.size();
	std::cout << "After:  ";
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::sortDeque() {
	std::deque<int> main_chain;
	std::deque<int> pend_chain;

	if (deq_pairs.size() == 1) {
		if (deq_pairs[0].first < deq_pairs[0].second) {
			main_chain.push_back(deq_pairs[0].first);
			main_chain.push_back(deq_pairs[0].second);
		}
		else {
			main_chain.push_back(deq_pairs[0].second);
			main_chain.push_back(deq_pairs[0].first);
		}
		if (struggler != -1)
			main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
		return ;
	}
	for (size_t i = 0; i < deq_pairs.size(); i++) {
		if (deq_pairs[i].first < deq_pairs[i].second)
			std::swap(deq_pairs[i].first, deq_pairs[i].second);
	}
	sort_array_d(deq_pairs);
	for (size_t i = 0; i < deq_pairs.size(); i++) {
		main_chain.push_back(deq_pairs[i].first);
		pend_chain.push_back(deq_pairs[i].second);
	}

	std::deque<size_t> jacobsthals_s = g_jacobsthalsequence_d(deq_pairs.size() + 2);

	std::deque<size_t> real_sequance = g_real_sequence_d(jacobsthals_s, pend_chain.size());

	for (size_t i = 0; i < real_sequance.size(); i++) {
		std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[real_sequance[i]]);
		main_chain.insert(it, pend_chain[real_sequance[i]]);
	}
	real_sequance.clear();
	if (struggler != -1)
		main_chain.insert((std::lower_bound(main_chain.begin(), main_chain.end(), struggler)), struggler);
	n_size = main_chain.size();
}


// Jacobsthal sequence for vector
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


// Jacobsthal sequence for deque
std::deque<size_t> PmergeMe::g_jacobsthalsequence_d(int n) {
	std::deque<size_t> sequence;
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
	
	while (1) {
		ssize_t x = (ssize_t)jacobsthal_s[i];
		while (x >= (ssize_t)pend_size) {
			out_limit = true;
			x--;
		}
		
		while (std::find(real_sequence.begin(), real_sequence.end(), x) == real_sequence.end()) {
			real_sequence.push_back(x);
			x--;
			if (x < 0)
				break;
		}
		if (out_limit)
			break;
		i++;
	}
	return real_sequence;
}

std::deque<size_t> PmergeMe::g_real_sequence_d(std::deque<size_t> jacobsthal_s, size_t pend_size) {
	std::deque<size_t> real_sequence;
	size_t i = 0;
	bool	out_limit = false;
	
	while (1) {
		ssize_t x = (ssize_t)jacobsthal_s[i];
		while (x >= (ssize_t)pend_size) {
			out_limit = true;
			x--;
		}
		
		while (std::find(real_sequence.begin(), real_sequence.end(), x) == real_sequence.end()) {
			real_sequence.push_back(x);
			x--;
			if (x < 0)
				break;
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
