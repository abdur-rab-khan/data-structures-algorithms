#include <bits/stdc++.h>
using namespace std;

// This function is responsible for merge all divided array into single array.
void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining of left
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining of right
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// This function is responsible for dividing the array in to subarray
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Finally print sorted array
void printArr(vector<int> sortedArr) {
    // Printing all elements of array
    for (const int& n : sortedArr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {38, 27, 43, 10};

    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);

    return 0;
}