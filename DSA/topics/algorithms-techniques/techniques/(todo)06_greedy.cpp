/*
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       GREEDY TECHNIQUE                                                                         |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🟡 Greedy technique is used to find the best answer by picking the best choice at the current step. Unlike backtracking, once a choice is made here, it       |
|     cannot be undone. So greedy only works when picking the best choice at each step keeps leading to the correct final answer for that problem.              |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🔵 Example 1 (Matching type):                                                                                                                                  |
|             Suppose we have "n" children with a greed value each, and "k" cookies with a size each, and we want to satisfy as many children as possible.       |
|             The greedy way is to sort children by greed (smallest first) and cookies by size (smallest first), then give the smallest cookie that is big       |
|             enough to the least greedy child, moving on one by one.                                                                                            |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🔵 Example 2 (Scheduling type):                                                                                                                                |
|             Suppose you are building a booking system (like a meeting scheduler in your web app, or a timeline of non-overlapping cutscene events in a game). |
|             Each task has a start time and an end time, and you want to fit in the maximum number of non-overlapping tasks.                                    |
|             The greedy way is to sort all tasks by their end time (earliest finishing first), then keep picking the next task only if it starts after the      |
|             end time of the last picked task. Picking the "earliest finishing" task first always leads to the maximum number of tasks fitted.                  |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <algorithm>
#include <cstddef>
#include <vector>

#include "../../../dsa_utils.h"

namespace problems {
    /*
     * Give list of childrens and the list of cookies.
     * Find the number of children we can fulfill there greed
     */
    int findContentChildren(std::vector<int>& greedFactors, std::vector<int>& cookiesSizes) {
        std::ranges::sort(greedFactors);
        std::ranges::sort(cookiesSizes);

        size_t cookiesIdx       = 0;
        int    contentChildrens = 0;

        for (const int& greed : greedFactors) {
            // Traversing on cookies to get to the best cookie who fulfil the current children greed.
            while(cookiesIdx < cookiesSizes.size() && cookiesSizes[cookiesIdx] < greed) {
                ++cookiesIdx;
            }

            // No cookies left, that can satisfy
            if(cookiesIdx == cookiesSizes.size()) {
                break;
            }

            ++cookiesIdx;
            ++contentChildrens;
        }

        return contentChildrens;
    }

    void main() {
        std::vector<int> children1 = {1, 2};
        std::vector<int> cookie1   = {1, 1, 2};

        print(findContentChildren(children1, cookie1));

        std::vector<int> children2 = {1, 2};
        std::vector<int> cookie2   = {1, 1, 1};

        print(findContentChildren(children2, cookie2));

        return;
    }
}  // namespace problems

int main() {
    problems::main();
    return 0;
}
