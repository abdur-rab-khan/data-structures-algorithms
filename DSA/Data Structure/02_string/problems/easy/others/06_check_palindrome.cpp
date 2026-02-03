#include <bits/stdc++.h>
using namespace std;

/*
    <====================> CHECK PALINDROME <======================>

    ◉ Palindrome is a technique used to check whether original string is same to reverse string.
    ◉ Example: a = "abcdef", rev_a = "fedcba" ==> False
    ◉ Example: a = "aba", rev_a = "aba" ==> True.
*/

// Check palindrome using two pointers technique. tc = o(n), sc = o(1)
bool checkPalindrome1(string a) {
    int i = 0;
    int n = a.size() - 1;

    while (i < n) {
        if (a[i] != a[n])
            return false;

        i++;
        n--;
    }

    return true;
}

// Optimization on above one instead of using two variable we using single one.
bool checkPalindrome2(string a) {
    int n = a.size();

    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[(n - 1) - i])
            return false;
    }

    return true;
}

// Using recursion to check palindrome or not.
bool checkPalindromeUsingRec(string a, int left, int right) {
    if (left > right) {
        return true;
    }

    if (a[left] != a[right])
        return false;

    return checkPalindromeUsingRec(a, left + 1, right - 1);
}

// Function to check if a string is a palindrome
int isPalindrome(string& s) {
    // If reverse string is equal to given string,
    // then it is palindrome.
    return s == string(s.rbegin(), s.rend()) ? 1 : 0;
}

int main() {
    string a = "aba";
    string b = "abcdef";
    string c = "abba";

    cout << checkPalindrome1(a) << endl;
    cout << checkPalindrome1(b) << endl;
    cout << checkPalindrome1(c) << endl;

    cout << "<==============> Second Approach <================>" << endl;

    cout << checkPalindrome2(a) << endl;
    cout << checkPalindrome2(b) << endl;
    cout << checkPalindrome2(c) << endl;

    cout << "<==============> Using Recursion <================>" << endl;

    cout << checkPalindromeUsingRec(a, 0, a.length() - 1) << endl;
    cout << checkPalindromeUsingRec(b, 0, b.length() - 1) << endl;
    cout << checkPalindromeUsingRec(c, 0, c.length() - 1) << endl;

    return 0;
}