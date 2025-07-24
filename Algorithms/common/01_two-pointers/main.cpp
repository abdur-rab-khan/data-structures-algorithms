#include <bits/stdc++.h>
using namespace std;

/*
    <======================> Two Pointers <======================>

    ◉ Two Pointers technique is very effective to solve these problems such as "two sum with sorted
        array", "closest two sum", "three sum", "four sum", "trapping rain water" and many other
        popular interview questions.
    ◉ So in two pointer technique as name suggest they use two pointers (indices) to traverse on the
        data structure especially on "ARRAY", "STRING", "LINKED-LIST". The pointers often place in
        left-right and moving towards each other or place on the same direction, they are manipulate
        based on certain conditions, often reduce the time complexity from o(n²) to o(n).


    <======================> Example <======================>
    ◉ Example 1:
                    arr = [10, 20, 35, 50], target = 70
                    left = 0, right = 4 - 1 = 3;

                    ◉ Step 1: left = 0, right = 3
                            ◉ arr[left] = 10, arr[right] = 50 = 60 ==> 60 >> left += 1, Why "left +=
                                1" not "right -= 1" because it is sorted arr if sum of both is
                                smaller than target means arr[0] num is smaller to achieve target.
                    ◉ Step 2: left = 1, right = 3
                            ◉ arr[left] = 20, arr[right] = 50 = 70, We found are pair which is
                                {20,50}

*/

void twoSum(vector<int>& num, int target) {
    int left = 0;
    int right = num.size() - 1;

    while (left < right) {
        int sum = num[left] + num[right];

        // Sum match to target
        if (sum == target) {
            cout << num[left] << " - " << num[right] << endl;
            break;
        } else if (sum < target) {
            // In the sorted array always arr[right] will be greater than arr[left].
            // If sum of both is smaller than target which means arr[left] is smaller. than left++;
            left++;
        } else {
            // In the sorted array always arr[right] will be greater than arr[left].
            // If sum of both is greater than target which means arr[right] is larger. than right--;
            right--;
        }
    }
}

void reverseString(string& a) {
    int i = 0;
    int j = a.size() - 1;

    while (i < j) {
        char temp = a[i];

        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
}

int main() {
    string s = "abcdefg";
    vector<int> num1 = {10, 20, 35, 50};

    twoSum(num1, 70);
    reverseString(s);

    cout << s << endl;

    return 0;
}