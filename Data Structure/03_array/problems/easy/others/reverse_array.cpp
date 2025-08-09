#include <bits/stdc++.h>
using namespace std;

// Reverse the array TIME_COMPLEXITY o(n)
void reverseArr(vector<int>& arr) {
    int n = arr.size() - 1;

    for (int i = 0; i <= n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i];
        arr[n - i] = temp;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    reverseArr(arr);

    for (const auto& n : arr) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}