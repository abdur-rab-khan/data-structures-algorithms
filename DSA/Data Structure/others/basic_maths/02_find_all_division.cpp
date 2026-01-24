#include <bits/stdc++.h>

using namespace std;

// Brute force method to find -- all divisor
vector<int> getAllDivisor(int n) {
    vector<int> divisor = {};

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);
        }
    }

    return divisor;
}

// Using modulo and division to find -- all divisor
vector<int> getAllDivisorTwo(int n) {
    vector<int> divisor = {};

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0)
            continue;

        divisor.push_back(i);

        if (n / i != i) {
            divisor.push_back(n / i);
        }
    }

    return divisor;
}

int main() {
    // Find for -- 36
    vector<int> divisor_first = getAllDivisor(36);

    for (auto n : divisor_first) {
        cout << n << " ";
    }

    // Find for -- 36
    vector<int> divisor_second = getAllDivisorTwo(36);

    sort(divisor_second.begin(), divisor_second.end());
    cout << endl;
    for (auto const n : divisor_second) {
        cout << n << " ";
    }
    return 0;
}