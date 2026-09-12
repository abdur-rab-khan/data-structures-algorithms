#include <cstddef>
#include <string>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    string gcdOfStrings(const string& str1, const string& str2) {
        const size_t gcd       = __findGCD(str1.length(), str2.length());
        string       gcdSubstr = str1.substr(0, gcd);

        if (__repeatNTimes(gcdSubstr, str1.length() / gcd) != str1) {
            return "";
        }

        if (__repeatNTimes(gcdSubstr, str2.length() / gcd) != str2) {
            return "";
        }

        return gcdSubstr;
    }

   private:
    static size_t __findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return __findGCD(b, a % b);
    }

    static string __repeatNTimes(const string& str, int n) {
        string result = "";
        for (int i = 0; i < n; ++i) {
            result += str;
        }
        return result;
    }
};

int main() {
    Solution sol;

    print(sol.gcdOfStrings("ABCABC", "ABC"));
    print(sol.gcdOfStrings("ABABAB", "ABAB"));
    print(sol.gcdOfStrings("LEET", "CODE"));
    print(sol.gcdOfStrings("AAAAAB", "AAA"));

    return 0;
}
