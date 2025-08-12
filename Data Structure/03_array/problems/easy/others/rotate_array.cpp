#include <bits/stdc++.h>
using namespace std;

/*
    <===================> ROTATE ARRAY <===================>

    ◎ Rotation in an array is defined as re-arranging the element in an array by shifting each
        element to a new position. It is done either "clockwise" or "anticlock-wise".


    <=========> EXAMPLE <=========>

    ◎ Example 1 (Right Rotation => Clock-wise):
                arr = [1, 2, 3, 4, 5, 6]

                >> Start Rotating
                arr = [6, 1, 2, 3, 4, 5]
                arr = [5, 6, 1, 2, 3, 4]

    ◎ Example 2 (Left Rotation => anticlock-wise):
                arr = [1, 2, 3, 4, 5, 6]

                >> Start Rotating
                arr = [2, 3, 4, 5, 6, 1]
                arr = [3, 4, 5, 6, 1, 2]
*/

void naiveRotation(vector<int>& arr, int d) {
    int n = arr.size();

    for (int i = 0; i < d; i++) {
        int start = arr[0];

        int j;
        for (j = 1; j < n; j++) {
            arr[j - 1] = arr[j];
        }

        arr[j - 1] = start;
    }
}

void tempRotation(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> temp;

    // Start from d to n and put into temp
    for (int i = d; i < n; i++) {
        temp.push_back(arr[i]);
    }

    // Push all remaining one from 0 to d - 1 at the temp of temp
    for (int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }

    // Print all of them
    for (const int& n : temp)
        cout << n << " ";
    cout << endl;
}

// TODO: Learn Again about Juggling Algorithm
void usingJugglingAlgorithm(vector<int>& arr, int d) {
    // Size of an array "arr"
    int n = arr.size();

    int cycle = __gcd(n, d);

    for (int i = 0; i < cycle; i++) {
        int currIdx = i, nextIdx;
        int currElem = arr[currIdx], nextElem;

        // Rotating element till currIdx == i
        do {
            nextIdx = (currIdx + d) % n;
            nextElem = arr[nextIdx];

            arr[nextIdx] = currElem;

            currElem = nextElem;

            // Moving to the next index
            currIdx = nextIdx;
        } while (currIdx != i);
    }
}

void rotationMethod(vector<int>& arr, int d) {
    int n = arr.size();

    d %= n;

    // Reverse the entire array
    reverse(arr.begin(), arr.end());

    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining from d to n - 1 elements;
    reverse(arr.begin() + d, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    naiveRotation(arr, 4);

    for (const int& n : arr)
        cout << n << " ";
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    tempRotation(arr2, 2);

    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotationMethod(arr3, 4);

    for (const int& n : arr3)
        cout << n << " ";
    cout << endl;

    vector<int> arr4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    usingJugglingAlgorithm(arr4, 2);

    for (const int& n : arr4)
        cout << n << " ";
    cout << endl;

    return 0;
}