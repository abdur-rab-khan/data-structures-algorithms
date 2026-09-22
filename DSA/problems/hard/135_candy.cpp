#include <algorithm>
#include <numeric>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    int candy(const vector<int>& ratings) {
        vector<int> answer(ratings.size(), 1);
        int         size = static_cast<int>(ratings.size());

        // Pass 1: Travel from left to right
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                answer[i] = answer[i - 1] + 1;
            }
        }

        // Pass 2: Travel from right to left
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                answer[i] = max(answer[i], answer[i + 1] + 1);
            }
        }

        return accumulate(answer.begin(), answer.end(), 0);
    }
};

int main() {
    Solution sol;

    print(sol.candy({1, 0, 2}), "Total candy took: ");
    print(sol.candy({1, 2, 2}), "Total candy took: ");
    print(sol.candy({1, 2, 5, 4, 3, 2, 1}), "Total candy took: ");

    return 0;
}
