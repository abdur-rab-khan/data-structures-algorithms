#include <bits/stdc++.h>

#include "../../dsa_utils.hpp"
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> numsFreq;

    // Making frequency hashmap with nums counts
    for (const int n : nums2) {
        numsFreq[n] = true;
    }

    int numsOneIdx = 0;
    int numsTwoIdx = 0;

    for (int numsOneIdx = 0; numsOneIdx < nums1.size(); numsOneIdx++) {
        int numsOne = nums1[numsOneIdx];

        if (numsFreq[numsOne]) {
            numsFreq.erase(numsOne);

            // Let's add "num"
            nums2[numsTwoIdx++] = numsOne;
        }
    }

    nums2.resize(numsTwoIdx);
    return nums2;
}

int main() {
    auto sameElements = [](vector<int> actual, vector<int> expected) {
        sort(actual.begin(), actual.end());
        sort(expected.begin(), expected.end());
        return actual == expected;
    };

    dsa::submitForTesting(
        "basic duplicates",
        []() {
            vector<int> nums1 = {1, 2, 2, 1};
            vector<int> nums2 = {2, 2};
            return intersection(nums1, nums2);
        },
        vector<int> {2}, sameElements);

    dsa::submitForTesting(
        "unordered",
        []() {
            vector<int> nums1 = {4, 9, 5};
            vector<int> nums2 = {9, 4, 9, 8, 4};
            return intersection(nums1, nums2);
        },
        vector<int> {4, 9}, sameElements);

    dsa::submitForTesting(
        "no overlap",
        []() {
            vector<int> nums1 = {1, 3, 5};
            vector<int> nums2 = {2, 4, 6};
            return intersection(nums1, nums2);
        },
        vector<int> {}, sameElements);

    return 0;
}