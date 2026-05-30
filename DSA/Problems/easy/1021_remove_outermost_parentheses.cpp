#include <iostream>
#include <string>

/*
    * In this approach with are using with counter variable called depth, the problem in me is we can’t feature it out we can use depth in this approach for tracking outer parentheses and inner parentheses.
    * So next time when we are going to solve the problem "please please please", break down the question into separate chunks. Then feature out what things are needed to solve this problem.
*/
std::string removeOuterMostParentheses(std::string& parentheses) {
    if (parentheses.empty()) {
        return "";
    }

    int depth = 0;
    std::string result = "";

    for (const char& bracket : parentheses) {
        if (bracket == '(') {
            if (depth > 0) {
                result.push_back(bracket);
            }

            depth++;
        } else {
            depth--;

            if (depth > 0) {
                result.push_back(bracket);
            }
        }
    }

    return result;
}

int main() {
    std::string parentheses1 = "(()())(())";
    std::string parentheses2 = "(()())(())(()(()))";
    std::string parentheses3 = "()()";

    std::cout << "After Removing outer most parentheses: "
              << removeOuterMostParentheses(parentheses1) << std::endl;
    std::cout << "After Removing outer most parentheses: "
              << removeOuterMostParentheses(parentheses2) << std::endl;
    std::cout << "After Removing outer most parentheses: "
              << removeOuterMostParentheses(parentheses3) << std::endl;

    return 0;
}