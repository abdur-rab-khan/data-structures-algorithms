#include <iostream>
#include <stack>
#include <vector>

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
    std::vector<int> heights = {10, 6, 8, 5, 11, 9};

    std::cout << "Number of senable persons are: ";
    for (const int& persons : findSenablePeoples(heights)) {
        std::cout << persons << " ";
    }
    std::cout << std::endl;

    return 0;
}