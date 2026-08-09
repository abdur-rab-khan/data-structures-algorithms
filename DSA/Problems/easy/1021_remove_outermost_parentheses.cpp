#include <iostream>
#include <string>

/*
    * In this approach with are using with counter variable called depth, the problem in me is we can’t feature it out we can use depth in this approach for tracking outer parentheses and inner parentheses.
    * So next time when we are going to solve the problem "please please please", break down the question into separate chunks. Then feature out what things are needed to solve this problem.
*/
std::string removeOuterParentheses(std::string s) {
    std::string result;
    result.reserve(s.size());

    int depth = 0;
    for (const char& ch : s) {
        depth += (ch == '(') ? 1 : -1;

        const bool isInnerOpenParen  = (ch == '(' && depth > 1);
        const bool isInnerCloseParen = (ch == ')' && depth >= 1);

        if (isInnerOpenParen || isInnerCloseParen) {
            result.push_back(ch);
        }
    }

    return result;
}

int main() {
    const std::string parentheses1 = "(()())(())";
    const std::string parentheses2 = "(()())(())(()(()))";
    const std::string parentheses3 = "()()";

    std::cout << "After Removing outermost parentheses: " << removeOuterParentheses(parentheses1)
              << std::endl;
    std::cout << "After Removing outermost parentheses: " << removeOuterParentheses(parentheses2)
              << std::endl;
    std::cout << "After Removing outermost parentheses: " << removeOuterParentheses(parentheses3)
              << std::endl;

    return 0;
}
