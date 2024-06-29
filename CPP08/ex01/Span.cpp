/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:59:25 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/28 16:12:38 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <algorithm>
#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &copy) {
	if (this != &copy) {
		this->N = copy.N;
		this->v = copy.v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (v.size() >= N)
		throw std::runtime_error("Not enough space to add number");
	v.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (v.size() < 2) {
        throw std::logic_error("Not enough data to calculate span");
    }
    std::vector<int> sortedNumbers = v;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = std::numeric_limits<int>::max();
    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
	if (v.size() <= 1)
		throw std::runtime_error("Not enough data to calculate span");
	int minNumber = *std::min_element(v.begin(), v.end());
    int maxNumber = *std::max_element(v.begin(), v.end());
    return maxNumber - minNumber;
}
