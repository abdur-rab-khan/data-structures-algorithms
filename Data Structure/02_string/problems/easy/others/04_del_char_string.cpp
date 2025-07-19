#include <bits/stdc++.h>
using namespace std;

string deleteString(string s, char ch) {
    string res = "";

    for (const char c : s) {
        if (c != ch) {
            res += c;
        }
    }

    return res;
}

int main() {
    // Task: Given an string s and char ch, Task is to remove character from given s.
    string greet = "Hello world!";
    char ch = '!';

    cout << deleteString(greet, ch);
    return 0;
}