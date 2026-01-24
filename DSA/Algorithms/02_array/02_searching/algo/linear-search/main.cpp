#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int x) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

int main() {
    vector<int> arr = {5, 1, 5, 1, 2, 36, 2};

    cout << "1 in arr is at: " << (linearSearch(arr, 1)) << endl;

    return 0;
}