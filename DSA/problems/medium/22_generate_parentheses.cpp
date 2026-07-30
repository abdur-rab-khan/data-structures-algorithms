#include <string>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

/*
 * Like we solve previous problems where states are fixed here we construct the answer based on conditions like:
 *      1. We won't start closing until "closedN < opnedN"
 *      2. We won't start opening parentheses till "openedN < n"
*/
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        backTracking(n, 0, 0);
        return result;
    }

   private:
    string         current;
    vector<string> result;

    void backTracking(int n, int openedN, int closedN) {
        if (openedN == n && closedN == n) {
            result.push_back(current);
            return;
        }

        if (openedN < n) {
            current.push_back('(');
            backTracking(n, openedN + 1, closedN);
            current.pop_back();
        }

        if (closedN < openedN) {
            current.push_back(')');
            backTracking(n, openedN, closedN + 1);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    print(sol.generateParenthesis(3), "Valid Parentheses are: ");
    return 0;
}
