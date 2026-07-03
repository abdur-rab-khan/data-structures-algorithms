#include <iostream>
#include <vector>

using namespace std;

int longestTurbulentSubarray(const vector<int>& nums) {
    int left        = 0;
    int right       = 0;
    int maxSubarray = 0;

    string prevSign = "";

    while (right < nums.size()) {
        const int diff = right - left + 1;

        if (diff > 1) {
            if (nums[right - 1] == nums[right]) {
                left     = right;
                prevSign = "";
            } else if (nums[right - 1] > nums[right] && prevSign == ">") {
                left     = right - 1;
                prevSign = ">";
            } else if (nums[right - 1] < nums[right] && prevSign == "<") {
                left     = right - 1;
                prevSign = "<";
            }
        }

        maxSubarray = max(maxSubarray, (right - left) + 1);
        right++;
    }

    return maxSubarray;
}

int main() {
    const vector<int> num1 = {100};
    const vector<int> num2 = {4, 8, 12, 16};
    const vector<int> num3 = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    const vector<int> num4 = {9, 4, 8, 4, 2};

    cout << "Longest turbulent subarray is: " << longestTurbulentSubarray(num1) << endl;
    cout << "Longest turbulent subarray is: " << longestTurbulentSubarray(num2) << endl;
    cout << "Longest turbulent subarray is: " << longestTurbulentSubarray(num3) << endl;
    cout << "Longest turbulent subarray is: " << longestTurbulentSubarray(num4) << endl;

    return 0;
}