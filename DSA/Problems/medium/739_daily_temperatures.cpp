#include <stack>
#include <string>
#include <utility>
#include <vector>

#include "../../dsa_utils.h"

std::vector<int> calculateDailyTemperature(std::vector<int> temps) {
    int size = static_cast<int>(temps.size());

    std::stack<std::pair<int, int>> st;
    std::vector<int>                result(size, 0);

    for (int i = size - 1; i >= 0; --i) {
        while (!st.empty() && st.top().first <= temps[i]) {
            st.pop();
        }

        int maxTempDay = !st.empty() ? st.top().second : i;
        int dayDiff    = maxTempDay - i;

        result[i] = dayDiff;
        st.push(std::make_pair(temps[i], i));
    }

    return result;
}

int main() {
    // std::vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    // std::vector<int> temps2 = {30, 40, 50, 60};
    // std::vector<int> temps3 = {30, 60, 90};
    std::vector<int> temps4 = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};

    std::string msg = "Daily temps are: ";
    // print(calculateDailyTemperature(temps1), msg);
    // print(calculateDailyTemperature(temps2), msg);
    // print(calculateDailyTemperature(temps3), msg);
    print(calculateDailyTemperature(temps4), msg);

    return 0;
}
