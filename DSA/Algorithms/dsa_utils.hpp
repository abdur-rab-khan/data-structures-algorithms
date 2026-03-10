#pragma once
#include <iostream>
#include <vector>

// Template function to print array elements
// Usage: printArrayElements(arr, "Optional message")
template<typename T>
void printArrayElements(const std::vector<T>& elements, const std::string& msg = ""){
    if(elements.empty())
        std::cout << "ARRAY IS EMPTY!!!" << std::endl;

    std::string message = (msg.empty() ? "Array elements are: " : msg);
    std::cout << message;

    for(const T& elem:elements)
        std::cout << elem << " ";

    std::cout << std::endl;
}
