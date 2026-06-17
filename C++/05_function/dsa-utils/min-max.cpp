#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> nums = {2, 6, 1, 52, 89, 500};

// 👉 Min/Max: Return either "max" value or "min" value from two.
void usingMinMax() {
    std::cout << "--> Using minmax: " << std::endl;

    std::cout << "Min value between 44, 90: " << std::min(44, 90) << std::endl;
    std::cout << "Max Value between 4252, 52: " << std::max(4252, 52) << std::endl;
}

// 👉 min_element: Returns an iterator to the min_element between the given range
void usingMinElement() {
    std::cout << std::endl << "--> Using min_element: " << std::endl;

    auto minElement = std::min_element(nums.begin(), nums.end());

    std::cout << "Min element on nums is: " << *minElement << std::endl;
}

// 👉 max_element: Return an iterator for the max_element between the given range
void usingMaxElement() {
    std::cout << std::endl << "--> Using max_element: " << std::endl;

    std::vector<int>::iterator maxElement = std::max_element(nums.begin(), nums.end());
    std::cout << "Max element on nums is: " << *maxElement << std::endl;
}

// 👉 minmax: Return a pair for min and max value from two value, first represents min and second represents max
void using_minmax() {
    std::cout << std::endl << "--> Using minmax: " << std::endl;

    std::pair<int, int> minmaxValue = std::minmax(700, 200);
    std::cout << "Min value is: " << minmaxValue.first << " -- "
              << "Max value is: " << minmaxValue.second << std::endl;
}

// 👉 clamp: Keep the value between given range, used for clean boundary problems.
// 🔵 clamp(0, 55, 20); // 20 because it's within the range
// 🔵 clamp(0, 55, -100); // 0 because it's become small than lower one
// 🔵 clamp(0, 55, 200); // 55 because it's become greater than higher one
void usingClamp() {
    std::cout << std::endl << "--> Using clamp: " << std::endl;

    std::cout << "55, Keep the value between 0 to 60: " << std::clamp(55, 0, 60) << std::endl;
    std::cout << "100, Keep the value between 0 to 60: " << std::clamp(100, 0, 60) << std::endl;
    std::cout << "-200, Keep the value between 0 to 60: " << std::clamp(-200, 0, 60) << std::endl;
}

int main() {
    usingMinMax();
    usingMinElement();
    usingMaxElement();
    using_minmax();
    usingClamp();

    return 0;
}