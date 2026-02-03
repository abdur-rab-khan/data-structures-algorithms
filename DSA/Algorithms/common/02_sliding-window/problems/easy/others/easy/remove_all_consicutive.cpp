#include <bits/stdc++.h>
using namespace std;

/*
    <====================> Remove all consecutive duplicates from a string <====================>

    ◎ Given a string "s", the task is to remove all consecutive duplicates from string "s", and
        return the resultant string.

    -> Example:

    Input: s = "aaaaaaabbbbbbb"
    Output: "ab"

    Input: s = "geeksforgeeks"
    Output: "geksforgeks"

    Input: s = "aabccba"
    Output: "abcba"
*/

// Brute force approach TIME_COMPLEXITY o(n²) SPACE_COMPLEXITY o(1)
void removeDuplicateBR(char* str) {
    int i = 1;

    while (str[i] != '\0') {
        // Check whether if previous value is same as current.
        // If yes than ignore this time that value.
        if (str[i] == str[i - 1]) {
            int j = i - 1;
            while (str[j] != '\0') {
                str[j] = str[j + 1];
                j++;
            }
        } else {
            i++;
        }
    }
}

// Brute force approach using RECURSIVE FUNCTION -> TIME_COMPLEXITY o(n²) and SPACE_COMPLEXITY o(n)
void removeDuplicateR(char* str) {
    // Base case
    if (str[0] == '\0' || str[1] == '\0')
        return;

    if (str[0] == str[1]) {
        // Shift character by one position to the left.
        int i = 0;
        while (str[i] != '\0') {
            str[i] = str[++i];
        }
        removeDuplicateR(str);
    } else {
        // Otherwise, move to the next character in the string.
        removeDuplicateR(str + 1);
    }
}

// Expected approach TIME_COMPLEXITY o(n) and SPACE_COMPLEXITY o(1)
string removeDuplicate(string str) {
    // Do nothing if str is empty
    if (str.empty())
        return str;

    string result = "";

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != str[i + 1]) {
            result += str[i];
        }
    }

    return result;
}

int main() {
    char str[] = "aaaaabbbbbbbb";
    char str1[] = "apple";

    // Brute force method
    cout << "Using Brute force method: " << endl;

    removeDuplicateBR(str);
    cout << "New String is: " << str << endl;

    removeDuplicateBR(str1);
    cout << "New String is: " << str1 << endl;

    // Brute force recursive method.
    cout << "Using Brute force recursive method: " << endl;

    removeDuplicateR(str);
    cout << "New String is: " << str << endl;

    removeDuplicateR(str1);
    cout << "New String is: " << str1 << endl;

    // Expected approach
    cout << "Using expected approach: " << endl;

    cout << "New String is: " << removeDuplicate(str) << endl;
    cout << "New String is: " << removeDuplicate(str1) << endl;

    return 0;
}