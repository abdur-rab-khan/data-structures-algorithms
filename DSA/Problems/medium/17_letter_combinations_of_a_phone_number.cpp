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
    vector<string> findLetterCombination(string digits) {
        backTracking(digits, 0);
        return result;
    }

   private:
    array<string, 8> DIGIT_MAPPED = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string         current;
    vector<string> result;

    void backTracking(string digits, int digitIdx) {
        if (digitIdx == static_cast<int>(digits.size())) {
            result.push_back(current);
            return;
        }

        string currentString = DIGIT_MAPPED[digits[digitIdx] - '2'];

        for (const char& ch : currentString) {
            current.push_back(ch);
            backTracking(digits, digitIdx + 1);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.findLetterCombination("234"));

    return 0;
}
