/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                      TWO POINTERS                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 In "two pointers" technique we use two indices (pointer) to scan the array, based on condition we smartly increase/decrease pointer indices.                                                                     |
|                                                                                                                                                                                                                     |
| 🟡 Without using "two pointers" we could use "nested loop o(n²)", "two pointers" makes scaning efficient "o(n)".                                                                                                    |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    TYPES TWO POINTERS                                                                                               |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🔶 Opposite direction (start & end):                                                                                                                                                                                |
|                                                                                                                                                                                                                     |
|    1. One Pointer at the begining, One Pointer at the end.                                                                                                                                                          |
|    2. Moving based on conditions.                                                                                                                                                                                   |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Sorted array problems                                                                                                                                                                                  |
|           2. Pair sum problems                                                                                                                                                                                      |
|           3. Palindrome checking                                                                                                                                                                                    |
|                                                                                                                                                                                                                     |
| 🔶 Same direction (slow & fast pointer):                                                                                                                                                                            |
|                                                                                                                                                                                                                     |
|    1. Both pointers starts from the same position.                                                                                                                                                                  |
|    2. Fast pointer (move quickly), slow pointer (move based on conditions).                                                                                                                                         |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Removing Duplicates                                                                                                                                                                                    |
|           2. Removing elements                                                                                                                                                                                      |
|           3. Cycle Detection                                                                                                                                                                                        |
|           4. Rearranging array in place                                                                                                                                                                             |
|                                                                                                                                                                                                                     |
| 🔶 Sliding window (Variable size):                                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
|    1. Window grows and shrinks maintaining condition inside the window.                                                                                                                                             |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Longest Substring                                                                                                                                                                                      |
|           2. Subarray sum problems                                                                                                                                                                                  |
|           3. At most K distinct element                                                                                                                                                                             |
|                                                                                                                                                                                                                     |
| 🔶 Sliding window (Fixed size):                                                                                                                                                                                     |
|                                                                                                                                                                                                                     |
|    1. Window size fixed maintaining fixed distance, both moves together.                                                                                                                                            |
|                                                                                                                                                                                                                     |
|    Used In:                                                                                                                                                                                                         |
|           1. Maximum size of K                                                                                                                                                                                      |
|           2. First negative in window.                                                                                                                                                                              |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/


#include <bits/stdc++.h>
using namespace std;

void traverse(vector<int>& vec, string msg = "") {
    if(vec.size() == 0)
        return;

    if(msg.empty())
        cout << "Elements of a vector are: ";
    else
        cout << msg;

    for(const int& el: vec){
        cout << el << " ";
    }
    cout << endl;
}

namespace intro {
    // Using Opposite direction to reverse the array
    void reverse(vector<int>& vec) {
        int i = 0;
        int j = vec.size() - 1;

        while(i < j){
            vec[i] ^= vec[j], vec[j] ^= vec[i], vec[i] ^= vec[j]; // Swapping numbers

            i++;
            j--;
        }
    }
   
    // Using same direction to check duplicates
    void removeDuplicates(vector<int> vec){
        int i = 0, j = 1;
        vector<int> uniqueValues = {};

        while(j < vec.size()){
            if(vec[i] == vec[j])
                j++;
            else {
                uniqueValues.push_back(vec[i]);
                i = j;
                j++;
            }
        }

        // The last unique group is never pushed inside the loop, add it here
        if(!vec.empty())
            uniqueValues.push_back(vec[i]);

        traverse(uniqueValues); // Printing all unique elements
    }
    
    void main() {
        // Reversing and printing arr
        vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        reverse(arr), traverse(arr);

        // Removing duplicates
        vector<int> arr2 = {1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 5};
        removeDuplicates(arr2);
    }
}

namespace problems {
    // Basic Level
    namespace basic {
        // Two sum problem (SHORTED VERSION)
        void computeTwoSum(vector<int> arr, int k){
            int i = 0, j = arr.size() - 1;

            while(i < j){
                int sum = arr[i] + arr[j];

                // If sum equal to k break the loop
                if(sum == k)
                    break;

                // If sum greater shift by 1 from right otherwise shift by 1 from left;
                if(sum > k) 
                    j--;
                else
                    i++;
            }

            // No pair found
            if(i >= j){
                i = 0;
                j = 0;
            }

            cout << "Pair that sums equals to " << k << " is: " << i << " - " << j << endl;
        }
       
        // Checking whether it's palindrome or not.
        void isPalindrome(string str){
            int leftIndex = 0;
            int rightIndex = str.length() - 1;

            // Lambda function: use "auto" or given type or directly use "isalnum"  ==> Learned LAMBDA FUNCTION
            function<bool(char)> isValidChar = [](char ch) -> bool {
                char lowerCh = tolower(ch);
                return (lowerCh >= 'a' && lowerCh <= 'z') ||
                (lowerCh >= '0' && lowerCh <= '9');
            };

            // Find whether "str" is palindrome or not by look both side.
            while(leftIndex < rightIndex){
                bool isRightCharValid = isValidChar(str[rightIndex]);
                bool isLeftCharValid = isValidChar(str[leftIndex]);
               
                if(!isRightCharValid){
                    leftIndex++;
                    continue;
                }

                if(!isLeftCharValid){
                    rightIndex--;
                    continue;
                }
               
                if(tolower(str[leftIndex]) != tolower(str[rightIndex])) {
                    cout << str << " is not a palindrome";
                    return;
                }

                leftIndex++;
                rightIndex--;
            }

            cout << str << " is a palindrome";
        }
        
        // Remove duplicates
        void removeDuplicates(vector<int> arr){
            // If no elements are there
            if(arr.size() == 0)
                return;

            int i = 0, j = 1;

            while(j < arr.size()){
                if(arr[i] == arr[j])
                    j++;
                else{
                    arr[++i] = arr[j++];
                }
            }

            // Printing every elements;
            cout << "Unique elements are: ";
            for(int k = 0; k < i + 1; k++){
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        
        // Moving zeros
        void moveZeros(vector<int>& arr){
            if(arr.empty() || arr.size() == 1)
                return;

            int i = 0, j = 0;

            while(j < arr.size()){
                if(arr[j] != 0)
                    arr[i++] = arr[j++];
                else
                    j++;
            }

            // Fill zeros from i till n
            while(i < arr.size()){
                arr[i++] = 0;
            }

            // Printing every elements;
            cout << "Non zero elements are: ";
            for(int k = 0; k < i; k++){
                cout << arr[k] << " ";
            }
            cout << endl;
        }

        // Merge sorted array
        void mergeSort(vector<int> arr1, vector<int> arr2){
            vector<int> mergedArr = {};

            int i = 0, j = 0;
            while(i < arr1.size() && j < arr2.size()) {
                if(arr1[i] < arr2[j])
                    mergedArr.push_back(arr1[i++]);
                else
                    mergedArr.push_back(arr2[j++]);
            }

            // Push remaining elements from both
            while(i < arr1.size())
                mergedArr.push_back(arr1[i++]);

            while(j < arr2.size())
                mergedArr.push_back(arr2[j++]);

            // Printing elements of merged array
            traverse(mergedArr);

            // Merging without using extra space;
            int size1 = arr1.size();
            int size2 = arr2.size();

            arr1.resize(size1 + size2);

            int m = size1 - 1;              // last valid element in original arr1
            int n = size2 - 1;              // last element in arr2
            int k = size1 + size2 - 1;      // last index of resized arr1

            while (m >= 0 && n >= 0) {
                if (arr1[m] > arr2[n])
                    arr1[k--] = arr1[m--];
                else
                    arr1[k--] = arr2[n--];
            }

            while (n >= 0) {
                arr1[k--] = arr2[n--];
            }

            // Printing elements of merged array
            cout << "IN-PLACE MERGING: " << endl;
            traverse(arr1);
        }

        // Container with most water problem
        void calculateMaxContainerArea(const vector<int>& heights) {
            /*
                * Two-pointer approach to calculate maximum container area
            
                |                   
                |
                +-------------------+ 
                |                   |
             8  |                   |
                |                   | 4
                |                   |
                +-------------------+
                   j - i (distance)
                        
            */

            int size = heights.size();
            
            int leftIndex = 0;
            int rightIndex = size - 1;
            
            int maxWaterArea = 0;

            // Find max water area
            while(leftIndex < rightIndex){
                int leftHeight = heights[leftIndex];
                int rightHeight = heights[rightIndex];

                int minHeight = min(leftHeight, rightHeight);
                int width = rightIndex - leftIndex;
                int waterArea = minHeight * width;

                if(leftHeight < rightHeight)
                    leftIndex++;
                else
                    rightIndex--;

                maxWaterArea = max(maxWaterArea, waterArea);
            }

            cout << "Max water area is: " << maxWaterArea< endl;
        }

        void computeSortedSquares(vector<int> numbers) {
            // Edge case: empty array
            if(numbers.empty())
                return;

            int negativeIndex = 0;
            int positiveIndex = 1;
            int size = numbers.size();
            
            vector<int> squaredValues;

            // Step 1: Find first non-negative index 
            while(positiveIndex < size && numbers[positiveIndex] < 0) {
                negativeIndex++;
                positiveIndex++;
            }

            // Step 2: Merge negative and positive parts
            while(negativeIndex >= 0 && positiveIndex < size) {
                int leftValue = numbers[negativeIndex];
                int rightValue = numbers[positiveIndex];

                if(abs(leftValue) < rightValue){
                    squaredValues.push_back(leftValue * leftValue);
                    negativeIndex--;
                }
                else{
                    squaredValues.push_back(rightValue * rightValue);
                    positiveIndex++;
                }
            }

            // Step 3: Add remaining negative elements
            while(negativeIndex >= 0){
                int value = numbers[negativeIndex];
                squaredValues.push_back(value * value);
                negativeIndex--;
            }

            while(positiveIndex < size) {
                int value = numbers[positiveIndex];
                squaredValues.push_back(value * value);
                positiveIndex++;
            }

            traverse(squaredValues, "Printing all sorted array: ");
        }

        // Main function
        void main(){
            cout << endl << "Basic Problems: " << endl;
            
            // Two Sum Problem
            vector<int> arr = {2, 7, 11, 15};
            computeTwoSum(arr, 9);

            // IsPalindrome problem
            isPalindrome("madam");
            isPalindrome("car racing");

            // Removing duplicates in place
            vector<int> duplicateNumbers = {1, 1, 1, 2, 3, 4, 5, 5, 5};
            removeDuplicates(duplicateNumbers);

            // Moving zero elements towards right
            vector<int> numbers = {0, 1, 0, 3, 12};
            moveZeros(numbers);

            // Merge sorted array
            vector<int> sortedNumberF = {1, 3, 5, 7};
            vector<int> sortedNumberS = {2, 4, 6};
            mergeSort(sortedNumberF, sortedNumberS);

            // Container with most water
            vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
            calculateMaxContainerArea(heights);

            // Square of sorted array
            vector<int> sortedNumbers = {-4, -1, 0, 3, 10};
            computeSortedSquares(sortedNumbers);
        }
    }

    // Medium Level
    namespace medium {
        
        // Main function
        void main(){
            // CALLING ALL THE METHOD
        }
    }

    // Advance Level
    namespace advance {
        
        // Main function
        void main(){
            // CALLING ALL THE METHOD
        }
    }
    
    void main(){
        basic::main();
        medium::main();
        advance::main();
    }
}

int main() {
    cout << "Intro: " << endl;
    intro::main();

    problems::main();

    return 0;
}