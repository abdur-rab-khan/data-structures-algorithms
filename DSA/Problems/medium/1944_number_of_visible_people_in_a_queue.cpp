#include <iostream>
#include <stack>
#include <vector>

// 👉 Brute force approach
// std::vector<int> findSenablePeoples(const std::vector<int>& heights) {
//     int size = static_cast<int>(heights.size());

//     std::vector<int> result;
//     result.reserve(size);

//     for (int i = 0; i < size; i++) {
//         int maxHeights     = 0;
//         int senableHeights = 0;

//         for (int j = i + 1; j < size; j++) {
//             if (j < size && std::min(heights[i], heights[j]) > maxHeights) {
//                 senableHeights++;
//             }

//             maxHeights = std::max(maxHeights, heights[j]);
//         }

//         result.push_back(senableHeights);
//     }

//     return result;
// }

// 👉 Optimized approach
std::vector<int> findSenablePeoples(const std::vector<int>& heights) {
    int size = static_cast<int>(heights.size());

    std::stack<int>  heightStack;
    std::vector<int> result(size, 0);

    for (int i = size - 1; i >= 0; i--) {
        int heightCounts = 0;

        // Removing invalid (small) height than current height
        while (!heightStack.empty() && heightStack.top() < heights[i]) {
            heightStack.pop();
            heightCounts++;
        }

        if (!heightStack.empty()) {
            heightCounts++;
        }

        result[i] = heightCounts;
        heightStack.push(heights[i]);
    }

    return result;
}

int main() {
    std::vector<int> heights = {5, 1, 2, 3, 10};

    std::cout << "Number of senable persons are: ";
    for (const int& persons : findSenablePeoples(heights)) {
        std::cout << persons << " ";
    }
    std::cout << std::endl;

    return 0;
}