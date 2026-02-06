# Time Complexity in Computer Science

- [Time Complexity in Computer Science](#time-complexity-in-computer-science)
  - [Time Complexity](#time-complexity)
    - [Examples](#examples)
  - [Space Complexity](#space-complexity)
    - [Example](#example)
  - [Logarithms](#logarithms)

## Time Complexity

> The term **Time Complexity** is rate of which the time taken increases with respect to **input size** of an algorithm that is represent as **o() --> bigO notation**.

- Rules to calculate Time Complexity
  1. Always calculate in term of worst case scenario.
  2. Avoid constants.
  3. Avoid lower values.

### Examples

- **Example 1**

  ```cpp
  void main(){
    int n = 5;

    for(int i = 0; i <= n; i++){
      cout << i << " "; // 1 2 3 4 5
    }
  }
  ```

  - Let's calculate time complexity for ⬆️ code.
    - There are three operation we do, To calculate time complexity we calculate every step than finally find tc.
      1. `i <= n`
      2. `i++`
      3. `cout << i << " ";`
    - If we calculate, It will be like `o(N * 3)` = `5 * 3 = 15`, but as we saw above rules we have to neglect lower and constant value, Here `3` is a constant value that's value we does not count them. So final **Time Complexity** will be **`o(N)`**

- **Example 2**

  ```c++
  void main(){
    int n = 5;

    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
        cout << "[ " << i << ", " << j << " ]" << endl;
      }
    }
  }
  ```
  
  - Let's calculate time complexity for ⬆️ code.

    - There is two loop **1** loop run from **`0 to n`** **2** loop inside **1** run from **`0 to n`**
      - We can say that it runs **`n * n`** mean **`o(n²)`**.
      - For i = 0 it run **j = 0 to n**, for every loop same happen.
  
- **Example 3**

  ```cpp
  void main(){
    int n = 5;

    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= i; j++){
        // Some constant operations
      }
    }
  }
  ```

- Let's calculate time complexity for ⬆️ code.

    ```cpp
    // For 0 >> 0
    // For 1 >> 0, 1
    // For 2 >> 0, 1, 2
    // For 3 >> 0, 1, 2, 3
    // For 4 >> 0, 1, 2, 3, 4
    // For 5 >> 0, 1, 2, 3, 4, 5

    // >> 0, 1, 2, 3, 4, 5 -- Number of time it will run.

    // We have formula to find it n(n + 1) / 2 == n² / 2 + n / 2.
    // We neglect n / 2 So total time complexity will be n² / 2.
    ```

## Space Complexity

> A **memory space** that our program is taken to run the program is called **Space Complexity**. It is the combination of both **Auxiliary Space** (The Space to solve the problem) + **Input Space** (Space to store the input).

### Example

- Explain **Auxiliary** and **Input Space**

  ```cpp
  int a = 5, b = 10; // --> It is Input Space to store the input

  int c = a + b; // --> It is Auxiliary space that is used to solve the problem
  
  // Instead of using c we can do like that also.
  b = a + b; // ❌ We have to avoid unless interview say to change the input, We have to avoid to change the input.
  ```
  
  - Let's calculate space complexity for ⬆️ code.
    - So the space complexity will be **`o(3)`**

## Logarithms
