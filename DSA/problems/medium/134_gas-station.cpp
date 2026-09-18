#include <numeric>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    int canCompleteCircuitBruteForce(const vector<int>& gas, const vector<int>& cost) {
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

    /*
     * 🟡 Intusion: If total gas is smaller than the cost, mean it's not possible to complete the circuit.
     *              If gas is there means it's possible, to has path just we need to check each gas station,
     *              with the cost need to go to next station.
     */
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        // Checking the total gas with total cost, to see whether it's possible to complete the circuit
        if (std::accumulate(gas.begin(), gas.end(), 0) <
            std::accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int startPos = 0;
        int totalGas = 0;
        for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
            totalGas += gas[i] - cost[i];

            // Checking if "totalGas" become negative we need to reset and start freshly again.
            if (totalGas < 0) {
                totalGas = 0;
                startPos = i + 1;
            }
        }

        return startPos;
    }
};

int main() {
    Solution sol;

    print(sol.canCompleteCircuit({2, 3, 4}, {3, 4, 3}));
    print(sol.canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}));

    return 0;
}
