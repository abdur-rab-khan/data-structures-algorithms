# Dynamic Programming

> Dynamic programming is a algorithmic technique to optimize recursive algorithms by storing the results of subproblem to avoid to recomputing again and again of the same subproblem.

- [Dynamic Programming](#dynamic-programming)
  - [Overview](#overview)
    - [Top Down (memoization)](#top-down-memoization)
    - [Bottom-Up (tabulation)](#bottom-up-tabulation)
  - [Examples of Dynamic Programming](#examples-of-dynamic-programming)
    - [1. Fibonacci Number (Top Down Approach)](#1-fibonacci-number-top-down-approach)
      - [How will Dynamic Programming (DP) Works?](#how-will-dynamic-programming-dp-works)
    - [2. Fibonacci Number (Bottom Up Approach)](#2-fibonacci-number-bottom-up-approach)

## Overview

- The core idea behind dynamic programming is to store the solutions of subproblem to ensure that each subproblem is only solved once.
- To solve DP problems, we first write the recursive solution in such a way that there are overlapping subproblems and optimal substructure.
- To make sure that the recursive value is computed only once, we store the results of subproblems.
- There are two way to store the results of subproblems:
    1. **Top Down (memoization)**
    2. **Bottom Up (tabulation)**

### Top Down (memoization)

- In this approach, we solve the problem and store the results of subproblems in a data structure (usually an array or a hash map).

  - Next time before computing the result of a subproblem, we check if it is already computed and stored in the data structure.
  - If result is not computed, we compute it and store it in the data structure.

### Bottom-Up (tabulation)

- In this approach, we solve the smaller subproblems first and use their results to build up the solution to the original problem.
  - In this approach, we typically use an iterative approach to fill up a table (usually an array) with the results of subproblems.
  - We use DP table to store the results of subproblems and build up the solution to the original problem.
  - We only use recursive formula on table entries, not on function calls.

## Examples of Dynamic Programming

### 1. Fibonacci Number (Top Down Approach)

- Brute force recursive solution by using the recursive formula:
  - `fib(n) = fib(n-1) + fib(n-2)` with base cases `fib(0) = 0` and `fib(1) = 1`

    ```cpp
    #include<bits/stdc++.h>
    using namespace std;
    
    int fib(int x){
        if(x == 0) 
            return 0;
        else if(x == 1 || x == 2) 
            return 1;
        else 
            return fib(x - 1) + fib(x - 2);
    }
    
    int main(){
        int x = 5;
        cout << "Fibonacci of " << x << " is: " << fib(x) << endl;
    }
    ```

#### How will Dynamic Programming (DP) Works?

- As highlighted in the below picture these are the overlapping subproblems in the recursion tree.
- For that situation, we can use dynamic programming to store the results of subproblems in a data structure (usually an array or a hash map) to avoid recomputing the same subproblem again and again.

    ![Fibonacci Recursion Tree](https://media.geeksforgeeks.org/wp-content/uploads/20241223141819419563/1.webp)

- Steps to solve the problem using DP:
    1. **Identify Subproblems:** Divide the main problem into smaller subproblems i.e f(n - 1) + f(n - 2).
    2. **Store Solutions:** Store the results of subproblems in a data structure (usually an array or a hash map).
    3. **Build the Solutions:** Use the stored results to build the solution to the original problem.
    4. **Avoid Recomputation:** Before computing the result of a subproblem, check if it is already computed and stored in the data structure.

- Solving Fibonacci using Top Down (memoization) approach time complexity is O(n) and space complexity is O(n):

   ```cpp
   #include <bits/stdc++.h>
    using namespace std;
    
    int fibDP(int n, vector<int>& memo) {
        if (n <= 1)
            return n;
    
        // Check whether solution of subproblem is there or not.
        if (memo[n] != -1)
            return memo[n];
    
        memo[n] = fibDP(n - 1, memo) + fibDP(n - 2, memo);
    
        return memo[n];
    }
    
    int main() {
        int n = 8;
        vector<int> memo(n + 1, -1);
    
        cout << "Fibonacci series of " << n << " is: " << fibDP(n, memo);
    
        return 0;
    }
   ```

- Using Space Optimised Approach - O(n) Time and O(1) Space

### 2. Fibonacci Number (Bottom Up Approach)

- Unlike, Top Down approach, in Bottom Up appraoch we solve the smaller subproblems first and use their results to build up the solution to the original problem.
- We typically use an iterative approach to fill up a table (usually an array) with the results of subproblems.

    ```cpp
    #include<bits/stdc++.h>
    using namespace std;
    
    int fib(int x){
        vector<int> dp(x + 1);
    
        dp[0] = 0;
        dp[1] = 1;
    
        for(int i = 2; i <= x; i++){
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
    
        return dp[x];
    }
    
    int main(){
        int x = 5;
    
        cout << "Fibonacci of " << x << " is: " << fib(x) << endl;
        return 0;
    }
    ```

  - Here the ***time complexity*** is `o(n)` and ***space complexity*** is `o(n)`.
  - There are event better approach are there.

    ```c++
    #include<bits/stdc++.h>
    using namespace std;

    int fib(int x){
        int prevprev = 0, prev = 1, current;

        for(int i = 2; i <= x; i++){
            current = prevprev + prev;
            prevprev = prev;
            prev = current;
        }

        return current;
    }

    int main(){
        int x = 5;

        cout << "Fibonacci of " << x << " is: " << fib(x) << endl;
        return 0;
    }
    ```
