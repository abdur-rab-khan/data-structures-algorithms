/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                   🪟 SLIDING WINDOW                                                                                                 |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 The sliding window technique is a very useful that helps us to find and process on "continuous part" of data efficiently. Instead of checking every possible values we maintain a window by "kth" elements and   |
|     perform operation on it.                                                                                                                                                                                        |
|                                                                                                                                                                                                                     |
| 🟡 Instead of recalculating everything, If it breaks conditions than we remove elements from "left" and shift the window by adding from "right" after performing calculation.                                       |
|                                                                                                                                                                                                                     |
| 🔷 Example:                                                                                                                                                                                                         |
|                                                                                                                                                                                                                     |
|            🟡 arr = [2, 1, 5, 1, 3, 2]                                                                                                                                                                              |
|                                                                                                                                                                                                                     |
|            🟡 k = 3                                                                                                                                                                                                 |
|                                                                                                                                                                                                                     |
|            🟡 Windows are:                                                                                                                                                                                          |
|                                                                                                                                                                                                                     |
|                        [2, 1, 5]                                                                                                                                                                                    |
|                        [1, 5, 1]                                                                                                                                                                                    |
|                        [5, 1, 3]                                                                                                                                                                                    |
|                        [1, 3, 2]                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              HOW SLIDING WINDOW WORKS 🪟                                                                                            |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 Step 1: Creating a window                                                                                                                                                                                        |
|                                                                                                                                                                                                                     |
|          🟡 left = 0     // Start of the window                                                                                                                                                                     |
|                                                                                                                                                                                                                     |
|          🟡 right = 0   //  End of the window                                                                                                                                                                       |
|                                                                                                                                                                                                                     |
| 🔷 Step 2: Expand Window                                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|         🟡 Move towards "right" to include more elements                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|         🟡 [2, 1, 5]                                                                                                                                                                                                |
|                                                                                                                                                                                                                     |
| 🔷 Step 3: Process Window                                                                                                                                                                                           |
|                                                                                                                                                                                                                     |
|         🟡 Performing compute on value like "sum", "maximum", "minimum", "number of characters", "count unique values".                                                                                             |
|                                                                                                                                                                                                                     |
| 🔷 Step 4: Shrink Window                                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|         🟡 If it breaks the condition ("size become bigger"), We'll shrink ("move left") pointer.                                                                                                                   |
|                                                                                                                                                                                                                     |
| 🔷 Step 5: Slide Window                                                                                                                                                                                             |
|                                                                                                                                                                                                                     |
|         🟡 Move forward window, "Remove left element", "Add new right element".                                                                                                                                     |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              TYPE OF SLIDING WINDOW 🪟                                                                                              |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 1. Fixed Size Window:                                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|       🟡 Find the maximum sum of subarray size "k", Here the window size will be constant, So that we only have to consider the sum if size of the window is "smaller or equal" to "k".                             |
|                                                                                                                                                                                                                     |
| 🔷 2. Variable Size Window:                                                                                                                                                                                         |
|                                                                                                                                                                                                                     |
|       🟡 Here window size are't fixed, It will update based on the condition, Suppose "Find longest substring without repeating characters."                                                                        |
|                                                                                                                                                                                                                     |
|       🟡 Input = "abcabcbb", Output = 3, "Longest Supstring is 3". Here the window size if dynamic means it will update based on whether it's longest substring or not.                                             |
|                                                                                                                                                                                                                     |
| 🔷 3. Sliding Window with Frequency Map:                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|       🟡 Here we use "sliding window" + "a frequency map" (For Tracking the elements), Example finding "Find the fruits from the bucket that can hold upto 3 fruits".                                               |
|                                                                                                                                                                                                                     |
|       🟡 fruits = ["apple", "banana", "apple", "orange", "banana"]                                                                                                                                                  |
|                                                                                                                                                                                                                     |
|                   first_window = ["apple" ,"banana", "apple"], Frequency Map = {"apple" -> 2, "banana" -> 1} // Similar with other windows                                                                          |
|                                                                                                                                                                                                                     |
| 🔷 4. Sliding Window with dequeue:                                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
|       🟡 Here we use "sliding window" + "deque (doubly ended queue)", It's useful when we want to store elements in a correct order, Like for storing "maximum" or "minimum" value.                                 |
|                                                                                                                                                                                                                     |
|       🟡 In "doubly ended" queue it's possible to store, remove elements on both "front" and "start" position, Which helps to maintain order of elements like large value will be at "front" and small at "back".   |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                              ALL SLIDING WINDOW PATTERNS 🪟                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔷 Pattern 1: Fixed Size Window:                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
|                                 🟡 Window size if fixed one step at a time, Suppose problem statement contains "subarray size of k", "substring length k". So find thing we have is "sliding window".               |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 2: Longest/Shortest Valid Window:                                                                                                                                                                        |
|                                                                                                                                                                                                                     |
|                                 🟡 Expand Window Until condition breaks, Like "Find longest Subarray", "Find longest Substring", "Minimum Window", "Smallest Subarray".                                             |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 3: At Most K Distinct Elements:                                                                                                                                                                          |
|                                                                                                                                                                                                                     |
|                                 🟡 Window allows maximum k unique elements.                                                                                                                                         |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 4: Exactly K Distinct Elements:                                                                                                                                                                          |
|                                                                                                                                                                                                                     |
|                                 🟡 Find extract "k" distinct elements.                                                                                                                                              |
|                                                                                                                                                                                                                     |
| 🔷 Pattern 5: Anagram Matching:                                                                                                                                                                                     |
|                                                                                                                                                                                                                     |
|                                 🟡 Compare Characters Frequency, "find anagram", "permutation of string".                                                                                                           |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
#include "../dsa_utils.hpp"


using namespace std;

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟 SLIDING WINDOW EASY PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace easy_problems {
    // Main function
    void main(){
        cout << "Sliding Window Easy Problems: " << endl;

        cout << endl << endl;
    }
}

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                           🪟 SLIDING WINDOW MEDIUM PROBLEMS                                                                                         |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace medium_problems {
    // Main function
    void main(){
        cout << "Sliding Window Medium Problems: " << endl;

        cout << endl << endl;
    }
}

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                            🪟 SLIDING WINDOW HARD PROBLEMS                                                                                          |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace hard_problems {
    // Main function
    void main(){
        cout << "Sliding Window Hard Problems: " << endl;

        cout << endl << endl;
    }
}

int main() {
    // Calling main functions
    easy_problems::main();
    medium_problems::main();
    hard_problems::main();

    return 0;
}