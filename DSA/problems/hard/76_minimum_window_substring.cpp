#include <climits>
#include <string>
#include <unordered_map>
#include <utility>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        auto substrWindow = make_pair(0, INT_MAX);
        int  targetWindow = static_cast<int>(t.size());

        // Hashmap, to store "target" freq for getting "minWindow"
        unordered_map<char, int> targetFreq;
        for (const char& ch : t) {
            targetFreq[ch]++;
        }

        int leftIndex = 0;
        for (int rightIndex = 0; rightIndex < static_cast<int>(s.size()); ++rightIndex) {
            auto rightFreq = targetFreq.find(s[rightIndex]);
            if (rightFreq != targetFreq.end()) {
                --rightFreq->second;
                if (rightFreq->second >= 0) {
                    --targetWindow;
                }
            }

            while (leftIndex <= rightIndex && targetWindow == 0) {
                auto leftFreq = targetFreq.find(s[leftIndex]);
                if (leftFreq != targetFreq.end()) {
                    if ((substrWindow.second - substrWindow.first) > (rightIndex - leftIndex)) {
                        substrWindow = make_pair(leftIndex, rightIndex);
                    }

                    ++leftFreq->second;
                    if (leftFreq->second > 0) {
                        ++targetWindow;
                    }
                }

                ++leftIndex;
            }
        }

        return substrWindow.second == INT_MAX
                   ? ""
                   : string(s.begin() + substrWindow.first, s.begin() + substrWindow.second + 1);
    }
};

int main() {
    Solution sol;
    print(sol.minWindow("ADOBECODEBANC", "ABC"));
    print(sol.minWindow("a", "a"));
    print(sol.minWindow("a", "aa"));
    print(sol.minWindow("bba", "ba"));
    print(sol.minWindow("aa", "aa"));
    print(sol.minWindow("aaa", "aab"));

    return 0;
}
