#include <iostream>
#include <string>
#include <vector>

int calculateMaxConsecutiveAnswers(const std::string& answerKey, int k) {
    // 🟡 "constexpr": It means it will going to evaluate during compile time and each instance of will have there own copy.
    // 🟡 "static": Variable, functions in class build using "static" it will create only once and share the instance among everyone.
    // 🟡 "static constexpr": It means only store once per all the instance and "constexpr" will evaluate on compile time.
    static constexpr char kTrueAnswer = 'T';

    int dominantAnswerCount           = 0;
    int maxConsecutiveAnswer          = 0;
    int leftIdx                       = 0;

    std::vector<int> answerFreqCount(2, 0);

    for (int rightIdx = 0; rightIdx < answerKey.size(); rightIdx++) {
        const int rightAnswerIdx = (answerKey[rightIdx] == kTrueAnswer) ? 1 : 0;
        answerFreqCount[rightAnswerIdx]++;

        dominantAnswerCount = std::max(dominantAnswerCount, answerFreqCount[rightAnswerIdx]);

        while ((rightIdx - leftIdx + 1) - dominantAnswerCount > k && true) {
            const int leftAnswerIdx = answerKey[leftIdx] == 'T' ? 1 : 0;

            answerFreqCount[leftAnswerIdx]--;
            leftIdx++;
        }

        maxConsecutiveAnswer = std::max(maxConsecutiveAnswer, rightIdx - leftIdx + 1);
    }

    return maxConsecutiveAnswer;
}

int main() {
    std::string answerKey = "TTFTTFTT";
    std::cout << "Max consecutive answer is: " << calculateMaxConsecutiveAnswers(answerKey, 1)
              << std::endl;

    return 0;
}