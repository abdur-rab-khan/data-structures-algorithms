#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

static std::vector<int> nums = {6, 7, 2, 9, 25, 68, 190};

void print(std::vector<int> vec) {
    std::cout << "Elements are: ";
    for (const int& n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// 👉 Binary Search: It's a build-in for doing "binary search" and it returns either true/false.
void usingBinarySearch() {
    std::cout << "Is 190 exists on nums: " << std::binary_search(nums.begin(), nums.end(), 190)
              << std::endl;
    std::cout << "Is 55 exists on nums: " << std::binary_search(nums.begin(), nums.end(), 55)
              << std::endl;
}

// 👉 Upper bound: Return an iterator for first element ""first element > value"""
void usingUpperBound() {
    std::cout << std::endl << "--> Upper Bound: " << std::endl;

    // Using auto as a type
    auto upperBound1 = std::upper_bound(nums.begin(), nums.end(), 2);

    // Using "vector iterator" as a type
    std::vector<int>::iterator upperBound2 = std::upper_bound(nums.begin(), nums.end(), 68);

    std::cout << "First element greater than 68: " << *upperBound1 << std::endl;  // 6
    std::cout << "First element greater than 2: " << *upperBound2 << std::endl;   // 190
}

// 👉 Lower bound: Return an iterator for first element ""first element >= value""
void usingLowerBound() {
    std::cout << std::endl << "--> Lower Bound: " << std::endl;

    auto lowerBound1 = std::lower_bound(nums.begin(), nums.end(), 3);
    auto lowerBound2 = std::lower_bound(nums.begin(), nums.end(), 180);

    std::cout << "First element lower than 7: " << *lowerBound1 << std::endl;    // 6
    std::cout << "First element lower than 190: " << *lowerBound2 << std::endl;  // 190
}

int main() {
    usingBinarySearch();
    usingUpperBound();
    usingLowerBound();

    return 0;
}