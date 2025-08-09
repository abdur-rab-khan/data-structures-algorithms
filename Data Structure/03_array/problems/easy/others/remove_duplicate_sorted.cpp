#include <bits/stdc++.h>
using namespace std;

/*
    <================> REMOVE DUPLICATE FROM SORTED ARRAY <================>

    ◎ For this question, Task is to remove duplicates from sorted array.

    ◎ Example 1:
                arr = [2, 2, 2, 2, 2]
                result = [2]
*/

// Using hashmap -- also works with unsorted
int removeDuplicates(vector<int>& arr) {
    unordered_set<int> s;

    int idx = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            arr[idx++] = arr[i];
        }
    }

    return idx;
}

// Expected approach TIME_COMPLEXITY o(n), SPACE_COMPLEXITY o(1)
int bestApproach(vector<int>& arr) {
    int idx = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            arr[idx++] = arr[i];
        }
    }

    return idx;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 6, 6};
    int arrSize = removeDuplicates(arr);

    vector<int> arr2 = {1, 1, 3, 3, 3, 4, 5, 6, 6};
    int arr2Size = bestApproach(arr2);

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < arr2Size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}