#include <bits/stdc++.h>
using namespace std;

// We can't use sliding window here because, there is no condition for stoping the iteration.

// ==> BRUIT FORCE APPROACH
int findMaxLength(vector<int>& nums) {
    int maxSubArraySize = 0;

    for (int i = 0; i < nums.size(); i++) {
        int totalOnes = 0;
        int totalZeros = 0;

        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == 0) {
                totalZeros++;
            } else {
                totalOnes++;
            }

            if (totalZeros == totalOnes) {
                maxSubArraySize = max(maxSubArraySize, (j - i + 1));
            }
        }
    }

    return maxSubArraySize;
}

// ==> TODO: OPTIMIZED APPROACH USING HASHMAP

int main() {
    return 0;
}