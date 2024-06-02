/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:25:09 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/02 13:36:27 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Function to randomly generate an instance of A, B, or C
Base* generate(void) {
    std::srand(std::time(0));
    int random = std::rand() % 3;

    switch(random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return nullptr;
}

// Function to identify the type of object pointed to by p
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Function to identify the type of object referenced by p
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Avoid unused variable warning
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b; // Avoid unused variable warning
        std::cout << "B" << std::endl;
    } catch (const std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c; // Avoid unused variable warning
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {}
}

int main() {
    Base* base = generate();
    identify(base);
    identify(*base);

    delete base;
    return 0;
}
