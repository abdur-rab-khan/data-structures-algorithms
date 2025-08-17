# Merge Sort

> Merge Sort is popular sorting algorithm that follow [**divide and conquer**](../../../../common/05_divide_and_conquer/intro.md) approach. It works by dividing the input array into two halves by recursively, and then recursively sorted array merge into single sorted array.

- [Merge Sort](#merge-sort)
  - [Illustrating Merge Sort](#illustrating-merge-sort)
    - [Step 1](#step-1)
    - [Step 2](#step-2)
    - [Step 3](#step-3)
    - [Step 4](#step-4)

## Illustrating Merge Sort

### Step 1

![step-1](https://media.geeksforgeeks.org/wp-content/uploads/20240627163910/Merge-Sort-1.webp)

### Step 2

![step-2](https://media.geeksforgeeks.org/wp-content/uploads/20240627163910/Merge-Sort-2.webp)

### Step 3

![step-3](https://media.geeksforgeeks.org/wp-content/uploads/20240627163911/Merge-Sort-3.webp)

### Step 4

![step-4](https://media.geeksforgeeks.org/wp-content/uploads/20240627163912/Merge-Sort-4.webp)

- Working of Above Example:

    ```txt
    Divide: 
    
    [38, 27, 43, 10]  is divided into  [38, 27  ] and  [43, 10]  . 
    [38, 27]  is divided into  [38]  and  [27]  . 
    [43, 10]  is divided into  [43]  and  [10]  . 
    Conquer: 
    
    [38]  is already sorted. 
    [27]  is already sorted. 
    [43]  is already sorted. 
    [10]  is already sorted. 
    Merge: 
    
    Merge  [38]  and  [27]  to get  [27, 38]  . 
    Merge  [43]  and  [10]  to get  [10,43]  . 
    Merge  [27, 38]  and  [10,43]  to get the final sorted list  [10, 27, 38, 43] 
    Therefore, the sorted list is  [10, 27, 38, 43]  . 
    ```
