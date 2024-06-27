/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:59:20 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/26 19:22:40 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
	private:
		unsigned int N;
		std::vector<int> v;
		Span();

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void addNumber(int number);
		template <typename i_iter>
		void addNumbers(i_iter begin, i_iter end) {
			if (v.size() + std::distance(begin, end) > N)
				throw std::runtime_error("Not enough space to add numbers");
			while (begin != end) {
    		    addNumber(*begin);
    		    ++begin;
			}
			// v.insert(v.end(), begin, end);
		}
		
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif