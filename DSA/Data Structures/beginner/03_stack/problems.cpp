#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

bool isValidParenthesis(std::string str) {
    std::unordered_map<char, char> parenthesis;

    parenthesis.insert({'(', ')'});
    parenthesis.insert({'[', ']'});
    parenthesis.insert({'{', '}'});

    // Checking parenthesis is valid or not.
    std::stack<char> st;

    for (const char& ch : str) {
        if (!st.empty()) {
            if (ch != parenthesis[st.top()] && !parenthesis.count(ch)) {
                return false;
            }
        }

        st.push(ch);
    }

    return true;
}

int main() {
    std::string str1 = "()";
    std::string str2 = "(]";
    std::string str3 = "()[]{}";
    std::string str4 = "([{}])";

    std::cout << "Is Valid Parenthesis: " << str1 << " " << isValidParenthesis(str1) << std::endl;
    std::cout << "Is Valid Parenthesis: " << str2 << " " << isValidParenthesis(str2) << std::endl;
    std::cout << "Is Valid Parenthesis: " << str3 << " " << isValidParenthesis(str3) << std::endl;
    std::cout << "Is Valid Parenthesis: " << str4 << " " << isValidParenthesis(str4) << std::endl;

    return 0;
}