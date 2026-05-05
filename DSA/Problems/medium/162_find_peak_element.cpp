#include <bits/stdc++.h>
using namespace std;

int findPeekElement(vector<int> nums) {
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;

    while (leftIndex < rightIndex) {
        int mid = leftIndex + (rightIndex - leftIndex) / 2;

        if (nums[mid] < nums[mid + 1]) {
            leftIndex = mid + 1;
        } else {
            rightIndex = mid;
        }
    }

    return rightIndex;
}

int main() {
    cout << "Peek element is: " << findPeekElement({1, 2, 3, 1}) << endl;
    cout << "Peek element is: " << findPeekElement({1, 2, 1, 3, 5, 6, 4}) << endl;

    return 0;
}