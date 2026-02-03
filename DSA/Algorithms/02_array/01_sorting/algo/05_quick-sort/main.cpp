#include <bits/stdc++.h>
using namespace std;

int naivePartition(vector<int>& arr, int low, int high) {
    int pivotIdx = 0;
    int pivot = arr[high];

    vector<int> temp;  // Creating temporary arr to store smaller before pivot and greater after
                       // pivot elements.

    for (int i = low; i <= high; i++) {
        if (arr[i] <= pivot) {
            temp.push_back(arr[i]);
        }
    }

    pivotIdx = temp.size() - 1;

    for (int i = low; i <= high; i++) {
        if (arr[i] > pivot) {
            temp.push_back(arr[i]);
        }
    }

    // Copying all the elements from temp into original array.
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return pivotIdx;
}

int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];

    int i = low - 1, j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }

    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    // Make partition and return pivot index, before pivot index all element will smaller
    // and greater after pivot.
    // int partitionIdx = naivePartition(arr, low, high);
    int partitionIdx = hoarePartition(arr, low, high);

    // Split arr into two parts from low to partitionIdx.
    // and from partitionIdx + 1 to high.
    quickSort(arr, low, partitionIdx);
    quickSort(arr, partitionIdx + 1, high);
}

int main() {
    vector<int> arr = {10, 2, 5, 8, 1, 5};

    quickSort(arr, 0, arr.size() - 1);

    for (const int& n : arr) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}