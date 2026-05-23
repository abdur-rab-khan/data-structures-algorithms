#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(std::string str) {
    // Checking parenthesis is valid or not.
    std::stack<char> st;

    for (const char& ch : str) {
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }else{
            if(st.empty())
                return false;

            char top = st.top();
            st.pop();
            if(ch == ')' && top != '(') return false;
            if(ch == ']' && top != '[') return false;
            if(ch == '}' && top != '{') return false;
        }
    }

    return st.empty();
}

int main() {
    std::string str1 = "()";
    std::string str2 = "(]";
    std::string str3 = "()[]{}";
    std::string str4 = "([{}])";

    std::cout << "Is Valid Parenthesis: " << str1 << (isValidParenthesis(str1) ? " true" : " false") << std::endl;
    std::cout << "Is Valid Parenthesis: " << str2 << (isValidParenthesis(str2) ? " true" : " false") << std::endl;
    std::cout << "Is Valid Parenthesis: " << str3 << (isValidParenthesis(str3) ? " true" : " false") << std::endl;
    std::cout << "Is Valid Parenthesis: " << str4 << (isValidParenthesis(str4) ? " true" : " false") << std::endl;

    return 0;
}