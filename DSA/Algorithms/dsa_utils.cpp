#include <iostream>
#include <vector>

template<typename T>
void printArrayElements(const std::vector<T>& elements, const std::string& msg = "Array elements are: "){
    if(elements.empty())
        std::cout << "ARRAY IS EMPTY!!!" << std::endl;

    std::cout << msg << std::endl;

    for(const T& elem:elements)
        std::cout << elem << " ";

    std::cout << std::endl;
}