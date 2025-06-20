/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:55:36 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/29 08:03:58 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
    MutantStack<T>& operator=(const MutantStack<T>& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }
    
    const_iterator begin() const { return std::stack<T>::c.cbegin(); }
    const_iterator end() const { return std::stack<T>::c.cend(); }

    reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
    reverse_iterator rend() { return std::stack<T>::c.rend(); }
    
    const_reverse_iterator rbegin() const { return std::stack<T>::c.crbegin(); }
    const_reverse_iterator rend() const { return std::stack<T>::c.crend(); }
    
};

#endif