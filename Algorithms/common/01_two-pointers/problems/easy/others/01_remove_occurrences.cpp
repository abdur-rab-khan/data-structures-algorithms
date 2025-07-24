#include <bits/stdc++.h>
using namespace std;

int removeAllOccurrences(vector<int>& arr, int ele) {
    int left = 0;

    for (int right = 0; right < arr.size(); right++) {
        if (arr[right] != ele) {
            arr[left] = arr[right];
            left++;
        }
    }

    return left;
}

int main() {
    vector<int> num1 = {3, 2, 2, 3};
    vector<int> num2 = {0, 1, 3, 0, 2, 2, 4, 2};

    cout << "For num1 " << removeAllOccurrences(num1, 2) << endl;
    cout << "For num2 " << removeAllOccurrences(num2, 2) << endl;

    return 0;
}