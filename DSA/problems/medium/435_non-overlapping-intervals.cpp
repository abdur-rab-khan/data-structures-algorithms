#include <algorithm>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sorting the intervals by end, so that we can easily see the overlapping one.
        std::ranges::sort(intervals,
                          [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

        std::vector<vector<int>> visitedIntervals;
        int                      removedIntervalCount = 0;

        for (const auto& interval : intervals) {
            if (!visitedIntervals.empty()) {
                vector<int> back = visitedIntervals.back();
                if (interval[0] < back[1]) {
                    ++removedIntervalCount;
                    continue;
                }
            }
            visitedIntervals.push_back(interval);
        }

        return removedIntervalCount;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    print(sol.eraseOverlapIntervals(intervals1));

    return 0;
}
