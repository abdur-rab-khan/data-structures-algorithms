#include <bits/stdc++.h>

#include "../../dsa_utils.hpp"
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    std::unordered_set<int> setA;
    for (const int& n : a) {
        setA.insert(n);
    }

    std::unordered_set<int> setB;
    for (const int& n : b) {
        setB.insert(n);
    }

    int idx = 0;
    std::vector<int> intersecNum;
    for (const int& n : setA) {
        if (setB.count(n)) {
            intersecNum.push_back(n);
        }
    }

    return intersecNum;
}

int main() {
    // Input 1:
    std::vector<int> numbers1 = {1, 2, 2, 1};
    std::vector<int> numbers2 = {2, 2};

    std::vector<int> intersec = intersection(numbers1, numbers2);

    std::cout << "Intersection elements are: ";
    for (const int& n : intersec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Input 2:
    std::vector<int> numbers3 = {4, 9, 5};
    std::vector<int> numbers4 = {9, 4, 9, 8, 4};

    std::vector<int> intersec2 = intersection(numbers3, numbers4);

    std::cout << "Intersection elements are: ";
    for (const int& n : intersec2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}