#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Assume minium index is "i".
        int min_index = i;

        // Finding minium element present in the array
        // If founded simply override the min_index with current j.
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                // override with current j
                min_index = j;
            }
        }

        // Swap arr[i] with min_index.
        swap(arr[i], arr[min_index]);
    }
}

void printArr(vector<int> arr) {
    for (const int& n : arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> num = {10, 3, 5, 1, 30, 4};

    selectionSort(num);
    printArr(num);

    return 0;
}