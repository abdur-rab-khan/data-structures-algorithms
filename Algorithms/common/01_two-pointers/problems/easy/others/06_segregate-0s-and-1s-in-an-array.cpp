#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Segregate 0s and 1s in an array <================>

    ◉ Given an array "arr" of 0s and 1s in random order, So the task is Segregate 0 on left and 1 on
        right.

    <==================> Examples <================>

    ◉ Example 1: arr[] =  {0,1,0,0,1,0,1}
                 Output =  {0, 0, 0, 0, 1, 1, 1}

    ◉ Example 2: s1 = {0, 1, 0}
                 Output = {0, 0, 1}
*/

void segregate01(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // if (arr[left] == 0) {
        //     left++;
        //     continue;
        // } else if (arr[right] == 1) {
        //     right--;
        //     continue;
        // }

        // <===================> OR SIMPLY DO THIS <=================>
        while (arr[left] == 0 && left < right)
            left++;

        while (arr[right] == 1 && left < right)
            right--;

        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 0, 1, 0, 1};
    segregate01(nums);

    for (const int& n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}