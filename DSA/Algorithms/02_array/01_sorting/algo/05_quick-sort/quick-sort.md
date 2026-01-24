# Quick Sort

> **Quick sort** is very efficient sorting algorithm based on [**Divide and Conquer**](../../../../common/05_divide_and_conquer/intro.md) concept that use
pivot point to pick an element and re-arrange the given array around the picked pivot.

- [Quick Sort](#quick-sort)
  - [Steps of Quick Sort Algorithm](#steps-of-quick-sort-algorithm)
    - [1. Choose a Pivot](#1-choose-a-pivot)
    - [2. Re arrange the Array](#2-re-arrange-the-array)
    - [3. Recursively Call](#3-recursively-call)
    - [4. Base Case](#4-base-case)
  - [Partition Algorithm](#partition-algorithm)
    - [1. Naive Partition](#1-naive-partition)
    - [2. Lomuto Partition](#2-lomuto-partition)
      - [Example](#example)
    - [3. Hoare's Partition](#3-hoares-partition)

## Steps of Quick Sort Algorithm

### 1. Choose a Pivot

- Selection an element from the array as the pivot.
- The choice of pivot can vary (e.g **first element**, **last element**, **random element** or **median**)

### 2. Re arrange the Array

- In this step, we re-arrange the array around the pivot point.
- After **partitioning**, all smaller elements than the pivot will be re-arrange on it's left.
- All greater elements than pivot will be re-arrange on it's right.

### 3. Recursively Call

- Than after apply the same process recursively to two partitioned sub-arrays.

### 4. Base Case

- The recursion will step when there is only one element left in the sub-array, means single element is already sorted.

- Basic overview of how the **QuickSort** algorithm works.

    ![illustrating-quick-sort-algorithm](https://media.geeksforgeeks.org/wp-content/uploads/20240926172924/Heap-Sort-Recursive-Illustration-660.webp)

## Partition Algorithm

- The key process in **quick sort** is **partition().** There are commonly three algorithms are their with **o(n)** time complexity.

### 1. Naive Partition

- In the naive approach we create copy of the array, and first put all smaller elements and than all greater elements.
- Finally we copy the temporary array back to original array.
- This required **o(n)** extra space.

```cpp
void partitionArr(vector<int> &arr, int low, int high){
  int pivot = arr[low]; // Choose pivot as first element

  vector<int> temp; // Temporary array to store data

  // Let's first push all smaller element in temp
  for(int i = low + 1; i <= high; i++){
    if(arr[i] <= pivot){
      temp.push_back(arr[i]);
    }
  }

  // We can say that here all elements put into the temp are smaller than pivot, this is the time to push pivot
  temp.push_back(pivot);

  // Let's push all greater element in temp
  for(int j = low; j <= high; j++){
    if(arr[j] > pivot){
      temp.push_back(arr[j]);
    }
  }

  arr = temp;
}
```

### 2. Lomuto Partition

- In this approach we does not use any extra space instead of play with index and swapping.
- We keep track of index of smaller elements and keep swapping.

#### Example

```cpp
int partition(vector<int>& arr, int low, int high){
    int n = arr.size();

    // choosing the pivot as arr[low]
    int pivot = arr[low];

    
}
```

### 3. Hoare's Partition

- This is the fastest algorithm as compare with previous one.
- Here we using two pointer technique where we traverse array from both sides and keep swapping greater element on left with smaller on right.