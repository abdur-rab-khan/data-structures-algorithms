#include <cctype>
#include <string>
#include <vector>

#include "../../dsa_utils.h"

/*
* On this problem we are needed permutation (possible combination) by transforming single latter either "lowercase" or "uppercase".
*
*/
class Solution {
   public:
    std::vector<std::string> findLetterCasePermutation(const std::string& s) {
        result.clear();

        std::string str = s;
        backTracking(str, "", 0);
        return result;
    }

   private:
    std::vector<std::string> result;

    void backTracking(const std::string& s, std::string current, int index) {
        if (index == static_cast<int>(s.size())) {
            result.push_back(current);
            return;
        }

        char ch = s[index];

        if (std::isalpha(ch)) {
            backTracking(s, current + static_cast<char>(std::tolower(ch)), index + 1);
            backTracking(s, current + static_cast<char>(std::toupper(ch)), index + 1);
        } else {
            backTracking(s, current + ch, index + 1);
        }
    }
};

int main() {
    Solution sol;

    print(sol.findLetterCasePermutation("a1b2"));
    print(sol.findLetterCasePermutation("3z4"));

    return 0;
}
