# Searching in Array

> Searching is a process of find the specific element in the collection of data and return their position (index).

- [Searching in Array](#searching-in-array)
  - [Two most Common algorithms](#two-most-common-algorithms)
    - [1. Linear Search](#1-linear-search)
      - [Simple Linear Search](#simple-linear-search)
      - [Improved Linear Search](#improved-linear-search)
      - [Example of Linear Search](#example-of-linear-search)
    - [Binary Search](#binary-search)
      - [Example of Binary Search](#example-of-binary-search)

## Two most Common algorithms

### 1. Linear Search

> It is mainly used to perform searching operation on **unsorted** array, it takes linear time complexity **o(n)**.

#### Simple Linear Search

```cpp
#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int x) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

int main() {
    vector<int> arr = {5, 1, 5, 1, 2, 36, 2};

    cout << "1 in arr is at: " << (linearSearch(arr, 1)) << endl;

    return 0;
}
```

#### Improved Linear Search

> There are some situations where you want to search same element **again and again**, So if we use above algorithm we have to search same element with same complexity all time.

- Linear search can be improved by using the following two methods.

    1. **Transposition**
       - In **transposition**, If the key element is found, we will swap the element with its ahead element to decrease the time complexity for next time search.
       - Suppose we have **`arr[] = {1, 4, 5, 6, 7}`** and **`x = 6`**:
            1. For first time we search `6` in `arr` with time complexity of o(3), then we will swap `5` to `6` to decrease time complexity next time.
       - By using this, We can perform search of `6` in Constant time.
       - It is commonly use in the situation where needs of same element are happening.
    2. **Move to front**
       - In this technique, We search that element if founded than we swap that element with first element.
       - It is helpful for finding same element all time.

#### Example of Linear Search

```cpp
#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int x) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

int main() {
    vector<int> arr = {5, 1, 5, 1, 2, 36, 2};

    cout << "1 in arr is at: " << (linearSearch(arr, 1)) << endl;

    return 0;
}
```

### Binary Search

> It is mainly used to perform searching operation on **sorted** array. It use [**divide and conquer**](../../../common/05_divide_and_conquer/intro.md) in here we divide array into two part and if middle element is same simply return index, otherwise we go either **left** or **right** based on comparing result (whether **greater** or **smaller**). This algorithms is faster then linear search and takes **o(Log(n))** time.

- Few condition array should  have to follow for binary search.
    1. The data structure must be sorted.
    2. Access to any element of the data structure should take constant time.

- Step-by-Step build for binary search algorithm
    1. Divide the array into two half part by finding the middle index "mid".
    2. Compare the middle element with the **key**.
    3. If **key** is matched, simply terminate the program.
    4. If **key** not match, choose which half part will search next.
        - If the **key** is smaller than middle element, then left side is used for next search.
        - If the **key** is greater than middle element, then right side is used for next search.
    5. The process is continued until the **key** is found or total space **exhausted**.

#### Example of Binary Search

```cpp
#include <bits/stdc++.h>
using namespace std;

int binarySearchR(vector<int>& arr, int target, int left, int right) {
    // If space is exhausted
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    // Check -- Whether arr[mid] == target
    if (arr[mid] == target)
        return mid;

    return (arr[mid] > target ? binarySearchR(arr, target, left, mid - 1)
                              : binarySearchR(arr, target, mid + 1, right));
}

int binarySearchL(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int x = 1;

    cout << x << " is found at: " << binarySearchR(arr, x, 0, arr.size() - 1) << "\n";
    cout << x << " is found at: " << binarySearchL(arr, x) << "\n";
    return 0;
}
```
