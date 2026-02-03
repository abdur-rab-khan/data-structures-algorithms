#include <bits/stdc++.h>
using namespace std;

// approach 1 o(s.length);
string insertString(string s, char ch, int pos) {
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        // Insert character at given pos
        if (i == pos - 1)
            res.push_back(ch);

        res.push_back(s[i]);
    }

    return res;
}

// approach 2
string insertStringS(string& s, char ch, int pos) {
    // Insert char at give pos
    s.insert(s.begin() + pos, ch);
    return s;
}

int main() {
    // Task: Given an string s, character ch and integer pos, So the task is to add "ch" in "s" at
    // "pos" and return updated string.
    string greet = "ABDE";
    char s = 'c';

    cout << insertString(greet, s, 3) << endl;
    cout << insertStringS(greet, s, 3) << endl;

    return 0;
}