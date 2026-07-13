#include <math.h>

#include <iostream>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int size = static_cast<int>(nums.size());

    int rightIdx = 0;
    while (rightIdx < size - 1 && nums[rightIdx] < 0) {
        rightIdx++;
    }

    vector<int> result;

    int leftIdx = rightIdx - 1;
    while (leftIdx >= 0 && rightIdx < size) {
        if (abs(nums[leftIdx]) > abs(nums[rightIdx])) {
            result.push_back(nums[rightIdx] * nums[rightIdx]);
            rightIdx++;
        } else {
            result.push_back(nums[leftIdx] * nums[leftIdx]);
            leftIdx--;
        }
    }

    while (leftIdx >= 0) {
        result.push_back(nums[leftIdx] * nums[leftIdx]);
        leftIdx--;
    }

    while (rightIdx < size) {
        result.push_back(nums[rightIdx] * nums[rightIdx]);
        rightIdx++;
    }

    return result;
}

vector<int> sortedSquaresOpt(vector<int>& nums) {
    int size = static_cast<int>(nums.size());

    int leftIdx  = 0;
    int rightIdx = size - 1;
    int pushPtr  = size - 1;

    vector<int> result(nums.size());

    while (leftIdx <= rightIdx) {
        int leftSqrt  = nums[leftIdx] * nums[leftIdx];
        int rightSqrt = nums[rightIdx] * nums[rightIdx];

        if (leftSqrt > rightSqrt) {
            result[pushPtr] = leftSqrt;
            leftIdx++;
            pushPtr--;
        } else {
            result[pushPtr] = rightSqrt;
            rightIdx--;
            pushPtr--;
        }
    }

    return result;
}

int main() {
    vector<int> nums       = {-4, -1, 0, 3, 10};
    vector<int> sortedSqrt = sortedSquaresOpt(nums);
    printArrayElements(sortedSqrt);
}
