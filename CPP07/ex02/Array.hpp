/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:33:15 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/25 19:16:45 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <algorithm>

template <typename T>
class Array {
private:
    T* elements;
    unsigned int length;

    void copyElements(const Array& copy);

public:
    // Default constructor
    Array();

    // Parameterized constructor
    Array(unsigned int n);

    // Copy constructor
    Array(const Array& copy);


    // Assignment operator
    Array& operator=(const Array& copy);

    // Destructor
    ~Array();

    // Subscript operator
    T& operator[](size_t index);


    const T& operator[](size_t index) const;


    // Size function
    size_t size() const;

};

#include "Array.tpp"

#endif