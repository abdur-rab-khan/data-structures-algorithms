#include <bits/stdc++.h>
using namespace std;

/*
    * In this problem we need to find whether the parenthesis are valid or not, like let me tell you what actually valid parenthesis are.
    * "()[]":-> It's valid because every parenthesis opening has same closing parenthesis.
    * "(]":-> It's invalid because it should look like this "()" but it's isn't.
*/
bool isValidParenthesis(std::string str) {
    // Checking parenthesis is valid or not.
    std::stack<char> st;

    for (const char& ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();
            if (ch == ')' && top != '(')
                return false;
            if (ch == ']' && top != '[')
                return false;
            if (ch == '}' && top != '{')
                return false;
        }
    }

    return st.empty();
}

int main() {
    std::string str1 = "()";
    std::string str2 = "(]";
    std::string str3 = "()[]{}";
    std::string str4 = "([{}])";

    std::cout << "Is Valid Parenthesis: " << str1 << (isValidParenthesis(str1) ? " true" : " false")
              << std::endl;
    std::cout << "Is Valid Parenthesis: " << str2 << (isValidParenthesis(str2) ? " true" : " false")
              << std::endl;
    std::cout << "Is Valid Parenthesis: " << str3 << (isValidParenthesis(str3) ? " true" : " false")
              << std::endl;
    std::cout << "Is Valid Parenthesis: " << str4 << (isValidParenthesis(str4) ? " true" : " false")
              << std::endl;

    return 0;
}