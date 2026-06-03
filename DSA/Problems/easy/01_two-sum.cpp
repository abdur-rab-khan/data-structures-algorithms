#include <iostream>
#include <unordered_map>
#include <vector>

/*
    * ❌ Problem: You did a pretty bad here, So the problem was you did the brute force approach that worked than you tried a very bad approach:
                  👉 Approach 1: You tried to sort it than, You tried to solve using "two pointers" technique which was very bad because after doing this how do you find the exact idx.
                  👉 Approach 2: It was correct, You use "hashmap" but first you were blank how do I use "hashmap" there, But knowing how to solve the you were "😧 annoyed", It was too simple.
                                    You were already solved these kind of problem but you were blank that the problem. So you use hashmap for tracking the number with idx and find the different
                                    using "diff = target - current", If "diff" is there in hashmap mean we found it. 
*/
std::vector<int> findTwoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIdxMap;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];

        if (numToIdxMap.count(diff)) {
            return {numToIdxMap[diff], i};
        }

        numToIdxMap[nums[i]] = i;
    }

    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};

    std::vector<int> result = findTwoSum(nums, 6);
    std::cout << "Idx are: " << result[0] << " - " << result[1] << std::endl;
}