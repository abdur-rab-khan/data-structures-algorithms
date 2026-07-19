#include <bits/stdc++.h>
using namespace std;

void reverseStr(string& s, int start, int end) {
    // Loop from both size till middle point
    while (start < end) {
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
}

// Native approach time complexity n(n * k), space complexity o(1)
void leftRotation(string& s, int k) {
    int n = s.size();

    for (int i = 0; i < k; i++) {
        int first = s[0];

        for (int j = 0; j < n; j++)
            s[j] = s[j + 1];

        s[n - 1] = first;
    }
}

// approach 1 time complexity worst case o(n²) = o(n), space complexity o(n)
string leftRotationSecond(string s, int k) {
    string updated = "";

    for (int i = k; i < s.size(); i++) {
        updated.push_back(s[i]);
    }

    for (int i = 0; i < k; i++) {
        updated.push_back(s[i]);
    }

    return updated;
}

void leftRotationUsingRev(string& s, int k) {
    int n = s.size();

    // Performing reverse ==> example s = abcdefg
    // Reverse s[0, k - 1] ==> abc ==> cba ==> cbadefg
    reverseStr(s, 0, k - 1);

    // Reverse s[2, n - 1] ==> defg ==> gfed ==> cbagfed
    reverseStr(s, k, n - 1);

    // Reverse s[0, n - 1] ==> defgabc
    reverseStr(s, 0, n - 1);
}

int main() {
    string s = "GeeksforGeeks";
    string a = "ABCdefg";
    int d = 2;

    leftRotation(s, d);
    leftRotation(a, 3);

    cout << s << endl;
    cout << a << endl;

    s = "GeeksforGeeks";
    a = "ABCdefg";

    leftRotationUsingRev(s, d);
    leftRotationUsingRev(a, 3);

    cout << s << endl;
    cout << a << endl;

    return 0;
}