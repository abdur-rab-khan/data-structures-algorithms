#include <algorithm>
#include <cstddef>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sorting the intervals based on the second value
        std::ranges::sort(intervals, [](const auto& a, const auto& b) { return a[1] < b[1]; });

        int removedIntervalsCtn = 0;
        int prevInterval        = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (prevInterval > intervals[i][0]) {
                removedIntervalsCtn++;
                continue;
            }
            prevInterval = intervals[i][1];
        }

        return removedIntervalsCtn;
    }
};

int main() {
    Solution sol;

    std::vector<std::vector<int>> vec1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    print(sol.eraseOverlapIntervals(vec1), "Total overleaped intervals removed: ");

    std::vector<std::vector<int>> vec2 = {{1, 2}, {1, 2}, {1, 2}};
    print(sol.eraseOverlapIntervals(vec2), "Total overleaped intervals removed: ");

    std::vector<std::vector<int>> vec3 = {{1, 2}, {2, 3}};
    print(sol.eraseOverlapIntervals(vec3), "Total overleaped intervals removed: ");

    std::vector<std::vector<int>> vec4 = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    print(sol.eraseOverlapIntervals(vec4), "Total overleaped intervals removed: ");

    return 0;
}
