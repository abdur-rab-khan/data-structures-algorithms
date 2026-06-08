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

    /*
        * Building a min stack, where a stack store normal value, and other stack will track the minimum value.
    */
    class MinStack {
        std::stack<int> valueStack;
        std::stack<int> miniStack;

       public:
        void push(int value) {
            valueStack.push(value);
            miniStack.push(miniStack.empty() ? value : std::min(value, miniStack.top()));
        }

        void pop() {
            if (valueStack.empty()) {
                throw std::underflow_error("pop() called on empty stack");
            }

            valueStack.pop();
            miniStack.pop();
        }

        int top() {
            if (valueStack.empty()) {
                throw std::underflow_error("top() called on empty stack");
            }

            return valueStack.top();
        }

        int getMin() {
            if (miniStack.empty()) {
                throw std::underflow_error("getMin() called on empty stack");
            }

            return miniStack.top();
        }
    };

    /*
        * Calculate the baseball score, They are score using different method we have to find total score based on there values.
        * "+" -> Sum the previous two numbers and push them
        * "C" -> Previous score is invalid, mean we have to remove it.
        * "D" -> Double the previous score and push them
        * "number" -> Push it without any rules.
    */
    int calPoints(std::vector<std::string>& scoreOperations) {
        std::stack<int> scoreStack;

        for (const std::string& operation : scoreOperations) {
            if (operation == "+") {
                if (scoreStack.size() < 2) {
                    continue;
                }

                int mostRecentScore = scoreStack.top();
                scoreStack.pop();

                int previousScore = scoreStack.top();
                scoreStack.pop();

                scoreStack.push(previousScore);
                scoreStack.push(mostRecentScore);
                scoreStack.push(previousScore + mostRecentScore);
            } else if (operation == "C") {
                if (!scoreStack.empty()) {
                    scoreStack.pop();
                }
            } else if (operation == "D") {
                if (!scoreStack.empty()) {
                    scoreStack.push(scoreStack.top() * 2);
                }
            } else {
                scoreStack.push(std::stoi(operation));
            }
        }

        int totalScore = 0;
        while (!scoreStack.empty()) {
            totalScore += scoreStack.top();
            scoreStack.pop();
        }

        return totalScore;
    }

    void main() {
        // Question 1:
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

        // Question 2:
        std::string str1 = "abbaca";
        std::string str2 = "azxxzy";

        std::cout << "Removed adjacent string is: " << removeAllAdjacent(str1) << std::endl;
        std::cout << "Removed adjacent string is: " << removeAllAdjacent(str2) << std::endl;

        // Question 3:
        MinStack s1;

        s1.push(-2);
        s1.push(0);
        s1.push(-3);

        std::cout << "Top Value of Stock is: " << s1.top() << std::endl;
        std::cout << "Min Value of Stock is: " << s1.getMin() << std::endl;

        s1.pop();

        std::cout << "Top Value of Stock is: " << s1.top() << std::endl;
        std::cout << "Min Value of Stock is: " << s1.getMin() << std::endl;

        // Question 4:
        std::vector<std::string> str = {"5", "-2", "4", "C", "D", "9", "+", "+"};
        std::cout << "Total score is: " << calPoints(str) << std::endl;
    }
};  // namespace easy

namespace medium {

    void main() {
        // call the member function and classes
    }
}  // namespace medium

int main() {
    // easy::main();
    medium::main();

    return 0;
}