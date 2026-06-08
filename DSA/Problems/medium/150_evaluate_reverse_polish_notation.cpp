#include <iostream>
#include <stack>
#include <string>
#include <utility>
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
int evaluateRNP(const std::vector<std::string>& tokens) {
    std::stack<int> operandStack;

    for (const std::string& token : tokens) {
        const bool isOperator = (token == "+" || token == "-" || token == "*" || token == "/");

        if (isOperator) {
            const int rightOperand = operandStack.top();
            operandStack.pop();

            const int leftOperand = operandStack.top();
            operandStack.pop();

            if (token == "+")
                operandStack.push(leftOperand + rightOperand);
            else if (token == "-")
                operandStack.push(leftOperand - rightOperand);
            else if (token == "*")
                operandStack.push(leftOperand * rightOperand);
            else
                operandStack.push(leftOperand / rightOperand);

        } else {
            operandStack.push(std::stoi(token));
        }
    }

    return operandStack.top();
}

int main() {
    std::vector<std::string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                                       "/",  "*", "17", "+", "5", "+"};
    std::cout << "Result is: " << evaluateRNP(tokens) << std::endl;

    return 0;
}