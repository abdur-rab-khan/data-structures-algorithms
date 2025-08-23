#include <bits/stdc++.h>
using namespace std;

/*
   <=================> find first and last positions of an element in a sorted array <=============>

    ● Given a sorted array (arr[]) with possibly some duplicates, the task is to find first and last
        occurrence of an element x.

        ● NOTE: If the number "x" is not found in array, simply return -1.


   <=================> Examples <=================>

    Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
    Output: 2 5
    Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5

    Input : arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125 ], x = 7
    Output : 6 6
    Explanation: First and last occurrence of 7 is at index 6

    Input: arr[] = [1, 2, 3], x = 4
    Output: -1 -1
    Explanation: No occurrence of 4 in the array, so, output is [-1, -1]
*/

// Using first approach with binary search.
vector<int> findOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int first = -1, last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x && arr[mid - 1] != x) {
            first = mid;
            last = mid;

            while (arr[last + 1] == x)
                last++;

            break;
        }

        if (arr[mid] >= x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    vector<int> occurrence = {first, last};
    return occurrence;
}

// Using second approach with binary search.
int search(vector<int>& arr, int x, bool findFirst) {
    int low = 0, high = arr.size() - 1;
    int idx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            idx = mid;

            if (findFirst == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return idx;
}

vector<int> find(vector<int>& arr, int x) {
    // Return index of first occurrence
    int first = search(arr, x, true);

    // Return index of last occurrence
    int last = search(arr, x, false);

    vector<int> res = {first, last};
    return res;
}

int main() {
    // Finding the occurrence of 5.
    vector<int> arr = {1, 3, 5, 5, 5, 5, 6, 7, 123, 125};
    vector<int> occurrence = findOccurrence(arr, 5);

    cout << "Occurrence of 5 is at: ";
    for (const int& n : occurrence)
        cout << n << " ";
    cout << endl;

    // Finding the occurrence of 7.
    vector<int> arr2 = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    vector<int> occurrence2 = findOccurrence(arr2, 7);

    cout << "Occurrence of 7 is at: ";
    for (const int& n : occurrence2)
        cout << n << " ";
    cout << endl;

    // Finding the occurrence of 4.
    vector<int> arr3 = {1, 2, 3, 4, 8, 9};
    vector<int> occurrence3 = findOccurrence(arr3, 9);

    cout << "Occurrence of 9 is at: ";
    for (const int& n : occurrence3)
        cout << n << " ";
    cout << endl;

    vector<int> occurrence9 = find(arr3, 9);

    cout << "Occurrence of 9 is at: ";
    for (const int& n : occurrence3)
        cout << n << " ";
    cout << endl;

    return 0;
}