# Sorting in Array

> A **sorting algorithm** is used to re-arrange the elements of an array either in decreasing order or increasing order.

- [Sorting in Array](#sorting-in-array)
  - [Example](#example)
  - [Algorithms](#algorithms)
    - [1. Selection sort](#1-selection-sort)
      - [Example of Selection sort](#example-of-selection-sort)
    - [2. Bubble sort](#2-bubble-sort)
      - [Example of bubble sort](#example-of-bubble-sort)
    - [3. Insertion sort](#3-insertion-sort)
      - [Example of Insertion sort](#example-of-insertion-sort)
      - [Application of Insertion sort](#application-of-insertion-sort)
    - [4. Merge sort](#4-merge-sort)
      - [Example of merge sort](#example-of-merge-sort)
    - [5. Quick sort](#5-quick-sort)

## Example

- **Increasing Order**

    ```txt
    arr = [10, 2, 5, 9, 1]
    incSort = [1, 2, 5, 9, 10]
    ```

- **Decreasing  Order**

    ```cpp
    arr = [10, 2, 5, 9, 1]
    incSort = [10, 9, 5, 2, 1]
    ```

## Algorithms

### 1. Selection sort

> **Selection sort** is comparison-based sorting algorithm, it repeatedly selecting the **smallest (or largest)** element from the unsorted portion and swapping it with first unsorted element. This process continue util we reach till end of the array.

- **Time Complexity** is **o(n²)** and **Space Complexity** is **o(1)**.

#### Example of Selection sort

```cpp
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Assume minium index is "i".
        int min_index = i;

        // Finding minium element present in the array
        // If founded simply override the min_index with current j.
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                // override with current j
                min_index = j;
            }
        }

        // Swap arr[i] with min_index.
        swap(arr[i], arr[min_index]);
    }
}

void printArr(vector<int> arr) {
    for (const int& n : arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> num = {10, 3, 5, 1, 30, 4};

    selectionSort(num);
    printArr(num);

    return 0;
}
```

### 2. Bubble sort

> **Bubble sort** is simplest algorithm that works by repeatedly swapping the adjusting element if they are in wrong order. \
> This Algorithm is not suitable for large dataset it's best-case, worst-case time complexity is quite-high.

- **Time Complexity** is **o(n²)** and **Space Complexity** is **o(1)**.

#### Example of bubble sort

```cpp
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();  // Size of an array
    bool swapped = false;

    // Loop all over the array.
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Check individual elements.
        for (int j = 0; j < n - i - 1; j++) {
            // Check whether arr[j] > then arr[j + 1], if yes simply swap it.
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printArr(vector<int> arr) {
    for (const int& n : arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {10, 5, 2, 1, 16, 20};

    bubbleSort(arr);
    printArr(arr);

    return 0;
}
```

### 3. Insertion sort

> **Insertion sort** simple algorithm is used to arrange array element in sorted manner, It use iterative approach to sort the array. \
> In this algorithm sorting happen when see **`arr[i + 1]`** is smaller than **`arr[i]`**, than we starting comprising till reach to the start and find if element is smaller than previous one simply perform swapping. 

- Time Complexity
  - **Best case: o(n)**
  - **Worst and average case: o(n²)**

#### Example of Insertion sort

```cpp
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }
}

void printArr(vector<int> arr) {
    // Print all elements of arr
    for (const int& n : arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {11, 12, 13, 5, 6};

    insertionSort(arr);
    printArr(arr);

    return 0;
}
```

#### Application of Insertion sort

- The list is small or nearly sorted.
- Can be useful when array is already almost sorted.

### 4. Merge sort

> **Merge sort** is popular sorting algorithm knows for its efficiency and stability. It use [**divide and conquer**](https://www.geeksforgeeks.org/dsa/introduction-to-divide-and-conquer-algorithm/) approach which is popular approach where we divide problem into independent subproblem, and then start solving. \
> In merge sort we divide element and solving them individually and then merging them to find solution.

- Time Complexity
  - **Best case: o(n log n)**
  - **Worst and average case: o(n long n)**

#### Example of merge sort

```cpp

```

### 5. Quick sort
