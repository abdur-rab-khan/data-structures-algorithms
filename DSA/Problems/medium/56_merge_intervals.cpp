#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// => We Perform sorting to arrange them in a sorted manner so that we can easily perform merge operation on it.
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    // Let's sort them.
    sort(intervals.begin(), intervals.end(),
         [](std::vector<int>& a, std::vector<int>& b) { return a[0] < b[0]; });

    std::vector<std::vector<int>> mIntervals;
    mIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (mIntervals.back()[1] >= intervals[i][0]) {
            mIntervals.back()[1] = std::max(mIntervals.back()[1], intervals[i][1]);
        } else {
            mIntervals.push_back(intervals[i]);
        }
    }

    return mIntervals;
}

int main() {
    std::vector<std::vector<int>>       intervals  = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    const std::vector<std::vector<int>> mIntervals = merge(intervals);

    std::cout << "Elements are: ";
    std::cout << "[ ";
    for (size_t idx = 0; idx < mIntervals.size(); ++idx) {
        const std::vector<int>& i = mIntervals[idx];
        std::cout << "[ ";
        std::cout << i[0] << ", " << i[1];
        std::cout << " ]";

        if (idx + 1 != mIntervals.size()) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;

    return 0;
}