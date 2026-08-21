/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                            GCD or HCF (GREATEST COMMON DIVISOR)                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 GCD (Greatest Common Divisor), it's the biggest number that divides both number without any remainders.                                        |
|                                                                                                                                                   |
|      🔹 Factor of 12 ("a") -> 1, 2, 3, 4, [6], 12                                                                                                 |
|      🔹 Factor of 18 ("b") -> 1, 2, 3, [6], 9, 18                                                                                                 |
|                                                                                                                                                   |
| 🔶 Euclidean Algorithm gcd(b, a % b)                                                                                                              |
|      🔸 It's the algorithm that provides efficient way to find the "gcd"                                                                          |
|                                                                                                                                                   |
| 🟡 Euclidean algorithm helps us to find GCD by subtracting from "a - b" or using "a % b", If "a" got fully subtracted or "b" got fully divided    |
|  without any remainder means that's the point where we say it's GCD.                                                                              |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                              LCM (LEAST COMMON MULTIPLE)                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 LCM (Least Common Multiple), it's the smallest number that both number can divide them without getting any remainders.                         |
|                                                                                                                                                   |
|      🔹 Multiple of 4 ("a") -> 4, 18, [12], 16, 20 ....                                                                                           |
|      🔹 Multiple of 6 ("b") -> 6, [12], 18 ...                                                                                                    |
|                                                                                                                                                   |
| 👉 [12] is the LCM for (4, 6), because 12 is divide by 4 and 6 completely without giving any remainder                                            |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>

#include "../../dsa_utils.h"

using namespace std;

namespace gcd {
    int bruteForce(int a, int b) {
        int ans = 1;

        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                ans = i;
            }
        }

        return ans;
    }

    int euclideanAlgorithm(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a       = b;
            b       = rem;
        }
        return a;
    }

    int euclideanAlgorithmRec(int a, int b) {
        if (b == 0)
            return a;

        return euclideanAlgorithmRec(b, a % b);
    }

    void main() {
        print(bruteForce(6, 12), "GCD of 6 - 12 is: ");
        print(euclideanAlgorithm(12, 3), "GCD of 12 - 3 is: ");
        print(euclideanAlgorithm(48, 18), "GCD of 48 - 18 is: ");
        print(euclideanAlgorithm(4, 6), "GCD of 4 - 6 is: ");
        std::cout << std::endl << std::endl;
    }
}  // namespace gcd

namespace lcm {
    int bruteForce(int a, int b) {
        int mx = max(a, b);

        while (true) {
            if (mx % a == 0 && mx % b == 0) {
                break;
            }
            mx++;
        }

        return mx;
    }

    int optimizedLCM(int a, int b) {
        int gcd = gcd::euclideanAlgorithmRec(a, b);
        return ((a / gcd) * b);
    }

    void main() {
        print(bruteForce(4, 6), "LCM of 4 - 6 is: ");
        print(optimizedLCM(4, 6), "LCM of 4 - 6 is: ");
    }
}  // namespace lcm

int main() {
    gcd::main();
    lcm::main();

    return 0;
}
