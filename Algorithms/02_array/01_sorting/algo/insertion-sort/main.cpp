#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j -= 1;
        }

        arr[j] = key;
    }
}

void printArr(vector<int> arr) {
    // Print all elements of arr
    for (const int& n : arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {11, 12, 13, 5, 6};

    insertionSort(arr);
    printArr(arr);

    return 0;
}