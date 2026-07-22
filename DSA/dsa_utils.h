#pragma once

#include <cassert>
#include <iostream>
#include <ranges>
#include <string_view>
#include <type_traits>

// Print function declartion for iterable containers like (vector, array, list)
template <typename T>
    requires std::ranges::range<T> && (!std::is_convertible_v<T, std::string_view>)
void print(const T& container, std::string_view msg = "", bool isRoot = true);

// Print function declaration for single elements like (number, float, bool)
template <typename T>
    requires(!std::ranges::range<T> || std::is_convertible_v<T, std::string_view>)
void print(const T& val, std::string_view msg = "", bool isRoot = true);

template <typename T>
    requires std::ranges::range<T> && (!std::is_convertible_v<T, std::string_view>)
void print(const T& container, std::string_view msg, bool isRoot) {
    if (isRoot) {
        std::cout << (!msg.empty() ? msg : "Container elements are: ");
    }

    std::cout << "[ ";
    for (const auto& elem : container) {
        print(elem, "", false);
    }
    std::cout << "] ";

    if (isRoot) {
        std::cout << "\n";
    }
}

template <typename T>
    requires(!std::ranges::range<T> || std::is_convertible_v<T, std::string_view>)
void print(const T& val, std::string_view msg, bool isRoot) {
    if (isRoot) {
        std::cout << (!msg.empty() ? msg : "Container elements are");
        std::cout << ": ";
    }

    if constexpr (std::is_same_v<T, bool>) {
        std::cout << (val ? "true" : "false") << " ";
    } else {
        std::cout << val << " ";
    }

    if (isRoot) {
        std::cout << "\n";
    }
}
