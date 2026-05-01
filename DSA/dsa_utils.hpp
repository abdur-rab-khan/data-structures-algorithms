#pragma once
#include <iostream>
#include <string>
#include <vector>

// Template function to print array elements
// Usage: printArrayElements(arr, "Optional message")
template <typename T>
void printArrayElements(const std::vector<T>& elements, const std::string& msg = "") {
    if (elements.empty())
        std::cout << "ARRAY IS EMPTY!!!" << std::endl;

    std::string message = (msg.empty() ? "Array elements are: " : msg);
    std::cout << message;

    std::cout << "[ ";

    for (size_t i = 0; i < elements.size(); ++i) {
        std::cout << elements[i];

        if (i != elements.size() - 1)
            std::cout << ", ";
    }

    std::cout << " ]";

    std::cout << std::endl;
}

int testCount = 0;

template <typename T, typename X>
void submitForTesting() {
    // Calling a function here.

    std::cout << "Test No. " << testCount << " run Successfully" << endl;
    testCount++;
}
