#include <iostream>
#include <string>
#include <vector>

int calculateMaxConsecutiveAnswers(const std::string& answerKey, int k) {
    // 🟡 "constexpr": It means it will going to evaluate during compile time and each instance of will have there own copy.
    // 🟡 "static": Variable, functions in class build using "static" it will create only once and share the instance among everyone, Actually there are three means of "static" keywords.
    //              1️⃣. "static on a Normal Variable (inside a function)": Means once a function is called, it will create "variable with static once" and share that reference with among all the functions. It saves alot mem.
    //              2️⃣. "static on a Function and Variable (outside any fun/class)":
    //              3️⃣. "static on class":
    static constexpr char kTrueAnswer = 'T';

    if (answerKey.empty())
        return 0;

    int falseCount = 0;
    int trueCount  = 0;

    int dominantAnswerCount     = 0;
    int maxConsecutiveQuestions = 0;

    int leftIdx = 0;
    for (int rightIdx = 0; rightIdx < static_cast<int>(answerKey.size()); rightIdx++) {
        if (answerKey[rightIdx] == kTrueAnswer) {
            trueCount++;
        } else {
            falseCount++;
        }

        dominantAnswerCount = std::max(dominantAnswerCount, std::max(falseCount, trueCount));

        while ((rightIdx - leftIdx + 1) - dominantAnswerCount > k) {
            if (answerKey[leftIdx] == kTrueAnswer) {
                trueCount--;
            } else {
                falseCount--;
            }

            leftIdx++;
        }

        maxConsecutiveQuestions = std::max(maxConsecutiveQuestions, (rightIdx - leftIdx + 1));
    }

    return maxConsecutiveQuestions;
}

int main() {
    std::string answerKey = "TTFF";
    std::cout << "Max consecutive answer is: " << calculateMaxConsecutiveAnswers(answerKey, 2)
              << std::endl;

    return 0;
}