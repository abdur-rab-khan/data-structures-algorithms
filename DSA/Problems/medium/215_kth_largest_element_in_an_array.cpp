#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    random_device                 rd;
    uniform_int_distribution<int> dist(left, right);

    int pivotPoint   = dist(rd);
    int pivotElement = nums[pivotPoint];
    swap(nums[right], nums[pivotPoint]);

    int leftIdx = left;
    for (int rightIdx = left; rightIdx < right; rightIdx++) {
        if (nums[rightIdx] > pivotElement) {
            swap(nums[rightIdx], nums[leftIdx]);
            leftIdx++;
        }
    }

    swap(nums[leftIdx], nums[right]);
    return leftIdx;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right)
        return nums[left];

    int partitionIdx = partition(nums, left, right);

    if (partitionIdx == k - 1) {
        return nums[k - 1];
    } else if (partitionIdx > k - 1) {
        return quickSelect(nums, left, partitionIdx - 1, k);
    } else {
        return quickSelect(nums, partitionIdx + 1, right, k);
    }
}

int main() {
    int         k    = 2;
    vector<int> nums = {3, 2, 1, 5, 6, 4};

    cout << "Kth largest element is: " << quickSelect(nums, 0, static_cast<int>(nums.size() - 1), k)
         << endl;

    return 0;
}
