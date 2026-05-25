#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace easy {
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

    /*
        * In this problem we need to remove all duplicate adjacent, So it goes like this:
            * "abbaca":
                * "a"
                * "ab"
                * "abb" -> "bb" are repeated, So you need to remove them.
                * "a" -> After removing we got this.
                * "aa" -> Again getting duplicate adjacent.
                * "c"
                * "ca"
                * 🟡 So the final answer will be "ca".   
    */
    std::string removeAllAdjacent(std::string str) {
        std::string uniqueStr;

        for (const char& ch : str) {
            if (!uniqueStr.empty()) {
                char top = uniqueStr.back();

                if (ch == top) {
                    uniqueStr.pop_back();
                } else {
                    uniqueStr.push_back(ch);
                }
            } else {
                uniqueStr.push_back(ch);
            }
        }

        return uniqueStr;
    }

    void main() {
        // Question 1.
        std::string str1 = "()";
        std::string str2 = "(]";
        std::string str3 = "()[]{}";
        std::string str4 = "([{}])";

        std::cout << "Is Valid Parenthesis: " << str1
                  << (isValidParenthesis(str1) ? " true" : " false") << std::endl;
        std::cout << "Is Valid Parenthesis: " << str2
                  << (isValidParenthesis(str2) ? " true" : " false") << std::endl;
        std::cout << "Is Valid Parenthesis: " << str3
                  << (isValidParenthesis(str3) ? " true" : " false") << std::endl;
        std::cout << "Is Valid Parenthesis: " << str4
                  << (isValidParenthesis(str4) ? " true" : " false") << std::endl;

        // Question 2.
        std::string str1 = "abbaca";
        std::string str2 = "azxxzy";

        std::cout << "Removed adjacent string is: " << removeAllAdjacent(str1) << std::endl;
        std::cout << "Removed adjacent string is: " << removeAllAdjacent(str2) << std::endl;
    }
};  // namespace easy

int main() {
    easy::main();

    return 0;
}