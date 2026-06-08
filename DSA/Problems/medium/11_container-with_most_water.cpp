#include <algorithm>
#include <iostream>
#include <vector>

/*
* Given:
    Heights: Given in the array

* Find: Two Line "Y-axis" that form a container on "X-axis", Needs to find a container that can store max waters.

--> LET'S SEE HOW IT GOING TO WORK
heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]

* Needs to find two lines that form container and needs to calculate the water.


   |                   |
   |                   |       |
   |   |               |       |
   |   |       |       |       |
   |   |       |   |   |       |
   |   |       |   |   |   |   |
   |   |   |   |   |   |   |   |
|  |   |   |   |   |   |   |   |
--------------------------------->
1  8   6   2   5   4   8   3   7 

leftIndex = 1;
rightIndex = n - 1;

mostWaters = 0;
maxLeft = nums[0] --> 1;
maxRight = nums[n - 1] --> 7;

Iteration 1:
    Between 1 - 7 --> We can only store (rightIdx - leftIdx) * min(1, 7) = 8

Iteration 2:
    Between 8 - 7 --> (rightIdx - leftIdx) --> 7 * min(8, 7) = 7 = 7 * 7 = 49 ✅

*/

int getMaxArea(std::vector<int>& heights) {
    int leftIdx = 0;
    int rightIdx = heights.size() - 1;

    int maxWater = 0;

    while (leftIdx < rightIdx) {
        int minHeight = std::min(heights[leftIdx], heights[rightIdx]);
        maxWater = std::max(maxWater, (rightIdx - leftIdx) * minHeight);

        if (heights[leftIdx] < heights[rightIdx]) {
            leftIdx++;
        } else {
            rightIdx--;
        }
    }

    return maxWater;
}

int main() {
    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << "Max water is: " << getMaxArea(heights) << std::endl;

    return 0;
}