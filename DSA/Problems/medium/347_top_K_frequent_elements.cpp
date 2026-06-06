#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

vector<int> findTopKFrequentElements(const vector<int>& nums, int k) {
    // Guard against invalid inputs:
    if (nums.empty() || k <= 0) {
        return {};
    }

    unordered_map<int, int> numFrequency;
    for (const int& num : nums) {
        numFrequency[num]++;
    }

    // Max-Heap ordered by frequency so the most frequent element is always on top
    priority_queue<pair<int, int>> maxFreqHeap;
    for (auto& [num, freq] : numFrequency) {
        maxFreqHeap.push({freq, num});
    }

    vector<int> result;
    result.reserve(k);
    for (int i = 0; i < k && !maxFreqHeap.empty(); i++) {
        result.push_back(maxFreqHeap.top().second);
        maxFreqHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3};

    cout << "Top Most elements are: ";
    for (const int& num : findTopKFrequentElements(nums, 2)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}