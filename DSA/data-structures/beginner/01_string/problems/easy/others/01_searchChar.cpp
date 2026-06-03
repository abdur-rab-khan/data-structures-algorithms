#include <bits/stdc++.h>

int searchChar(std::string s, char ch) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ch) {
            return i;
        }
    }

    return -1;
}

// Using in-build function
int searchCharS(std::string s, char ch) {
    size_t idx = s.find(ch);

    // When these functions ('find', 'rfind', 'find_last_of', 'find_first_of') not found return
    // std::string:npos
    if (idx != std::string::npos) {
        return idx;
    }

    return -1;
}

int main() {
    std::string name = "Abdur Rab Khan";
    char s1 = 'l';
    char s2 = 'n';

    std::cout << "Finding " << s1 << " in name " << searchChar(name, s1) << "\n";
    std::cout << "Finding " << s2 << " in name " << searchChar(name, s2) << "\n";

    std::cout << "<==========> Second Method <============>" << "\n";
    std::cout << "Finding " << s1 << " in name " << searchCharS(name, s1) << "\n";
    std::cout << "Finding " << s2 << " in name " << searchCharS(name, s2) << "\n";

    return 0;
}