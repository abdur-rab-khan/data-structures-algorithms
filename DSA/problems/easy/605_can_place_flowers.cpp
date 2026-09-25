#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = static_cast<int>(flowerbed.size());

        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                // The idea here we need to place flower bed if it's adjacent don't have, and we need to plant maximum number of flowers.
                // Means, but of start and end we only need to see the just either left or right side.
                const bool isLeftValid  = i == 0 || (flowerbed[i - 1] == 0);
                const bool isRightValid = i == size - 1 || (flowerbed[i + 1] == 0);
                if (isLeftValid && isRightValid) {
                    --n;
                    flowerbed[i] = 1;
                }
            }
        }

        return n <= 0;
    }
};

int main() {
    Solution sol;

    vector<int> flowerbed1 = {0, 0, 0};
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    vector<int> flowerbed3 = {1, 0, 0, 0, 1};

    print(sol.canPlaceFlowers(flowerbed1, 2));
    print(sol.canPlaceFlowers(flowerbed2, 1));
    print(sol.canPlaceFlowers(flowerbed3, 2));

    return 0;
}
