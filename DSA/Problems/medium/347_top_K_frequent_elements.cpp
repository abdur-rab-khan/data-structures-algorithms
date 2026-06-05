#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

vector<int> findTopKFrequentElements(const vector<int>& nums, int k) {
    unordered_set<int> lastSeenTracker;

    vector<int> topMostFrequentElements;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (lastSeenTracker.count(nums[i]))
            continue;

        int currentNumCount = 0;
        int currentNum      = nums[i];

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == currentNum) {
                currentNumCount++;
            }
        }

        if (currentNumCount >= k) {
            topMostFrequentElements.push_back(currentNum);
        }
        lastSeenTracker.insert(currentNum);
    }

    return topMostFrequentElements;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 3, 3, 3, 2};

    cout << "Top Most elements are: ";
    for (const int& num : findTopKFrequentElements(nums, 2)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}