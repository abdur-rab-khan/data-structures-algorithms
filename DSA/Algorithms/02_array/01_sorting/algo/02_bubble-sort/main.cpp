#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();  // Size of an array
    bool swapped = false;

    // Loop all over the array.
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Check individual elements.
        for (int j = 0; j < n - i - 1; j++) {
            // Check whether arr[j] > then arr[j + 1], if yes simply swap it.
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printArr(vector<int> arr) {
    for (const int& n : arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, 2, 1, 16, 20};

    bubbleSort(arr);
    printArr(arr);

    return 0;
}