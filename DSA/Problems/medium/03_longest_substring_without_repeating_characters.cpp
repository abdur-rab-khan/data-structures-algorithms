#include <iostream>
#include <string>
#include <vector>

int findLongestSubstringWithoutRepeating(const std::string& str) {
    if (str.empty()) {
        return 0;
    }

    int maxSubstringSize = 0;

    std::vector<int> characterFreqTracker(95, 0);

    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < str.size(); rightIdx++) {
        characterFreqTracker[str[rightIdx] - 32]++;

        while (characterFreqTracker[str[rightIdx] - 32] > 1) {
            characterFreqTracker[str[leftIdx] - 32]--;
            leftIdx++;
        }

        maxSubstringSize = std::max(maxSubstringSize, rightIdx - leftIdx + 1);
    }

    return maxSubstringSize;
}

int main() {
    std::string str = "pwwkew";
    std::cout << "Max subarray length is: " << findLongestSubstringWithoutRepeating(str)
              << std::endl;

    return 0;
}