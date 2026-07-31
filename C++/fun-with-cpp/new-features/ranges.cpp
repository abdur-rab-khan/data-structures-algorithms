#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <ranges>
#include <stack>
#include <string>
#include <vector>

#include "../../../DSA/dsa_utils.h"

void rangeSort() {
    std::vector<int> nums = {5, 1, 7, 8, 10};

    // Without telling any ".begin" or ".end" iterator
    std::ranges::sort(nums);
    print(nums, "After default sorting (accending order): ");

    // Using custom comp function to sort in a decending order, "first > last" mean it will sort in an decending order
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

    print(x, "Square of even numbers: ");
}

void rangeEnumerate() {
    std::vector<char> name = {'A', 'B', 'D', 'U', 'R', 'R', 'A', 'B'};

    // It's similar to python "enumerate" function that gives index along with data
    for (const auto& [index, ch] : name | std::views::enumerate) {
        std::cout << "At " << index << " is: " << ch << std::endl;
    }
    std::cout << std::endl;

    std::string convertIntoString = name | std::ranges::to<std::string>();
    std::cout << std::format("My name is: {}", convertIntoString) << std::endl;
}

void forEach() {
    std::vector<int> nums {1, 2, 3, 4, 5};

    // It's similar to "JavaScript" "forEach" function
    std::for_each(nums.begin(), nums.end(), [](const int x) { std::cout << x << " "; });
    std::cout << std::endl << std::endl;
}

std::stack<char> to() {
    // to is a function that converts, source range into any container like "std::vector", "std::map", "list"
    std::string str = "Abdur Rab Khan";

    std::vector<char> intoVector  = std::ranges::to<std::vector<char>>(str);
    auto              intoVector2 = str | std::ranges::to<std::vector<char>>();

    auto capitalize =
        str | std::views::transform([](char ch) { return static_cast<char>(std::tolower(ch)); }) |
        std::views::filter([](char ch) { return std::tolower(ch) != 'a'; });

    print(capitalize, "Here's the capitalize version: ");

    return str |
           std::views::transform([](char ch) { return static_cast<char>(std::toupper(ch)); }) |
           std::ranges::to<std::stack<char>>();
}

int main() {
    rangeSort();
    rangeEnumerate();
    forEach();
    rangeTransformerFilter();

    // "iota", It's similar to pythons "range" function that generates sequence of elements and returns an iterator.
    print((std::views::iota(11, 21) | std::views::reverse), "Generate numbers between 20 to 11: ");

    std::stack<char> nameStack = to();
    std::cout << "Top Char is: " << nameStack.top() << std::endl;

    return 0;
}
