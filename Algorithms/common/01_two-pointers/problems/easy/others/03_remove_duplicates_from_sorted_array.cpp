#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Remove Duplicates from Sorted Array <================>

    ◉ Given an array "arr", Task is to all duplicate elements.
    ◉ While maintaining the relative order elements.

    <==================> Examples <================>

    ◉ Example 1: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
                 Output = [1, 2, 3, 4, 5, _, _, _, _]

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
int removeDuplicatesSecond(vector<int>& arr) {
    int idx = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            arr[idx++] = arr[i];
        }
    }

    return idx;
}

int removeDuplicatesThird(vector<int>& arr) {
    int left = 1;
    int right = 1;

    while (right < arr.size()) {
        if (arr[right] != arr[right - 1]) {
            arr[left++] = arr[right];
        }

        right++;
    }

    return left;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};

    int idx = removeDuplicatesSecond(arr);

    for (int i = 0; i < idx; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 2, 2, 3, 4, 4, 4, 5, 5};

    int idx2 = removeDuplicatesThird(arr2);

    for (int i = 0; i < idx2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}