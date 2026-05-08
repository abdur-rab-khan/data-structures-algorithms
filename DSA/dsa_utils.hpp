#pragma once
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <type_traits>
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

namespace dsa {
    inline int testCount = 0;

    template <typename Actual, typename Expected, typename Comparator,
              typename std::enable_if_t<!std::is_invocable_v<Actual>, int> = 0>
    void submitForTesting(const std::string& testName, const Actual& actual,
                          const Expected& expected, Comparator comp) {
        bool ok = comp(actual, expected);
        assert(ok);
        std::cout << "Test No. " << testCount << " (" << testName << ") run successfully"
                  << std::endl;
        testCount++;
    }

    template <typename Actual, typename Expected,
              typename std::enable_if_t<!std::is_invocable_v<Actual>, int> = 0>
    void submitForTesting(const std::string& testName, const Actual& actual,
                          const Expected& expected) {
        submitForTesting(testName, actual, expected, std::equal_to<>());
    }

    template <typename Fn, typename Expected, typename Comparator,
              typename std::enable_if_t<std::is_invocable_v<Fn>, int> = 0>
    void submitForTesting(const std::string& testName, Fn fn, const Expected& expected,
                          Comparator comp) {
        auto actual = std::invoke(fn);
        submitForTesting(testName, actual, expected, comp);
    }

    template <typename Fn, typename Expected,
              typename std::enable_if_t<std::is_invocable_v<Fn>, int> = 0>
    void submitForTesting(const std::string& testName, Fn fn, const Expected& expected) {
        submitForTesting(testName, fn, expected, std::equal_to<>());
    }
}  // namespace dsa

#define SUBMIT_FOR_TESTING(testName, actual, expected) \
    ::dsa::submitForTesting((testName), (actual), (expected))

#define SUBMIT_FOR_TESTING_LAMBDA(testName, lambdaExpr, expected) \
    ::dsa::submitForTesting((testName), (lambdaExpr), (expected))
