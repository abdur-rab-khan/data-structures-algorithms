#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Optimized appraoch to solve this problem with-in "⌛ o(log n)" and "🗃 o(1)"
vector<int> findKClosestElements(const vector<int>& nums, const int k, const int x) {
    int left = 0;

    // 1. Doing "arr.size() - k", because we'll going to create imaginary window To check whether imaginary window is closer than current on.
    // 1. By substracting with "k" make window smaller enough to create window without any overflow.
    int right = static_cast<int>(arr.size()) - k;

    while(left < right){
        int mid = left + (right - left) / 2;

        if(x - arr[mid] > arr[mid + k] - x){
            // If arr[mid+k] is closer to x than arr[mid], we've proven the answer is strictly to the right of mid. So left = mid + 1 is a confident move, not a guess.
            left = mid + 1;
        }else {
            //  mid is still a possible answer (not proven worse), so keep it in range → right = mid
            right = mid;
        }
    }

    return vector(arr.begin() + left, arr.begin() + left + k);}

// Optimized appraoch but the time-complexity is "⌛ o(n)" and "🗃 o(1)"
vector<int> findKClosestElementTwoPointers(const vector<int>& nums, const int k, const int x) {
    int leftIdx  = 0;
    int rightIdx = static_cast<int>(nums.size()) - 1;

    while (rightIdx - leftIdx >= k) {
        if (x - nums[leftIdx] > nums[rightIdx] - x) {
            leftIdx++;
        } else {
            rightIdx--;
        }
    }

    vector<int> result;
    for (int i = leftIdx; i <= rightIdx; i++) {
        result.push_back(nums[i]);
    }
    return result;
}

int main() {
    const vector<int> nums = {1, 1, 2, 3, 4, 5};

    cout << "Closest elements are: ";
    for (const int& num : findKClosestElements(nums, 4, -1)) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
