#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;  // Temp to stored merged arr;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Push all remaining from i
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Push all remaining from j
    while (j <= right) {
        temp.push_back(arr[j++]);
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;  // Find mid point

    // Split array into two parts
    mergeSort(arr, left, mid);       // Split from left to mid
    mergeSort(arr, mid + 1, right);  // Split from mid + 1 till end

    // Merge and sort the splitted array
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