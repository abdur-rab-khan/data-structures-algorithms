/*
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                       GREEDY TECHNIQUE                                                                         |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🟡 Greedy technique is a rule where we pick the current best optimal choice (that looks best right now) that eventually leads us to have global optimal        |
|     solution, So greedy only works when picking the best choice at each step keeps leading to the correct final answer for that problem.                       |
|                                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                |
| 🔵 Example 1 (Matching type):                                                                                                                                  |
|             Suppose we have "n" children with a greed value each, and "k" cookies with a size each, and we want to satisfy as many children as possible.       |
|             The greedy way is to sort children by greed (smallest first) and cookies by size (smallest first), via this we can give the smallest cookies to    |
|             the children with lowest greedy.                                                                                                                   |
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
     * Give list of children and the list of cookies.
     * Find the number of children we can fulfill there greed
     */
    int findContentChildren(std::vector<int>& greedFactors, std::vector<int>& cookiesSizes) {
        std::ranges::sort(greedFactors);
        std::ranges::sort(cookiesSizes);

        size_t cookiesIdx      = 0;
        int    contentChildren = 0;

        for (const int& greed : greedFactors) {
            // Traversing on cookies to get to the best cookie who fulfill the current children greed.
            while (cookiesIdx < cookiesSizes.size() && cookiesSizes[cookiesIdx] < greed) {
                ++cookiesIdx;
            }

            // No cookies left, that can satisfy
            if (cookiesIdx == cookiesSizes.size()) {
                break;
            }

            ++cookiesIdx;
            ++contentChildren;
        }

        return contentChildren;
    }

    /*
     * 👉 For this "LemonadeChange" problem we have greed criteria at with use gives as "$20 bills", here we have to choice to split this.
     * 👉 Either "$5 * 3 = 15" or "$10 + $5 = 15", but our greed say that use "$10 bill" has much as possible don't waste "$5" because "$5" can use with "$10 and $20" both.
     *    We can't afford to loose it.
     */
    bool lemonadeChange(std::vector<int>& bills) {
        int five = 0, ten = 0;

        for (const int& bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (five == 1) {
                    return false;
                }
                --five;
                ++ten;
            } else {
                if (five >= 1 && ten >= 1) {
                    --five, --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    /*
     * 👉 For this "Jump Game" problem our greed criteria is that, We don't care about the solution I just want to go furthest jump that I can make.
     * 👉 Via this you never go back just visit and update the "maxReach" once maxReach goes beyond the array size that's the position we are looking for.
     * 👉 Unlike backtracking where we would visit to all possible paths and once find dead end we just undo the step but it's not a case with greedy approach.
     */
    bool canJump(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }

        // 🟡 First approach: Traversing from right to left.
        // 🟡 At each step we are checking that if the finalPosition is reachable from current pos.
        // 🟡 If it's reachable mean we can now say that if any number each to current reachable position, then they can eventually to go the end
        // int finalPosition = static_cast<int>(nums.size() - 1);

        // for (int i = nums.size() - 2; i >= 0; --i) {
        //     if (nums[i] + i >= finalPosition) {
        //         finalPosition = i;
        //     }
        // }

        // return finalPosition == 0;

        int maxReach = 0;
        int size     = static_cast<int>(nums.size()) - 1;

        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            if (i > maxReach) {
                return false;
            }
            maxReach = std::max(maxReach, i + nums[i]);
            if (maxReach >= size) {
                return true;
            }
        }

        return false;
    }

    int canCompleteJourney(const std::vector<int>& gas, const std::vector<int>& cost) {}

    void main() {
        // Question 1
        {
            std::vector<int> children1 = {1, 2};
            std::vector<int> cookie1   = {1, 1, 2};

            print(findContentChildren(children1, cookie1));

            std::vector<int> children2 = {1, 2};
            std::vector<int> cookie2   = {1, 1, 1};

            print(findContentChildren(children2, cookie2));
        }

        // Question 2
        {
            std::vector<int> bill1 = {5, 5, 5, 10, 20};
            std::vector<int> bill2 = {5, 5, 10, 10, 20};
            std::vector<int> bill3 = {5, 10};
            std::vector<int> bill4 = {5, 5, 5, 5, 10, 5, 10, 10, 10, 20};

            print(lemonadeChange(bill1));
            print(lemonadeChange(bill2));
            print(lemonadeChange(bill3));
            print(lemonadeChange(bill4));
        }

        // Question 3
        {
            std::vector<int> num1 = {0, 2, 3};
            std::vector<int> num2 = {2, 3, 1, 1, 4};
            std::vector<int> num3 = {3, 2, 1, 0, 4};
            print(canJump(num1), "Can jump to end: ");
            print(canJump(num2), "Can jump to end: ");
            print(canJump(num3), "Can jump to end: ");
        }

        // Question 4
        {
        }

        return;
    }
}  // namespace problems

int main() {
    problems::main();
    return 0;
}
