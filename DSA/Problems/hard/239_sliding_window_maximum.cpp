#include <deque>
#include <iostream>
#include <vector>

std::vector<int> maximumSlidingWindow(std::vector<int> nums, int k) {
    int              leftIdx = 0;
    std::vector<int> maximumValues;
    std::deque<int>  q;

    for (int rightIdx = 0; rightIdx < nums.size(); rightIdx++) {
        int currentNum = nums[rightIdx];

        // Removing smaller elements and adding current to back.
        while (!q.empty() && nums[q.back()] < currentNum) {
            q.pop_back();
        }
        q.push_back(rightIdx);

        // Window size become equal to k
        if (rightIdx - leftIdx + 1 == k) {
            maximumValues.push_back(nums[q.front()]);

            if (leftIdx == q.front()) {
                q.pop_front();
            }
            leftIdx++;
        }
    }

    return maximumValues;
}

int main() {
    std::vector<int> numbers = {1, 3, -1, -3, 5, 3, 6, 7};

    std::cout << "Maximum elements are: ";
    for (const int& n : maximumSlidingWindow(numbers, 3)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
