#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
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
};

int main() {
    Solution sol;

    std::vector<int> bill1 = {5, 5, 5, 10, 20};
    std::vector<int> bill2 = {5, 5, 10, 10, 20};
    std::vector<int> bill3 = {5, 10};
    std::vector<int> bill4 = {5, 5, 5, 5, 10, 5, 10, 10, 10, 20};

    print(sol.lemonadeChange(bill1));
    print(sol.lemonadeChange(bill2));
    print(sol.lemonadeChange(bill3));
    print(sol.lemonadeChange(bill4));

    return 0;
}
