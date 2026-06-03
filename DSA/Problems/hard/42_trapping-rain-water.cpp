#include <vector>
#include <iostream>
#include <algorithm>

int trappedWater(std::vector<int>& heights){
    int leftIdx = 1;
    int rightIdx = heights.size() - 2;

    int maxLeft = heights[0];
    int maxRight = heights[heights.size() - 1];

    int totalTrappedWater = 0;

    while(leftIdx <= rightIdx){
        int minHeight = std::min(maxLeft, maxRight);
        int currentLeft = heights[leftIdx];
        int currentRight = heights[rightIdx];

        if(maxLeft < maxRight){
            if(currentLeft > maxLeft){
                maxLeft = currentLeft;
            }else {
                totalTrappedWater += minHeight - currentLeft;
            }
            leftIdx++;
        }else {
            if(currentRight > maxRight){
                maxRight = currentRight;
            }else {
                totalTrappedWater += minHeight - currentRight;
            }
            rightIdx--;
        }
    }

    return totalTrappedWater;
}

int main(){
    std::vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Total Trapped Water: " << trappedWater(heights) << std::endl;

    std::vector<int> heights2 = {4, 2, 0, 3, 2, 5};
    std::cout << "Total Trapped Water: " << trappedWater(heights2) << std::endl;   

    return 0;
}