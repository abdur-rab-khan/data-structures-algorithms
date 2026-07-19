#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using std::count;
using std::count_if;
using std::cout;
using std::endl;
using std::find;
using std::find_if;
using std::function;
using std::vector;

vector<int> nums = {4, 20, 81, 500, 2, 1, 52, 1};

// 👉 count: Return how many times "val" appear within the range
void usingCount() {
  cout << "--> Using Count: " << endl;

  int numberOfTwoAppears = count(nums.begin(), nums.end(), 1);  // 1 --> 2
  int numberOfFourAppears = count(nums.begin(), nums.end(), 4); // 4 --> 1

  cout << "Number of times 1 appears: " << numberOfTwoAppears << endl;
  cout << "Number of times 4 appears: " << numberOfFourAppears << endl;
}

// 👉 count_if: It's similar to "count", but we can pass a function to count
// element by condition
void usingCountIf() {
  cout << endl << "--> Using Count-If: " << endl;

  auto isEven = [](int i) { return i % 2 == 0; };
  function<bool(int i)> isOdd = [](int i) { return i % 2 != 0; };

  int oddCounts = count_if(nums.begin(), nums.end(), isOdd);
  int evenCounts = count_if(nums.begin(), nums.end(), isEven);

  cout << "Number of odds are: " << oddCounts << endl;
  cout << "Number of evens are: " << evenCounts << endl;
}

// 👉 find: Return an iterator of first element if it matched, otherwise return
// end()
void usingFind() {
  cout << endl << "--> Using Count-If: " << endl;

  vector<int>::iterator isFourExists = find(nums.begin(), nums.end(), 4);
  vector<int>::iterator isFiveExits = find(nums.begin(), nums.end(), 5);

  if (isFourExists == nums.end()) {
    cout << "Four isn't exist" << endl;
  } else {
    cout << "The number four is exists: " << *isFourExists << endl;
  }

  if (isFiveExits == nums.end()) {
    cout << "Five isn't exist" << endl;
  } else {
    cout << "The number five exists: " << *isFiveExits << endl;
  }
}

// 👉 find_if: Return an iterator of first matched element using given function,
// otherwise return end
void usingFindIf() {
  cout << endl << "--> Using Count-If: " << endl;

  auto isEven = [](int i) { return i % 2 == 0; };

  vector<int>::iterator firstEven = find_if(nums.begin(), nums.end(), isEven);

  if (firstEven == nums.end()) {
    cout << "No even exists" << endl;
  } else {
    cout << "First even is found: " << *firstEven << endl;
  }
}

int main() {
  usingCount();
  usingCountIf();

  usingFind();
  usingFindIf();

  return 0;
}
