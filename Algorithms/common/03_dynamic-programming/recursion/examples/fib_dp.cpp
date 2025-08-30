#include <bits/stdc++.h>
using namespace std;

// Using TOP DOWN (memoization)
int fibDP(int n, vector<int>& memo) {
    if (n <= 1)
        return n;

    // Check whether solution of subproblem is there or not.
    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibDP(n - 1, memo) + fibDP(n - 2, memo);

    return memo[n];
}

// Using BOTTOM UP (tabulation)
int fibDPT(int n) {
    vector<int> dp(n + 1);

    // Storing the independent values in dp
    dp[0] = 0;
    dp[1] = 1;

    // Using the bottom-up approach
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Using Optimized approach
int fibDPTS(int n) {
    int prevprev, prev, current;

    prevprev = 0;
    prev = 1;
    current = 2;

    for (int i = 2; i <= n; i++) {
        current = prev + prevprev;
        prevprev = prev;
        prev = current;
    }

    return current;
}

int main() {
    int n = 8;
    vector<int> memo(n + 1, -1);

    cout << "Fibonacci series of " << n << " is: " << fibDP(n, memo) << endl;
    cout << "Fibonacci series of " << n << " is: " << fibDPT(n) << endl;

    return 0;
}
