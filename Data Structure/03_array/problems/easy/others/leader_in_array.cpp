#include <bits/stdc++.h>
using namespace std;

/*
    <================> LEADER IN ARRAY <================>

    ◎ For this question, Task is to check current element in the array is greater than all
        it's right elements.

    ◎ Example 1:
                arr = [16, 17, 3, 4, 5, 2]
                result = [2, 5, 17]
                explanation:
                            For 2:  At index n - 1 there is not element what's why it's here.
                            For 5: At index n - 2 there is not element greater than 5.
                            For 17: At index n - 5 there is not element greater than 17.
*/

// Naive Approach TIME_COMPLEXITY o(n²)
void leaderArrayN(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[i])
                break;
        }

        if (j == n) {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
}

// Better Approach TIME_COMPLEXITY o(n)
void leaderArrayBT(vector<int> arr) {
    int n = arr.size();
    int maxFromRight = arr[n - 1];
    cout << maxFromRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            maxFromRight = arr[i];
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 50, 5, 2};

    leaderArrayN(arr);
    leaderArrayBT(arr);

    return 0;
}