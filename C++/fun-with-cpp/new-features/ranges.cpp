#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "../../../DSA/dsa_utils.h"

void rangeSort() {
    std::vector<int> nums = {5, 1, 7, 8, 10};

    // Without telling any ".begin" or ".end" iterator
    std::ranges::sort(nums);
    print(nums, "After default sorting (accending order): ");

    // Using custom comp function to sort in a decending order
    std::ranges::sort(nums, [](const int& first, const int& last) { return first > last; });
    print(nums, "After decending sorting (using comp): ");
}

void rangeTransformerFilter() {
    std::vector<int> nums = {2, 3, 4, 5, 8, 7, 10};

    // Filter is similar to how "JavaScript (filter) works".
    // Transform is similar to how "JavaScript (map)" works.
    // Either we can pass "container" as a argument or just using pipe ("|").
    // Which take value from the container before the pipe, It could be a "another
    // filter/transform" or just simple vector
    auto x = nums | std::ranges::views::filter([](const int& n) { return n % 2 == 0; }) |
             std::ranges::views::transform([](const int& n) { return n * n; });

    print(x);
}

void rangeEnumerate() {
    std::vector<char> name = {'A', 'B', 'D', 'U', 'R', 'R', 'A', 'B'};

    // It's really nice feature, here we can easily access index with value on
    // "for each" lpp
    for (const auto& [index, ch] : name | std::ranges::views::enumerate) {
        std::cout << "At " << index << " is: " << ch << std::endl;
    }
    std::cout << std::endl;
}

void forEach() {
    std::vector<int> nums {1, 2, 3, 4, 5};

    // It's similar to "JavaScript" "forEach" function
    std::for_each(nums.begin(), nums.end(), [](const int x) { std::cout << x << " "; });
    std::cout << std::endl << std::endl;
}

int main() {
    rangeSort();
    rangeEnumerate();
    forEach();
    rangeTransformerFilter();

    // We can easily generate index number using "iota" function and by using
    // "reverse" we can also easily reverse them
    print((std::ranges::views::iota(0, 10) | std::ranges::views::reverse),
          "Generate numbers between 0 to 9: ");

    return 0;
}
