#include <cctype>
#include <functional>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

/*
    * We have given "arithmetic expressions", and we need to evaluate them based on the expressions.
    * Like ["2", "3", "4", "+", "*"]
           * [2, 3, 4]
           * [2, 7]  ---> 3 + 4 = 7
           * [2, 7] ---> 2 * 7 = 14
           * [14]
           * Now "14" is our answer

    * Don't complicate things, We have to make simple as possible, For this problem I able to think the solution but i make things more complicated.
*/
static const std::unordered_map<std::string, std::function<int(int, int)>> ops = {
    {"+", std::plus<int>()},
    {"-", std::minus<int>()},
    {"*", std::multiplies<int>()},
    {"/", std::divides<int>()}};

int evaluateRPN(const std::vector<std::string>& tokens) {
    std::stack<int> operandStack;

    for (const std::string& token : tokens) {
        const auto operatorIt = ops.find(token);
        const bool isOperator = operatorIt != ops.end();

        if (isOperator) {
            if (operandStack.size() < 2) {
                throw std::invalid_argument("evaluateRPN: malformed expression");
            }

            const int rightOperand = operandStack.top();
            operandStack.pop();
            const int leftOperand = operandStack.top();
            operandStack.pop();

            if (token == "/" && rightOperand == 0) {
                throw std::invalid_argument("evaluateRPN: division by zero");
            }

            operandStack.push(operatorIt->second(leftOperand, rightOperand));
        } else {
            operandStack.push(std::stoi(token));
        }
    }

    return operandStack.top();
}

int main() {
    std::vector<std::string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                                       "/",  "*", "17", "+", "5", "+"};
    std::cout << "Result is: " << evaluateRPN(tokens) << std::endl;

    return 0;
}
