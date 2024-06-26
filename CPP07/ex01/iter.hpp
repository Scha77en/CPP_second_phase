/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:50:29 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/25 17:19:35 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t size, void (*func)(T const &)) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

template <typename T>
void print(T const &x) {
	std::cout << x << std::endl;
}


#endif