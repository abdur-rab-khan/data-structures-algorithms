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

std::vector<int> evaluateMostFrequentElements(const std::vector<int>& nums, int k) {
    if (nums.empty() || k <= 0) {
        return {};
    }

    // Maping elements by it's frequency
    std::unordered_map<int, int> elementsFreq;
    for (const int& n : nums) {
        elementsFreq[n]++;
    }

    // Sorting elements by it's frequency
    std::priority_queue<std::pair<int, int>> maxFreqHeap;
    for (const auto& [num, freq] : elementsFreq) {
        maxFreqHeap.push({freq, num});
    }

    // Build a vector size k, to store elements
    std::vector<int> sortedNums;
    sortedNums.reserve(k);

    for (int i = 0; i < k && !maxFreqHeap.empty(); i++) {
        sortedNums.push_back(maxFreqHeap.top().second);
        maxFreqHeap.pop();
    }

    return sortedNums;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3};

    cout << "Top Most elements are: ";
    for (const int& num : evaluateMostFrequentElements(nums, 2)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}