#include <iostream>
#include "Array.hpp"

int main() {
    // Create an array with 5 elements
    Array<int> array1(5);
    for (size_t i = 0; i < array1.size(); ++i) {
        array1[i] = i + 1;
    }

    // Create a copy of array1
    Array<int> array2(array1);

    // Modify the original array
    array1[0] = 42;

    // Display elements of both arrays
    std::cout << "array1: ";
    for (size_t i = 0; i < array1.size(); ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "array2: ";
    for (size_t i = 0; i < array2.size(); ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << array1[10] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << array2[-1] << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
