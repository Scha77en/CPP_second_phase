#include <iostream>
#include <map>
#include <vector>
#include <set>
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

    std::map<int, int> map;

    map[1] = 1;
    map[2] = 2;
    map[4] = 4;
    map[3] = 3;

    try {
        std::map<int, int>::iterator it = easyfind(map, 4);
        std::cout << "a matching value was found at the index '" << it->first << "'" << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    std::set<int> set = {1, 3, 2, 4, 5};

    try {
        std::set<int>::iterator it = easyfind(set, 2);
        std::cout << "a matching value was found at the index '" << *it << "'" << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
