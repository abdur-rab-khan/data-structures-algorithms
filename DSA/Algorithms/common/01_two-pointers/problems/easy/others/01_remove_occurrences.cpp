#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Remove All Occurrences of an Element in an Array <================>

    ◉ Given an array "arr" and an interget "ele", task is to remove all occurrence "ele" from "arr"
        in-place and return the number of elements which are not equal to "ele".
    ◉ So if there is "K" number of elements which are not equal to "ele" than the input "arr" should
        be modified such that first "k" elements should not contain the elements which are not equal
        to "ele".

    <==================> Examples <================>

    ◉ Example 1: arr[] = [3, 2, 2, 3], ele = 3
                 Output = 2
                 Modified arr[] = [2,2,_,_]

    ◉ Example 2: arr[] = [0, 1, 3, 0, 2, 2, 4, 2], ele = 2
                 Output = 5
                 Modified arr[] = [0,1,3,0,4,_,_,_]
*/

int removeAllOccurrences(vector<int>& arr, int ele) {
    int left = 0;

    for (int right = 0; right < arr.size(); right++) {
        if (arr[right] != ele) {
            arr[left] = arr[right];

            left++;
        }
    }

    for (const int n : arr)
        cout << n << " ";

    return left;
}

int main() {
    vector<int> num1 = {3, 2, 2, 3};
    vector<int> num2 = {0, 1, 3, 0, 2, 2, 4, 2};

    cout << "For num1 " << removeAllOccurrences(num1, 2) << endl;
    cout << "For num2 " << removeAllOccurrences(num2, 2) << endl;

    return 0;
}