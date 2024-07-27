/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:03:38 by aouhbi            #+#    #+#             */
/*   Updated: 2024/07/27 20:10:48 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num <= 0) {
			throw std::runtime_error("Error: Invalid input");
		}
		vec.push_back(num);
		deq.push_back(num);
	}
}

void PmergeMe::sort() {
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t start, end;
	
	start = clock();
	sortVector();
	// return ;
	end = clock();
	float vecTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	sortDeque();
	end = clock();
	float deqTime = static_cast<float>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
			  << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
			  << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}

void PmergeMe::sortVector() {
	merge_sort_vector(vec);
	// mergeInsertSortVector(vec, 0, vec.size() - 1);
}

void    PmergeMe::merge_sort_vector(std::vector<int>& arr)
{
	size_t pairs_size = arr.size() / 2;

	if (pairs_size == 0)
		return;
	for (size_t i = 0; i < pairs_size; i++) {
		if (arr[i * 2] < arr[i * 2 + 1])
		   std::swap(arr[i * 2], arr[i * 2 + 1]);
	}
	print_vector(arr);
	for (size_t i = 0; i < pairs_size - 1; i++) {
		if (arr[i * 2] > arr[i * 2 + 2]) {
			std::swap(arr[i * 2], arr[i * 2 + 2]);
			std::swap(arr[i * 2 + 1], arr[i * 2 + 3]);
		}
	}
	std::cout << "-------------------" << std::endl;
	std::swap(arr[0], arr[1]);
	print_vector(arr);
	size_t size = arr.size();
	for (size_t i = 3; i < size; i++) {
		int current = arr[i];
		std::cout << "current = " << current << std::endl;
		std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.begin() + i, current);
		if (it != arr.begin() + i) {
			std::cout << "it = " << *it << std::endl;
			arr.erase(arr.begin() + i);
			arr.insert(it, current);
			i--;
		}
	}
	std::cout << "-------------------" << std::endl;
	print_vector(arr);
}

void	PmergeMe::print_vector(std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::sortDeque() {
	mergeInsertSortDeque(deq, 0, deq.size() - 1);
}

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
