#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../dsa_utils.hpp"

std::vector<int> calculateDailyTemperature(std::vector<int> temps) {}

int main() {
    std::vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> temps2 = {30, 60, 90};
    std::vector<int> temps3 = {20, 30, 50, 60};

    std::string msg = "Daily temps are: ";
    printArrayElements(calculateDailyTemperature(temps1), msg);
    printArrayElements(calculateDailyTemperature(temps2), msg);
    printArrayElements(calculateDailyTemperature(temps3), msg);

    return 0;
}