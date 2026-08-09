#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../../dsa_utils.h"

class Solution {
   public:
    int leastInterval(const std::vector<char>& tasks, int n) {
        // Count tasks, to actually know the total tasks count
        std::unordered_map<char, int> freq;
        for (const char& t : tasks)
            freq[t]++;

        // Heap, For tracking the tasks count
        std::priority_queue<int, std::vector<int>> heap;
        for (const auto& [t, count] : freq)
            heap.push(count);

        int time = 0;
        // Queue, Once task is done the task much need to rest for n intervals it's used for that.
        std::queue<std::pair<int, int>> cooldown;

        while (!heap.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front().second < time) {
                heap.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!heap.empty()) {
                int count = heap.top();
                heap.pop();
                count--;
                if (count > 0) {
                    cooldown.push({count, time + n});
                }
            }
        }

        return time;
    }
};

int main() {
    Solution sol;

    print(sol.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2), "The least interval took is: ");
    print(sol.leastInterval({'A', 'C', 'A', 'B', 'D', 'B'}, 1), "The least interval took is: ");
    print(sol.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 3), "The least interval took is: ");
    print(sol.leastInterval({'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'E'}, 2),
          "The least interval took is: ");

    return 0;
}
