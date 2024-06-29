#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found value at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // ************************************************************

    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);

    try {
        std::deque<int>::iterator it = easyfind(deq, 4);
        std::cout << "Found value at index: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // *************************************************************

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(4);
    lst.push_back(2);

    try {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found value at index: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
