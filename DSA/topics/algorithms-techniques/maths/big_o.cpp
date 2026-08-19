/*
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                     BIG O NOTATION                                                                |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 BIG O notation tells about how algorithms "execution time" or "operation grow" when size "n" increases.                                        |
|                                                                                                                                                   |
| 🔶 BIG O Examples:                                                                                                                                | 
|                                                                                                                                                   |
|    1. O(1): It will take constant time not depends on how much input size it.                                                                     |
|                                                                                                                                                   |
|    2. O(n): It will grows "n" time directly with size changes.                                                                                    |
|                                                                                                                                                   |
|    3. O(log n): Reduces the number of steps as input size increases, See below how O(log n) works.                                                |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                    LOGARITHMS                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                   |
| 🟡 Logarithm helps us to find how fast our algorithm is, By seeing the number of steps it's taking to run an algorithm. Logarithm is just a       |
|     tool to find how speed of our algorithm.                                                                                                      |
|                                                                                                                                                   |
| 🔶 HOW LOGARITHM WORKS:                                                                                                                           |
|                                                                                                                                                   |
|    1. "log₂(n) || log(n)" -> Log to the base 2, means it will divide the n by 2 at every step until become 1.                                     |
|                                                                                                                                                   |
|    2. "log₂(8)" -> 8 / 2 -> 4  || 4 / 2 -> 2 || 2 / 2 -> 1 || --> log₂(8) = 3 --> It's taking 3 step to solve a problem.                          |
|                                                                                                                                                   |
| ⭐ In Computer Science we use "log₂(n)" Because of often we divide things into 2 like in Binary Search or other algorithms.                       |
|                                                                                                                                                   |
| 🔷 Common Example of Logarithm:                                                                                                                   |
|                                                                                                                                                   |
|    1. "log₂(n)" -> See above.                                                                                                                     |
|                                                                                                                                                   |
|    2. "log log(16)" -> 1. Let's check how much steps log(16) takes = 4, Now will further find So log(4) = 2.                                      |
|                                                                                                                                                   |
|    3. "n log(n)" -> 1. Let's check the steps log(16) takes = 4, Now we will multiply with n, So 16 * log(16) || 16 * 4 || 52                      |
|                        Means Every step takes log(n) time which slower than "O(n)" but faster than "O(n²)".                                       |
|                                                                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------+
*/