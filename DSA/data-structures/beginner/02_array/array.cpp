#include <bits/stdc++.h>
using namespace std;

void traversingTechniques(vector<int> arr) {
  // Traversing using for loop
  cout << "Elements of an array are: ";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ' ';

    if (i == arr.size() - 1)
      cout << endl;
  }

  // Traversing using for each loop;
  cout << "Elements of an array are: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

void reverseArray(vector<int> arr) {
  int i = 0, j = arr.size() - 1;
  while (i < j) {
    // XOR FOR SWAPPING
    arr[i] ^= arr[j], arr[j] ^= arr[i], arr[i] ^= arr[j];

    i++;
    j--;
  }

  traversingTechniques(arr);
}

void findMinmax(vector<int> arr) {
  int min = INT_MAX;
  int max = INT_MIN;

  for (int i = 0; i < arr.size(); i++) {
    // Finding min value
    if (min > arr[i]) {
      min = arr[i];
    }

    // Finding max value
    if (max < arr[i]) {
      max = arr[i];
    }
  }

  cout << "Min value is: " << min << endl;
  cout << "Max value is: " << max << endl;
}

void countFrequency(vector<int> arr) {
  map<int, int> count;

  // Counting element frequency
  for (int i = 0; i < arr.size(); i++)
    count[arr[i]]++;

  // Printing all the frequency
  for (auto cf : count) {
    cout << "Total count frequency of " << cf.first << " is: " << cf.second
         << endl;
  }
}

int main() {
  // Initializing vector
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr2 = {55, 44, 33, 22, 11};
  vector<int> arr3 = {1, 2, 1, 2, 5, 6, 7, 6};

  // Traversing Techniques
  traversingTechniques(arr);

  // Revering an array
  reverseArray(arr2);

  // Find min, max
  findMinmax(arr2);

  // Count element frequency
  countFrequency(arr3);

  return 0;
}
