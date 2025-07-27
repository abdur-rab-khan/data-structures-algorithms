#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Two Sum Pair with target <================>

    ◉ Given an array "arr" of intergers and "target", Task is find a pair of two whose sum is equals
   to the target.

    <==================> Examples <================>

    ◉ Example 1: arr[] =  {0, -1, 2, -3, 1}, target = -2
                 Output = true
*/

bool checkPairFirst(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == target)
                return true;
        }
    }

    return false;
}

bool checkPairSecond(vector<int>& arr, int target) {
    // Let's perform sorting
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] + arr[right] < target) {
            left++;
        } else if (arr[left] + arr[right] > target) {
            right--;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {0, -1, 2, -3, 1};
    int target1 = 2;

    vector<int> nums2{1, -2, 1, 0, 5};
    int target2 = 0;

    cout << "For " << target1 << " pair is "
         << (checkPairFirst(nums, target1) ? "there" : "not there") << "\n";
    cout << "For " << target2 << " pair is "
         << (checkPairFirst(nums2, target2) ? "there" : "not there") << "\n";

    cout << "For " << target1 << " pair is "
         << (checkPairSecond(nums, target1) ? "there" : "not there") << "\n";
    cout << "For " << target2 << " pair is "
         << (checkPairSecond(nums2, target2) ? "there" : "not there") << "\n";

    cout << *nums.begin() << endl;

    return 0;
}