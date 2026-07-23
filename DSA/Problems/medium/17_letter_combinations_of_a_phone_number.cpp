#include <array>
#include <string>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

/*
* In this problem given list of number mapping to string, our task is the make all the possible combination out of mapping string and we can return answer is any order.
* Pick one letter and go deeper and deeper to find all the possible combination of string.
*/
class Solution {
   public:
    Solution() : DIGIT_MAPPING({"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}) {};

    vector<string> findLetterCombination(string digits) {
        backTracking(digits, 0);
        return result;
    }

   private:
    array<string, 10> DIGIT_MAPPING;

    vector<string> result;
    string         currentCombination;

    void backTracking(string digits, int digitIdx) {
        if (digitIdx > static_cast<int>(digits.size()) - 1) {
            result.push_back(currentCombination);
            return;
        }

        const auto currentDigit = DIGIT_MAPPING[digitIdx];

        for (int i = 0; i < static_cast<int>(currentDigit.size()); i++) {
            const auto currentChar = currentDigit[i];

            currentCombination.push_back(currentChar);
            backTracking(digits, digitIdx + 1);

            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.findLetterCombination("23"));

    return 0;
}
