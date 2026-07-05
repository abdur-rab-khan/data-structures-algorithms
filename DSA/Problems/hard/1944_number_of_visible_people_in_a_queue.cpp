#include <iostream>
#include <stack>
#include <vector>

/*
 * 🟡 So the formula is really simple, Suppose I pick one person and want to check every person to right whether, he can see them or not.
 * 🔶 Suppose the person's heights are [10, 6, 8, 5, 11, 9]:
 *      🔸 So the idea is, If current the person is greater than previous person means they can see them.
 *      🔸 10: visibleHeights = [ 6, 8, 11 ]
 *              🔹min(10, 6) = 6    || maxHeight = 0  || 6 > 0 true
 *              🔹min(10, 8) = 8    || maxHeight = 6  || 8 > 6 true
 *              🔹min(10, 5) = 5    || maxHeight = 8  || 5 > 8 false --> they are hidden because next person to them is greater than him, that's why 10 can't able to see them.
 *              🔹min(10, 11) = 11  || maxHeight = 8  || 11 > 8 true
 *              🔹min(10, 9) = 9    || maxHeight = 11 || 11 > 9 false
 *
 * 🔶 That's the way I can use to solve this problem.
*/
std::vector<int> findVisiblePersonBruteForce(const std::vector<int>& heights) {
    const int size = static_cast<int>(heights.size());

    std::vector<int> result;
    result.reserve(size);

    for (int i = 0; i < size; i++) {
        int maxHeights    = 0;
        int visibleCounts = 0;

        for (int j = i + 1; j < size; j++) {
            if (std::min(heights[i], heights[j]) > maxHeights) {
                visibleCounts++;
            }

            maxHeights = std::max(maxHeights, heights[j]);
        }

        result.push_back(visibleCounts);
    }

    return result;
}

// 👉 Optimized approach
/**
 * 🟡 So the idea, behind this approach is really simple, we are going to traverse from "right to left" instead of "left to right", because of from "left to right" we don't able to solve using "O(n)" time complexity.
 * 🟡 Using "right to left" approach: We'll going track the heights via "stack (data structure)" let's see one by one:
 *      1. visibleCounts [0, 0, 2, 1, 1, 0]
 *          🔸 9 || stack = [] || there is no element to right.
 *          🔸 11 || stack = [ 9 ] || there is one element that's 9, 👉 "9" is smaller than 11 means I can see them, and it's smaller means there is no element to left that can see them. So we'll remove them and count them while removing.
 *          🔸 5 || stack = [ 11 ] || there is one element that 5 can see, but they aren't smaller than 5 either, that's why we add one condition that say's if "stack" isn't empty means there is a boundary (person with the longest height).
 *          🔸 8 || stack = [ 5, 11 ] || there are two elements, So only 5 is smaller than 8 So only "visiblePerson" will be "1", but there is an element who is greater than "8" which is "11" So we'll count via condition.
 */
std::vector<int> findVisiblePersons(const std::vector<int>& heights) {
    std::stack<int>  heightStack;
    std::vector<int> visibleCounts(heights.size(), 0);

    for (int i = static_cast<int>(heights.size()) - 1; i >= 0; i--) {
        int count = 0;

        while (!heightStack.empty() && heightStack.top() < heights[i]) {
            count++;
            heightStack.pop();
        }

        if (!heightStack.empty()) {
            count++;
        }

        visibleCounts[i] = count;
        heightStack.push(heights[i]);
    }

    return visibleCounts;
}

int main() {
    const std::vector<int> heights = {5, 1, 2, 3, 10};

    std::cout << "Number of visible persons are: ";
    for (const int& persons : findVisiblePersons(heights)) {
        std::cout << persons << " ";
    }
    std::cout << std::endl;

    return 0;
}