/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:55:31 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/27 14:48:18 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "MutantStack top => " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Mutant size => " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << "Iterating with regular iterator:" << std::endl;
    while (it != ite) {
        std::cout << "[" << *it << "]" << std::endl;
        ++it;
    }


    std::cout << "Iterating with const iterator:" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    // MutantStack<int>::const_iterator cite = mstack.end();

    while (cit != mstack.end()) {
        std::cout << "[" << *cit << "]" << std::endl;
        ++cit;
    }
    // for (MutantStack<int>::const_iterator cit = mstack.begin(); cit != mstack.end(); ++cit) {
    //     std::cout << *cit << std::endl;
    // }
    std::cout << "Iterating with reverse iterator:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();

    while (rit != mstack.rend()) {
        std::cout << "[" << *rit << "]" << std::endl;
        ++rit;
    }

    std::cout << "Iterating with const reverse iterator:" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();

    while (crit != mstack.rend()) {
        std::cout << "[" << *crit << "]" << std::endl;
        ++crit;
    }
    // MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    // for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
    //     std::cout << *rit << std::endl;
    // }

    // for (MutantStack<int>::const_reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
    //     std::cout << *rit << std::endl;
    // }

    std::stack<int> s(mstack);
    return 0;
}
