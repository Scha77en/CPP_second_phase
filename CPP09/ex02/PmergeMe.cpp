/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:03:38 by aouhbi            #+#    #+#             */
/*   Updated: 2024/08/21 21:54:45 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
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
	std::cout << "Before: ";
	// for (size_t i = 0; i < vec_pairs.size(); ++i) {
	// 	std::cout << vec_pairs[i].first << " " << vec_pairs[i].second << " ";
	// }
	// std::cout << std::endl;

	// clock_t start, end;
	
	// start = clock();
	sortVector();
	return ;
	// end = clock();
	// float vecTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000000;

	// start = clock();
	// sortDeque();
	// end = clock();
	// float deqTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000000;

	// std::cout << "After: ";
	// for (size_t i = 0; i < vec.size(); ++i) {
	// 	std::cout << vec[i] << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
	// 		  << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
	// std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
	// 		  << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}

void PmergeMe::sortVector() {
	merge_sort_vector(vec_pairs);
	// mergeInsertSortVector(vec, 0, vec.size() - 1);
}

std::vector<std::pair<int, int> > PmergeMe::set_vec_pairs(std::vector<int>& vec) {
	size_t vec_size = vec.size() / 2;
	std::vector<std::pair<int, int> > vec_pairs;

	for (size_t i = 0; i < vec_size; i += 2) {
		vec_pairs.push_back((std::make_pair(vec[i], vec[i + 1])));
	}
	print_vector(vec_pairs);
	vec.clear();
	return vec_pairs;
}

std::deque<std::pair<int, int> > PmergeMe::set_deq_pairs(std::deque<int>& deq) {
	size_t deq_size = deq.size() / 2;
	std::deque<std::pair<int, int> > deq_pairs;

	for (size_t i = 0; i < deq_size; i += 2) {
		deq_pairs.push_back((std::make_pair(deq[i], deq[i + 1])));
	}
	deq.clear();
	return deq_pairs;
}

void    PmergeMe::merge_sort_vector(std::vector<std::pair<int, int> >& arr)
{
	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	if (arr.size() < 2) {
		std::sort(arr.begin(), arr.end());
		std::cout << "---------- main chain ---------" << std::endl;
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
		return ;
	}
	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i].first < arr[i].second)
			std::swap(arr[i].first, arr[i].second);
	}
	std::sort(arr.begin(), arr.end());
	std::cout << "-------------------" << std::endl;
	// print_vector(arr);
	main_chain.push_back(arr[0].second);
	main_chain.push_back(arr[0].first);
	for (size_t i = 1; i < arr.size(); i++) {
		main_chain.push_back(arr[i].first);
		pend_chain.push_back(arr[i].second);
	}
	
	size_t pend_size = pend_chain.size();
	std::cout << "---------- main chain ---------" << std::endl;
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
	std::cout << "--------- pend chain ----------" << std::endl;
	for (size_t i = 0; i < pend_chain.size(); i++)
		std::cout << pend_chain[i] << " ";
	std::cout << std::endl;

	std::cout << "pend size = " << pend_size << std::endl;

	
	// for (size_t i = 0; i < pairs_size; i++) {
	// 	if (arr[i * 2] < arr[i * 2 + 1])
	// 	   std::swap(arr[i * 2], arr[i * 2 + 1]);
	// }
	// print_vector(arr);
	// for (size_t i = 0; i < pairs_size - 1; i++) {
	// 	if (arr[i * 2] > arr[i * 2 + 2]) {
	// 		std::swap(arr[i * 2], arr[i * 2 + 2]);
	// 		std::swap(arr[i * 2 + 1], arr[i * 2 + 3]);
	// 	}
	// }
	std::cout << "-------------------" << std::endl;
	// std::swap(arr[0], arr[1]);
	print_vector(arr);
	std::cout << "generating jacobsthalsequence" << std::endl;
	std::vector<size_t> jacobsthals_s = g_jacobsthalsequence(arr.size() + 2);
	print_sequence(jacobsthals_s);

	// sroting using jacobsthals sequence
	// int k = 0;
	// while (pend_chain.size() > 0) {
	// 	main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[k]), pend_chain[k]);
	// 	pend_chain.erase(pend_chain.begin() + k);
	// }
	
	for(size_t i = 1; i < jacobsthals_s.size(); i++) {
		size_t index = jacobsthals_s[i];
		while (index >= pend_chain.size())
			index--;
		// for(; index > jacobsthals_s[i - 1]; index--){
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[index]);
		std::cout << "position = " << it - pend_chain.begin() << std::endl;
		main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[index]), pend_chain[index]);
		pend_chain.erase(pend_chain.begin() + index);
		// }
	}

// for (size_t i = 1; i < Jacob.size(); i++){
//         int index = Jacob[i];
//         for (; index > Jacob[i - 1]; index--)
//             vect.insert(std::lower_bound(vect.begin(), vect.end(), pendChain[index]), pendChain[index]);
//     }
	// std::cout << "generating real sequence" << std::endl;
	// std::vector<size_t> real_sequance = g_real_sequence(jacobsthals_s, pend_size);
	// print_sequence(real_sequance);
	
	// // size_t size = arr.size();
	// // for (size_t i = 3; i < size; i++) {
	// // 	int current = arr[i];
	// // 	std::cout << "current = " << current << std::endl;
	// std::cout << "---------- main chain ---------" << std::endl;
	// for (size_t i = 0; i < main_chain.size(); i++)
	// 	std::cout << main_chain[i] << " ";
	// std::cout << std::endl;
	std::cout << "--------- pend chain ----------" << std::endl;
	for (size_t i = 0; i < pend_chain.size(); i++)
		std::cout << pend_chain[i] << " ";
	std::cout << std::endl;
	// size_t j = 0;
	// while (1) {
	// 	size_t i = 0;
	// 	while(real_sequance[j] && real_sequance[j] - i >= pend_chain.size())
	// 		i++;
	// 	// while(i >= 0 && (real_sequance[i] == 0 || real_sequance[i] > pend_chain.size()))
    //     // i--;
   	// 	// if(i < 0) break;
	// 	std::cout << "pend_chain[real_sequance[j] - i] = " << pend_chain[real_sequance[j] - i] << std::endl;
	// 	std::cout << "==> real_sequance[j] = " << real_sequance[j] << " ---- " << "i = " << i << std::endl;
	// 	std::cout << real_sequance[j] << "-" << i << " = " << real_sequance[j] - i << std::endl;
	// 	std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[real_sequance[j] - i]);
	// 	main_chain.insert(it, pend_chain[real_sequance[j] - i]);
	// 	pend_chain.erase(pend_chain.begin() + real_sequance[j] - i);
	// 	if (pend_chain.empty()) {
			if (struggler != -1) {
				std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), struggler);
				main_chain.insert(it, struggler);
			}
	// 		break ;
	// 	}
	// 	// std::cout << "increment [j] = " << j << std::endl;
	// 	j++;
	// 	// while (1);
	// }
	std::cout << "---------- main chain ---------" << std::endl;
	for (size_t i = 0; i < main_chain.size(); i++)
		std::cout << main_chain[i] << " ";
	std::cout << std::endl;
	// std::cout << "--------- pend chain ----------" << std::endl;
	// for (size_t i = 0; i < pend_chain.size(); i++)
	// 	std::cout << pend_chain[i] << " ";
	// std::cout << std::endl;
	// 	if (it != arr.begin() + i) {
	// 		std::cout << "it = " << *it << std::endl;
	// 		arr.erase(arr.begin() + i);
	// 		arr.insert(it, current);
	// 		i--;
	// 	}
	// }
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

std::vector<size_t> PmergeMe::g_real_sequence(std::vector<size_t> jacobsthal_s, int pend_size) {
	std::vector<size_t> real_sequence;
	size_t i = 1;
	bool	out_limit = false;

	while (1)
	{
		size_t x = jacobsthal_s[i];
		std::cout << "x = " << x << std::endl;
		while (x > (size_t)pend_size) {
			x--;
		std::cout << "here" << std::endl;
			out_limit = true;
		}
		if (std::find(real_sequence.begin(), real_sequence.end(), x) == real_sequence.end())
			real_sequence.push_back(x);
		if (out_limit == true)
			break ;
		x--;
		while (std::find(jacobsthal_s.begin(), jacobsthal_s.end(), x) == jacobsthal_s.end()) {
			real_sequence.push_back(x);
			x--;
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

// void PmergeMe::sortDeque() {
// 	mergeInsertSortDeque(deq, 0, deq.size() - 1);
// }

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int left, int right) {
	if (right - left <= 10) {
		insertionSortVector(arr, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertSortVector(arr, left, mid);
		mergeInsertSortVector(arr, mid + 1, right);
		mergeVector(arr, left, mid, right);
	}
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int left, int right) {
	if (right - left <= 10) {
		insertionSortDeque(arr, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertSortDeque(arr, left, mid);
		mergeInsertSortDeque(arr, mid + 1, right);
		mergeDeque(arr, left, mid, right);
	}
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
	std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

	size_t i = 0, j = 0, k = left;
	while (i < leftArr.size() && j < rightArr.size()) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		} else {
			arr[k++] = rightArr[j++];
		}
	}

	while (i < leftArr.size()) {
		arr[k++] = leftArr[i++];
	}

	while (j < rightArr.size()) {
		arr[k++] = rightArr[j++];
	}
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
	std::deque<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::deque<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

	size_t i = 0, j = 0, k = left;
	while (i < leftArr.size() && j < rightArr.size()) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		} else {
			arr[k++] = rightArr[j++];
		}
	}

	while (i < leftArr.size()) {
		arr[k++] = leftArr[i++];
	}

	while (j < rightArr.size()) {
		arr[k++] = rightArr[j++];
	}
}
