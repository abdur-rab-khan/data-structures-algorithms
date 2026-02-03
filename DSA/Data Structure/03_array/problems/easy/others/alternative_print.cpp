#include <bits/stdc++.h>
using namespace std;

// Naive approach to print
void naivePrint(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        if (i % 2 == 0)
            continue;

        cout << arr[i - 1] << " ";
    }
    cout << endl;
}

// Best Approach
void bestPrint(int arr[], int size) {
    for (int i = 0; i < size; i += 2) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Naive approach to print
void recursivePrint(int arr[], int size, int start = 1) {
    if (start == size) {
        cout << endl;
        return;
    }

    if (start % 2 != 0) {
        cout << arr[start - 1] << " ";
    }

    recursivePrint(arr, size, start + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bestPrint(arr, n);
    naivePrint(arr, n);
    recursivePrint(arr, n);

    return 0;
}