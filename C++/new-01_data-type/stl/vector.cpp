/*
+---------------------------------------------+ VECTOR IN C++ +-------------------------------------------+
|                                                                                                         |
|                                                                                                         |
|                                                                                                         |
|                                                                                                         |
|                                                                                                         |
|                                                                                                         |
|                                                                                                         |
|                                                                                                         |
+--------------------------------------------------+ END +------------------------------------------------+
*/


#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> nums = {10, 20, 30, 40, 50};
  size_t s = nums.size(); // Gives the number of element nums holded.

  cout << "Traversing in nums through for loop: -- " << endl;
  for(int i = 0; i < s; i++){
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
