#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int pathSize = static_cast<int>(gas.size()) - 1;

        for (int i = 0; i <= pathSize; ++i) {
            int j           = i;
            int gasInTank   = 0;
            int destination = pathSize + i;

            while (j <= destination) {
                int innerIdx = j % gas.size();

                gasInTank += gas[innerIdx];   // add the gas
                gasInTank -= cost[innerIdx];  // deduct the cost

                ++j;
                if (gasInTank < 0) {
                    break;
                }
            }

            if ((i == j % gas.size()) && gasInTank >= 0) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    print(sol.canCompleteCircuit({2, 3, 4}, {3, 4, 3}));
    print(sol.canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}));

    return 0;
}
