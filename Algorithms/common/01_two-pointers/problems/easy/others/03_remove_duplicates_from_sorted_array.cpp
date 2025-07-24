#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Remove Duplicates from Sorted Array <================>

    ◉ Given an array "arr", Task is to move all "zeros" to the "end" of the "arr".
    ◉ While maintaining the relative order of all non-zero elements.

    <==================> Examples <================>

    ◉ Example 1: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
                 Output = [1, 2, 4, 3, 5, 0, 0, 0]

    ◉ Example 2: arr[] = [10, 20, 30]
                 Output = 10, 20, 30
*/

// So in this approach time complexity will be o(n) and space complexity will be o(n).
void removeDuplicates(vector<int>& arr) {
    vector<int> newArr;
    unordered_set<int> numMap;

    for (int i = 0; i < arr.size(); i++) {
        if (numMap.find(arr[i]) == numMap.end()) {
            newArr.push_back(arr[i]);
            numMap.insert(arr[i]);
        }
    }

    arr = newArr;
}

// Here tc o(n) and sc o(1)
void removeDuplicatesSecond(vector<int>& arr) {
    int left = 0;
    int right = left + 1;

    while (right < arr.size()) {
        if (arr[left] != arr[right]) {
            left++;
            right++;
        } else {
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};

    removeDuplicates(arr);

    for (const int n : arr)
        cout << n << " ";

    cout << endl;

    return 0;
}