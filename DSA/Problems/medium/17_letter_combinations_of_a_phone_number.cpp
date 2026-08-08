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
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        backTracking(digits, result, "", 0);
        return result;
    }

   private:
    std::array<std::string, 8> DIGIT_MAPPING = {"abc", "def",  "ghi", "jkl",
                                                "mno", "pqrs", "tuv", "wxyz"};

    void backTracking(std::string digits, std::vector<std::string>& result, std::string current,
                      int index) {
        if (index >= static_cast<int>(digits.size())) {
            result.push_back(current);
            return;
        }

        std::string letters = DIGIT_MAPPING[digits[index] - '2'];
        for (const char& ch : letters) {
            backTracking(digits, result, current + ch, index + 1);
        }
    }
};

int main() {
    Solution sol;
    print(sol.letterCombinations("234"));
    print(sol.letterCombinations("2"));

    return 0;
}
