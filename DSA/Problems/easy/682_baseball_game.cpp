#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

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

int main() {
    std::vector<std::string> str = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    std::cout << "Total score is: " << calPoints(str) << std::endl;

    return 0;
}