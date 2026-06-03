#include <iostream>
#include <string>
#include <unordered_set>

int findLongestWithoutRepeatingSubstring(const std::string& str) {
    if (str.empty()) {
        return 0;
    }

    int maxSubstringLength = 0;

    std::unordered_set<char> windowCharacters;

    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < str.size(); rightIdx++) {
        while (windowCharacters.count(str[rightIdx])) {
            windowCharacters.erase(str[leftIdx]);
            leftIdx++;
        }

        windowCharacters.insert(str[rightIdx]);
        maxSubstringLength = std::max(maxSubstringLength, rightIdx - leftIdx + 1);
    }

    return maxSubstringLength;
}

int main() {
    std::string str = "pwwkew";
    std::cout << "Max subarray length is: " << findLongestWithoutRepeatingSubstring(str)
              << std::endl;

    return 0;
}