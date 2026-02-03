# Recursion

> A function is said to be recursive if it calls itself directly or indirectly to solve a smaller instance of the same problem.

- [Recursion](#recursion)
  - [Key Concepts](#key-concepts)
    - [Steps to implement Recursion](#steps-to-implement-recursion)
    - [Examples](#examples)
      - [Examples Sum of Natural Numbers](#examples-sum-of-natural-numbers)
      - [Examples Factorial of a Number](#examples-factorial-of-a-number)
      - [Examples Fibonacci of a Number](#examples-fibonacci-of-a-number)
    - [Comparison of Recursive and Iterative Approaches](#comparison-of-recursive-and-iterative-approaches)
    - [Needs of Recursion?](#needs-of-recursion)
    - [What is base condition in recursion?](#what-is-base-condition-in-recursion)
    - [How a particular problem is solved using recursion?](#how-a-particular-problem-is-solved-using-recursion)
    - [What is the difference between direct and indirect recursion?](#what-is-the-difference-between-direct-and-indirect-recursion)
    - [What is the difference between tail and non-tail recursion?](#what-is-the-difference-between-tail-and-non-tail-recursion)
    - [How memory is allocated to different function calls in recursion?](#how-memory-is-allocated-to-different-function-calls-in-recursion)

## Key Concepts

- A **recursive** algorithm takes one step towards the solution and then recursively calls itself to move towards the solution.
- Since function called, it might continue calling forever, So **base case** is needed to stop the recursion.

### Steps to implement Recursion

1. **Define a base case:** Identify the step where the solution is known/trivial. At this point, the function should return a value without making any further recursive calls.
2. **Define the recursive case:** This is where the function calls itself with a smaller or simpler input, moving towards the base case.
3. **Ensure the recursion terminates:** Make sure that the recursive calls eventually reach the base case. This often involves modifying the input in each recursive call.
4. **Combine the results:** If the function is solving a problem that requires combining results from multiple recursive calls, ensure that this combination is handled correctly.

### Examples

#### Examples Sum of Natural Numbers

- The sum of the first **`n`** natural numbers can be calculated using recursion by defining a base case (n == 1) and a recursive case.

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  
  int sumNatural(int n) {
          if (n == 1)
                  return 1;
  
          return n + sumNatural(n - 1);
  }
  
  int main() {
          int n = 5;
          cout << "Sum of " << n << " natural numbers: " << sumNatural(n);
          return 0;
  }
  ```

#### Examples Factorial of a Number

- The factorial of a number **`n`** (where n >= 0) is the product of all positive integers less than or equal to n.
- We calculate the factorial of a number using recursion by defining a base case (n == 0) and a recursive case.

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  
  int factorialN(int n) {
      if (n == 0)
          return 1;
  
      return n * factorialN(n - 1);
  }
  
  int main() {
      int n = 5;
  
      cout << "Factorial of " << n << " is: " << factorialN(n);
  
      return 0;
  }
  ```

- Illustration of the above code:
  
  ![factorial-illustration](https://media.geeksforgeeks.org/wp-content/uploads/20240924132748/factorial.webp)

#### Examples Fibonacci of a Number

- The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1.
- For example, the sequence starts as follows: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  
  int fibonacciN(int n) {
      if (n == 0)
          return 0;
      else if (n == 1 || n == 2)
          return 1;
      else
          return (fibonacciN(n - 1) + fibonacciN(n - 2));
  }
  
  int main() {
      int n = 8;
  
      cout << "Fibonacci of " << n << " is: " << fibonacciN(n) << endl;
  
      return 0;
  }
  ```

- Recursion Tree for the above Code:

  ![fibonacci-illustration](https://media.geeksforgeeks.org/wp-content/uploads/20250318141757504475/Fibonacci-series.webp)
 
### Comparison of Recursive and Iterative Approaches

| Approach | Complexity | Memory Usage |
|----------|------------|--------------|
| Iterative Approach | O(n) | O(1) |
| Recursive Approach | O(n) | O(n) |

### Needs of Recursion?

- Recursive solutions work as a a basis for Dynamic Programming and Divide and Conquer algorithms.
- Certain problems can be solved quite easily using recursion like Towers of Hanoi (TOH), Inorder/Preorder/Postorder Tree Traversals, DFS of Graph, etc.

### What is base condition in recursion?

- The base condition (or base case) in recursion is the condition under which the recursive function stops calling itself.
- It is very crucial to define a base case to prevent infinite recursion and potential stack overflow errors.

### How a particular problem is solved using recursion?

- The idea is to break the problem down into smaller subproblem of the same type, solve each subproblem recursively, and combine the results to solve the original problem.

### What is the difference between direct and indirect recursion?

1. **`direct`:** A function calls itself directly.
2. **`indirect`:** A function calls another function, which in turn calls the first function.

   ```cpp
   #include <bits/stdc++.h>
   using namespace std;
   
   void functionA(int n);
   void functionB(int n);
   
   void functionA(int n) {
       if (n > 0) {
           cout << "Function A: " << n << endl;
           functionB(n - 1); // Indirectly calls itself through functionB
       }
   }
   
   void functionB(int n) {
       if (n > 0) {
           cout << "Function B: " << n << endl;
           functionA(n - 1); // Indirectly calls itself through functionA
       }
   }
   
   int main() {
       int n = 3;
       functionA(n); // Start the indirect recursion
       return 0;
   }
   ```

### What is the difference between tail and non-tail recursion?

1. **`Tail Recursion`:** The recursive call is the last operation in the function. There are no further computations after the recursive call, meaning the current function's state does not need to be preserved.
2. **`Non-Tail Recursion`:** The recursive call is not the last operation in the function. There are further computations after the recursive call, meaning the current function's state needs to be preserved for those computations.

   ```cpp
   #include <bits/stdc++.h>
   using namespace std;
   
   // Tail Recursion
   int tailRecursiveFactorial(int n, int accumulator = 1) {
       if (n == 0)
           return accumulator;
       return tailRecursiveFactorial(n - 1, n * accumulator);
   }
   
   // Non-Tail Recursion
   int nonTailRecursiveFactorial(int n) {
       if (n == 0)
           return 1;
       return n * nonTailRecursiveFactorial(n - 1);
   }
   
   int main() {
       int n = 5;
   
       cout << "Tail Recursive Factorial of " << n << " is: " << tailRecursiveFactorial(n) << endl;
       cout << "Non-Tail Recursive Factorial of " << n << " is: " << nonTailRecursiveFactorial(n) << endl;
   
       return 0;
   }
   ```

- **`Tail Recursion`** is generally more efficient than **`Non-Tail Recursion`** because it can be optimized by the compiler to avoid increasing the call stack depth, thus preventing stack overflow for large inputs.

### How memory is allocated to different function calls in recursion?

- Recursive function uses more memory because each function call is stored in the call stack until the base case is reached and the function calls start returning.
  - Each function call has its own set of parameters and local variables, which are stored in the stack frame.
  - Internal system uses stock memory that follow **LIFO** (Last In First Out) principle. the last called function is the first one to be completed and removed from the stack.
- In contrast, an iterative approach typically uses a constant amount of memory, as it does not involve multiple function calls being stored in the stack.
