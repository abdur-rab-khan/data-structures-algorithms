#include <bits/stdc++.h>
using namespace std;

/*
    <==================> Reverse a string preserving space positions <================>

    ◉ Given an string "s", Task is to reverse the given string.
    ◉ While preserving the positions of spaces.

    <==================> Examples <================>

    ◉ Example 1: s = "internship at geeks for geeks"
                 Output = "skeegrofsk ee gtapi hsn retni"

    ◉ Example 2: s1 = "abc de"
                 Output = "edc ba"

    ◉ Example 3: s3 = "Help others"
                 Output = "sreh topleH"
*/

// Native Approach to do this ==> time-complexity = o(n) and space-complexity = o(n)
string reverseString(string a) {
    int n = a.size();
    string result(n, '\0');

    for (int i = 0; i < result.size(); i++) {
        if (a[i] == ' ')
            result[i] = ' ';
    }

    int j = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != ' ') {
            while (a[j] == ' ')
                j--;

            result[j] = a[i];
            j--;
        }
    }

    return result;
}

string reverseStringSecond(string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] == ' ') {
            start++;
            continue;
        } else if (str[end] == ' ') {
            end--;
            continue;
        }

        swap(str[start], str[end]);
        start++;
        end--;
    }

    return str;
}

int main() {
    string test1 = "internship at geeks for internship";
    string revTest1 = reverseString(test1);

    cout << revTest1 << "\n";

    string test2 = "internship at geeks for internship";
    string revTest2 = reverseStringSecond(test2);

    cout << revTest2 << "\n";

    return 0;
}