#include <bitset>
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

/**
 * I've solved this problem using bit manipulation.
 */
int findLongestSubstringWithoutRepeatingBit(const std::string& str) {
    std::bitset<128> charBits;
    int              longestSubstring = 0;

    auto isCharPresent = [&](const char& ch) -> bool { return charBits.test(ch); };
    auto toggleCharBit = [&](const char& ch) -> void { charBits.flip(ch); };

    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < static_cast<int>(str.size()); rightIdx++) {
        // Shrink from left until the duplicate is removed
        while (isCharPresent(str[rightIdx])) {
            toggleCharBit(str[leftIdx]);
            leftIdx++;
        }

        // Mark current char as seen in the window.
        toggleCharBit(str[rightIdx]);

        longestSubstring = std::max(longestSubstring, (rightIdx - leftIdx + 1));
    }

    return longestSubstring;
}

int main() {
    std::string str = "pwwkew";
    std::cout << "Max subarray length is: " << findLongestSubstringWithoutRepeating(str)
              << std::endl;

    return 0;
}