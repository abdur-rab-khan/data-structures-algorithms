# Divide and Conquer Approach Algorithm

> **Divide and Conquer** is a problem solving technique where we **divide** main problem into **subproblem** and then solving them individually, and finally **merge** them. \
> If we got **overlapping** subproblem, then we use [**dynamic programming**](../03_dynamic-programming/main.md).

- [Divide and Conquer Approach Algorithm](#divide-and-conquer-approach-algorithm)
  - [Working of Divide and Conquer](#working-of-divide-and-conquer)
    - [1. Divide](#1-divide)
    - [2. Conquer](#2-conquer)
    - [3. Merge](#3-merge)
  - [Advanced master theorem for divide and conquer recurrences](#advanced-master-theorem-for-divide-and-conquer-recurrences)

## Working of Divide and Conquer

- Divide and Conquer technique works in three stages:
    1. **Divide**
    2. **Conquer**
    3. **Merge**

    ![merge-sort](https://media.geeksforgeeks.org/wp-content/uploads/20240501171531/Working-of-Divide-and-Conquer-Algorithm.webp)

  - The above diagram shows the working of [**Merge Sort**](../../02_array/01_sorting/algo/merge-sort/main.cpp).

### 1. Divide

- Divide the original problem into smaller sub-problem.
- Each sub-problem should represent a part of overall problem.
- The goal is to divide the problem until no further division possible. 

### 2. Conquer

- Solve each smaller individual sub-problems.
- If a subproblem is small enough, we solve it directly without further recursion.
- The goal is to find solutions for these subproblem independently.

### 3. Merge

- Combine the sub-problems to get the **final solution** of the whole problem.
- Once the smaller sub-problems are solved, we recursively combine their solutions to get the solutions of larger problem.
- The goal is to formulate a solution for the original problem by merging the solution from the subproblem.

## Advanced master theorem for divide and conquer recurrences

> The master theorem is a tool to solve recurrence relations, that helps to analyze divide and conquer approach. \
> The **Master Theorem** provide a systematic way of solving recurrence relations of the form:

$$
T(n) = a \, T\!\left(\frac{n}{b}\right) + f(n)
$$

