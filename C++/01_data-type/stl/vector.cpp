/*
+---------------------------------------------+ VECTOR IN C++ +-------------------------------------------+
|                                                                                                         |
| 🟡Vector is used to store data in a contiguous memory location without thinking about memory allocation |
|   and deallocation.                                                                                     |
|                                                                                                         |
| 
|                                                                                                         |
+--------------------------------------------------+ END +------------------------------------------------+
*/

#include <iostream>
#include <vector>

using namespace std;

struct Entry {
  string name;
  int number;
};

void print_book(const vector<Entry>& vec) {
  if(vec.size() == 0) return; // If no element is there

  for(int i = 0; i < vec.size(); i++) {
     cout << vec[i].name + " --- " << vec[i].number << endl; 
  }
}

int main() {
  // Phone book vector
  vector<Entry> phone_book = {
    {
      "David Hume", 12345
    },
    {
      "Karl Popper", 590402 
    },
    {
      "Bertrant", 2434242 
    },
  };

  // Printing the elements of vector
  print_book(phone_book);

}
