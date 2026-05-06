#include <bits/stdc++.h>
using namespace std;

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    🫧 Bubble Sort                                                                                                   |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 Step-by-Step Process:                                                                                                                                                                                            |
|     1. Start from the first element (index 0)                                                                                                                                                                       |
|     2. Compare the current element with the next element                                                                                                                                                            |
|     3. If current element > next element, swap them                                                                                                                                                                 |
|     4. Move to the next element and repeat steps 2-3                                                                                                                                                                |
|     5. After one complete pass, the largest element moves to the end                                                                                                                                                |
|     6. Repeat the process for the remaining unsorted elements (reduce range by 1 each pass)                                                                                                                         |
|     7. Continue until no swaps occur or all elements are sorted                                                                                                                                                     |
|                                                                                                                                                                                                                     |
| 🔷 Time Complexity: O(n²) | Space Complexity: O(1)                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
| 🔷 Example: "https://claude.ai/chat/c195e2ea-9977-4209-a456-53ffc54f8792"                                                                                                                                           |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace bubbleSort {
    void bubbleSort(vector<int>& numbers) {
        int size = numbers.size();
        bool isSwapped = false;

        for (int i = 0; i < size - 1; i++) {
            isSwapped = false;

            for (int j = 0; j < size - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    isSwapped = true;
                    swap(numbers[j], numbers[j + 1]);
                }
            }

            // Everything is already sorted.
            if (!isSwapped)
                break;
        }
    }

    void main() {
        vector<int> num1 = {3, 5, 1, 6, 2, 7, 4, 8};
        bubbleSort(num1);

        cout << "Bubble sort: " << endl << endl;
        cout << "Array elements are: ";
        for (const int& num : num1) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
}  // namespace bubbleSort

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    🫳 Selection Sort                                                                                                |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 Step-by-Step Process:                                                                                                                                                                                            |
|     1. Start with the first element (index 0)                                                                                                                                                                       |
|     2. Find the smallest element in the remaining unsorted array                                                                                                                                                    |
|     3. Swap the smallest element with the current element at index i                                                                                                                                                |
|     4. Move to the next index (i + 1)                                                                                                                                                                               |
|     5. Repeat steps 2-4 until the entire array is sorted                                                                                                                                                            |
|     6. Each iteration places one element in its correct sorted position                                                                                                                                             |
|                                                                                                                                                                                                                     |
| 🔷 Time Complexity: O(n²) | Space Complexity: O(1)                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace selectionSort {
    void selectionSort(vector<int>& numbers) {
        int size = numbers.size();

        for (int i = 0; i < size - 1; i++) {
            int smallestIdx = i;

            for (int j = i + 1; j < size; j++) {
                if (numbers[j] < numbers[smallestIdx]) {
                    smallestIdx = j;
                }
            }

            swap(numbers[i], numbers[smallestIdx]);
        }
    }

    void main() {
        vector<int> num1 = {3, 5, 1, 6, 2, 7, 4, 8};
        selectionSort(num1);

        cout << "Selection sort: " << endl << endl;
        cout << "Array elements are: ";
        for (const int& num : num1) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
}  // namespace selectionSort

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    ➕ Insertion Sort                                                                                                |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 Step-by-Step Process:                                                                                                                                                                                            |
|     1. Start from the second element (index 1)                                                                                                                                                                      |
|     2. Store the current element in a temporary variable                                                                                                                                                            |
|     3. Compare the current element with elements before it (from right to left)                                                                                                                                     |
|     4. If the previous element is greater, shift it one position to the right                                                                                                                                       |
|     5. Continue shifting until the correct position is found                                                                                                                                                        |
|     6. Insert the current element into its correct position                                                                                                                                                         |
|     7. Move to the next element and repeat steps 2-6                                                                                                                                                                |
|     8. Continue until all elements are sorted                                                                                                                                                                       |
|                                                                                                                                                                                                                     |
| 🔷 Time Complexity: O(n²) | Space Complexity: O(1)                                                                                                                                                                  |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace insertionSort {
    void insertionSort(vector<int>& numbers) {
        int size = numbers.size();

        for (int i = 1; i < size; i++) {
            int j = i - 1;
            int elem = numbers[i];

            while (j >= 0 && numbers[j] > elem) {
                numbers[j + 1] = numbers[j];
                j--;
            }
            numbers[j + 1] = elem;
        }
    }

    void main() {
        vector<int> num1 = {3, 5, 1, 6, 2, 7, 4, 8};
        insertionSort(num1);

        cout << "Insertion sort: " << endl << endl;
        cout << "Array elements are: ";
        for (const int& num : num1) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
}  // namespace insertionSort

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    ✌️ Merge Sort                                                                                                    |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 Step-by-Step Process (Divide and Conquer):                                                                                                                                                                       |
|     Divide Phase:                                                                                                                                                                                                   |
|     1. Divide the array into two equal halves (middle = size/2)                                                                                                                                                     |
|     2. Recursively divide the left half until single elements remain                                                                                                                                                |
|     3. Recursively divide the right half until single elements remain                                                                                                                                               |
|                                                                                                                                                                                                                     |
|     Merge Phase:                                                                                                                                                                                                    |
|     4. Compare the first elements of both sorted subarrays                                                                                                                                                          |
|     5. Place the smaller element in the result array                                                                                                                                                                |
|     6. Move the pointer of the subarray from which element was taken                                                                                                                                                |
|     7. Repeat steps 4-6 until one subarray is exhausted                                                                                                                                                             |
|     8. Copy remaining elements from the non-empty subarray                                                                                                                                                          |
|     9. The merged result is now a sorted array                                                                                                                                                                      |
|                                                                                                                                                                                                                     |
| 🔷 Time Complexity: O(n log n) | Space Complexity: O(n)                                                                                                                                                             |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace mergeSort {
    void merge(vector<int>& numbers, int left, int mid, int right) {
        int firstTempSize = mid - left + 1;
        int secondTempSize = right - mid;

        // Step 1. Creating temp vectors.
        vector<int> firstTemp(firstTempSize), secondTemp(secondTempSize);

        // Step 2. Copying elements to temp vector.
        for (int i = 0; i < firstTempSize; i++)
            firstTemp[i] = numbers[left + i];

        for (int j = 0; j < secondTempSize; j++)
            secondTemp[j] = numbers[mid + 1 + j];

        // Step 3. Merging the elements in a sorted manner
        int i = 0, j = 0;
        int k = left;

        while (i < firstTempSize && j < secondTempSize) {
            if (firstTemp[i] <= secondTemp[j]) {
                numbers[k] = firstTemp[i];
                i++;
            } else {
                numbers[k] = secondTemp[j];
                j++;
            }
            k++;
        }

        // Step 4. Merging remaining numbers
        while (i < firstTempSize) {
            numbers[k] = firstTemp[i];
            i++;
            k++;
        }

        while (j < secondTempSize) {
            numbers[k] = secondTemp[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& numbers, int left, int right) {
        // Step 1. Base condition
        if (left >= right)
            return;

        // Step 2. Dividing into two equal parts
        int mid = left + (right - left) / 2;

        // Step 3. Dividing start to mid again.
        mergeSort(numbers, left, mid);

        // Step 4. Dividing mid + 1 to end again.
        mergeSort(numbers, mid + 1, right);

        // Step 5. Merging and sorting both divided array part.
        merge(numbers, left, mid, right);
    }

    void main() {
        vector<int> num1 = {3, 5, 1, 6, 2, 7, 4, 8};
        mergeSort(num1, 0, num1.size() - 1);

        cout << "Merge sort: " << endl << endl;
        cout << "Array elements are: ";
        for (const int& num : num1) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
}  // namespace mergeSort

/*
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                    🏃 Quick Sort                                                                                                    |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                                                                     |
| 🟡 Step-by-Step Process (Divide and Conquer):                                                                                                                                                                       |
|     1. Choose a "pivot" (could be "left", "right") element from the array                                                                                                                                           |
|     2. Partition the array so that:                                                                                                                                                                                 |
|        - All elements smaller than pivot are on the left                                                                                                                                                            |
|        - All elements greater than pivot are on the right                                                                                                                                                           |
|        - Pivot is now in its final sorted position                                                                                                                                                                  |
|     3. Recursively apply steps 1-2 to the left subarray                                                                                                                                                             |
|     4. Recursively apply steps 1-2 to the right subarray                                                                                                                                                            |
|     5. Continue until all subarrays are sorted (base case: array size ≤ 1)                                                                                                                                          |
|                                                                                                                                                                                                                     |
| 🔷 Time Complexity: O(n log n) average, O(n²) worst case | Space Complexity: O(log n)                                                                                                                               |
|                                                                                                                                                                                                                     |
+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
namespace quickSort {
    int partition(vector<int>& numbers, int left, int right) {
        // Step 1. Declaring pivot point as a "left" value.
        int pivotElem = numbers[right];

        // Step 2. Arranging smaller than "pivot" element towards pivots "left" and grater towards pivots "right".
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (pivotElem > numbers[j]) {
                i++;
                swap(numbers[i], numbers[j]);
            }
        }

        // Step 3. Placing pivot element to the correct position.
        swap(numbers[i + 1], numbers[right]);
        return i + 1;
    }

    void quickSort(vector<int>& numbers, int left, int right) {
        // Step 1. Base condition (when only single element is there)
        if (left >= right)
            return;

        // Step 2. Calculating pivot point
        int pivotPoint = partition(numbers, left, right);

        // Step 3. Calling recursively quick sort for "left" and "right" side of pivot point
        quickSort(numbers, left, pivotPoint - 1);
        quickSort(numbers, pivotPoint + 1, right);
    }

    void main() {
        vector<int> num1 = {3, 5, 2, 1, 4, 3};
        quickSort(num1, 0, num1.size() - 1);

        cout << "Quick sort: " << endl << endl;
        cout << "Array elements are: ";
        for (const int& num : num1) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
}  // namespace quickSort

int main() {
    // bubbleSort::main();
    // selectionSort::main();
    // insertionSort::main();
    // mergeSort::main();
    quickSort::main();

    return 0;
}
