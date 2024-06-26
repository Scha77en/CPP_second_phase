/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:39:43 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/25 19:14:37 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <new>

template <typename T>
Array<T>::Array() : elements(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->length = n;
	this->elements = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other) : elements(NULL), length(0) {
    copyElements(other);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& copy) {
	if (this != &copy) {
		delete[] elements;
		copyElements(copy);
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
	if (index >= length) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= length) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
size_t Array<T>::size() const {
	return length;
}

template <typename T>
void Array<T>::copyElements(const Array& copy) {
	this->length = copy.length;
	this->elements = new T[length];
	std::copy(copy.elements, copy.elements + length, this->elements);
}
