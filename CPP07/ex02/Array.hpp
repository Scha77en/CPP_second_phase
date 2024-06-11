/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:33:15 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/09 14:34:17 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* elements;
    unsigned int length;

public:
    // Default constructor
    Array() : elements(nullptr), length(0) {}

    // Parameterized constructor
    Array(unsigned int n) : elements(new T[n]()), length(n) {}

    // Copy constructor
    Array(const Array& other) : elements(new T[other.length]), length(other.length) {
        for (unsigned int i = 0; i < length; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            length = other.length;
            elements = new T[length];
            for (unsigned int i = 0; i < length; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Size function
    unsigned int size() const {
        return length;
    }
};

// template <typename T>
// class Array
// {
// 	private:
// 		T *array;
// 		unsigned int size;
// 	public:
// 		Array() : array(NULL), size(0) {}
// 		Array(unsigned int n) : array(new T[n]()), size(n) {}
// 		Array(const Array &other) : array(NULL), size(0) {
// 			*this = other;
// 		}
// 		~Array() {
// 			delete[] array;
// 		}
// 		Array &operator=(const Array &other) {
// 			if (this != &other) {
// 				delete[] array;
// 				size = other.size;
// 				array = new T[size];
// 				for (unsigned int i = 0; i < size; i++) {
// 					array[i] = other.array[i];
// 				}
// 			}
// 			return *this;
// 		}
// 		T &operator[](unsigned int i) {
// 			if (i >= size) {
// 				throw std::out_of_range("Index out of range");
// 			}
// 			return array[i];
// 		}
// 		const T &operator[](unsigned int i) const {
// 			if (i >= size) {
// 				throw std::out_of_range("Index out of range");
// 			}
// 			return array[i];
// 		}
// 		unsigned int getSize() const {
// 			return size;
// 		}
// };



#endif