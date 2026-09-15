#include <algorithm>
#include <cstddef>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    int findContentChildren(std::vector<int>& greedFactors, std::vector<int>& cookiesSizes) {
        std::ranges::sort(greedFactors);
        std::ranges::sort(cookiesSizes);

        size_t cookiesIdx      = 0;
        int    contentChildren = 0;

        for (const int& greed : greedFactors) {
            // Traversing on cookies to get to the best cookie who fulfill the current children greed.
            while (cookiesIdx < cookiesSizes.size() && cookiesSizes[cookiesIdx] < greed) {
                ++cookiesIdx;
            }

            // No cookies left, that can satisfy
            if (cookiesIdx == cookiesSizes.size()) {
                break;
            }

            ++cookiesIdx;
            ++contentChildren;
        }

        return contentChildren;
    }
};

int main() {
    Solution sol;

    std::vector<int> children1 = {1, 2};
    std::vector<int> cookie1   = {1, 1, 2};

    print(sol.findContentChildren(children1, cookie1));

    std::vector<int> children2 = {1, 2};
    std::vector<int> cookie2   = {1, 1, 1};

    print(sol.findContentChildren(children2, cookie2));

    return 0;
}
