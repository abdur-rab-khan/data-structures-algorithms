#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
   <================>

    ◉ Given an array "arr" consisting of only 0s, 1s and 2s, Task is to sort the array.
    ◉ i.e, pull 0s, then all 1s and all 2s in last.

    <==================> Examples <================>

    ◉ Example 1: arr[] =  {0, 1, 2, 0, 1, 2}
                 Output =  {0, 0, 1, 1, 2, 2}

    ◉ Example 2: s1 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
                 Output = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
*/

void sort012(vector<int>& arr) {
    int n = arr.size() - 1;
    int c0 = 0, c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            c0++;
        else if (arr[i] == 1)
            c1++;
        else
            c2++;
    }

    int idx = 0;

    for (int i = 0; i < c0; i++)
        arr[idx++] = 0;

    for (int i = 0; i < c1; i++)
        arr[idx++] = 1;

    for (int i = 0; i < c2; i++)
        arr[idx++] = 2;
}

/*
    ◉ In this approach we use three pointer method.
    ◉ "lo" for 0, "mid" for 1, "hi" for 2

    ◉ Traverse over the array till "mid <= hi", according to the value of arr[mid] we have
        three cases.
    ◉ arr[mid] = 0 ==> than swap arr[lo] with arr[mid], than increase mid and lo by 1, because all
                        zero are till index lo - 1 and move to next element so increase mid by 1.
    ◉ arr[mid] = 1 ==> the move to next element so increase mid by 1.
    ◉ arr[mid] = 2 ==> then arr[mid] with arr[hi], than decrease hi by 1, because all two's are from
                        index hi + 1 to n - 1, . Now, we don't move to the next element because the
                        element which is now at index mid can be a 0 and therefore needs to be
                        checked again.

    <=================> Example <==============>

    arr = [ 0, 1, 2, 0, 1, 2 ];
    lo = 0;
    mid = 0;
    hi = arr.size() - 1;

    ◉ Run loop till mid <= hi;

    <=================> Step 1 <================>

    mid             hi
    [0, 1, 2, 0, 1, 2] => Hit condition 1 mid = 0,swap(arr[lo], arr[mid]) lo++, mid++;
    lo

            ||
            ||
            \/

        mid         hi
    [0, 1, 2, 0, 1, 2];
        lo

    <=================> Step 3 <================>

        mid         hi
    [0, 1, 2, 0, 1, 2] => Hit condition 2 mid = 1, mid++;
        lo

            ||
            ||
            \/

           mid      hi
    [0, 1, 2, 0, 1, 2];
        lo

    <=================> Step 4 <================>

           mid      hi
    [0, 1, 2, 0, 1, 2] => Hit condition 3 mid = 2, swap(arr[mid],arr[hi]) hi--;
        lo

            ||
            ||
            \/

           mid   hi
    [0, 1, 2, 0, 1, 2];
        lo

    <=================> Step 5 <================>

           mid   hi
    [0, 1, 2, 0, 1, 2]; ==> Hit condition 3 mid = 2, swap(arr[mid],arr[hi]) hi--

            ||
            ||
            \/

           mid hi
    [0, 1, 1, 0, 2, 2];
        lo

    <=================> Step 6 <================>

           mid hi
    [0, 1, 1, 0, 2, 2]; ==> Hit condition 2 mid = 1, mid++

            ||
            ||
            \/

            mid-hi
    [0, 1, 1, 0, 2, 2];
        lo

    <=================> Step 7 <================>

            mid-hi
    [0, 1, 1, 0, 2, 2]; ==> Hit condition 1, mid = 0; lo++, mid++;

            ||
            ||
            \/

            mid-hi
    [0, 0, 1, 1, 2, 2];
        lo

*/
void sort012S(vector<int>& arr) {
    int lo = 0;
    int mid = lo;
    int hi = arr.size() - 1;

    while (mid <= hi) {
        if (arr[mid] == 0) {
            swap(arr[lo++], arr[mid++]);
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[hi--]);
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    sort012(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    vector<int> arr2 = {0, 1, 2, 0, 1, 2};
    sort012S(arr2);

    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << " ";

    return 0;
}