#include <bits/stdc++.h>
using namespace std;

/**
 * Partitions an array around a pivot element using the Hoare partition scheme.
 *
 * This is a helper function for quicksort that rearranges elements so that:
 * - Elements greater than pivot are on the left
 * - Elements less than or equal to pivot are on the right
 * - Returns the final position of the pivot
 *
 * Note: This implementation sorts in descending order (largest elements first),
 * which is useful for finding the kth largest element efficiently.
 *
 * Example:
 * Input: numbers = [3, 2, 1, 5, 4], left = 0, right = 4
 * After partition around pivot 4: [5, 4, 1, 2, 3]
 * Returns: 1 (position of pivot)
 *
 * Time Complexity: O(n) - Scans through the array once
 * Space Complexity: O(1) - In-place partitioning
 *
 * @param numbers Reference to vector of integers to partition
 * @param left Starting index of the partition range
 * @param right Ending index of the partition range (pivot element)
 * @return Final index position of the pivot element
 */
int partition(std::vector<int>& numbers, int left, int right) {
    int pivotElem = numbers[right];

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (numbers[j] > pivotElem) {
            i++;
            std::swap(numbers[i], numbers[j]);
        }
    }

    std::swap(numbers[i + 1], numbers[right]);
    return i + 1;
}

/**
 * Finds the kth largest element in an unsorted array using quicksort selection.
 *
 * This is an optimized approach to finding the kth largest element without
 * fully sorting the entire array. It uses the quicksort partitioning algorithm
 * but only recurses into the partition containing the kth element, achieving
 * average O(n) time complexity.
 *
 * Strategy:
 * 1. Partition array around a pivot
 * 2. If pivot position is k-1, we found the kth largest
 * 3. If pivot position > k-1, search left partition
 * 4. If pivot position < k-1, search right partition
 *
 * Example:
 * Input: numbers = [3, 2, 3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
 * Output: 4th largest element (after sorting: [6, 5, 5, 4, ...], answer is 4)
 *
 * Time Complexity: O(n) average, O(n²) worst case
 * Space Complexity: O(log n) average due to recursion stack
 *
 * @param numbers Reference to vector of integers
 * @param k Position to find (1-indexed, k=1 for largest, k=2 for 2nd largest, etc.)
 * @param left Starting index of current search range
 * @param right Ending index of current search range
 */
void quickSort(std::vector<int>& numbers, int k, int left, int right) {
    if (left >= right)
        return;

    int pivotPosition = partition(numbers, left, right);

    if (pivotPosition == k - 1)
        return;

    if (pivotPosition >= k) {
        quickSort(numbers, k, left, pivotPosition - 1);
    } else {
        quickSort(numbers, k, pivotPosition + 1, right);
    }
}

int main() {
    int k1 = 4;
    std::vector<int> numbers1 = {3, 2, 3, 2, 3, 1, 2, 4, 5, 5, 6};
    quickSort(numbers1, k1, 0, numbers1.size() - 1);
    std::cout << "Kth element of the sorted array is: " << numbers1[k1 - 1] << std::endl;

    int k2 = 2;
    std::vector<int> numbers2 = {3, 2, 1, 5, 6, 4};
    quickSort(numbers2, k2, 0, numbers2.size() - 1);
    std::cout << "Kth element of the sorted array is: " << numbers2[k2 - 1] << std::endl;

    return 0;
}