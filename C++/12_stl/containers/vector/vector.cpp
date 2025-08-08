#include <bits/stdc++.h>
using namespace std;

int main() {
    // Perform insert operation in vector
    vector<char> firstName = {'A', 'D', 'U'};

    // Insert 'R' at the end of firstName
    firstName.push_back('R');

    // Insert at first index, firstName.begin() represent 0 index + 1 = 1
    firstName.insert(firstName.begin() + 1, 'B');

    // Access all element
    for (int i = 0; i < firstName.size(); i++)
        cout << firstName[i];

    cout << endl;

    // <==============> Retrieve Elements <==============>
    vector<char> sample = {'a', 'b', 'c', 'd', 'f', 'g'};

    cout << sample[2] << endl;
    cout << sample.at(5) << endl;

    sample[2] = 'C';
    sample.at(5) = 'G';

    cout << sample[2] << endl;
    cout << sample.at(5) << endl;

    // <==============> Traversing on Vector <==============>
    // Using ForLoop
    for (int i = 0; i < sample.size(); i++)
        cout << sample[i];
    cout << endl << endl;

    // Using ForEach
    for (const auto c : sample)
        cout << c;
    cout << endl << endl;

    // Reverse Traversing
    for (auto it = sample.rbegin(); it != sample.rend(); ++it) {
        cout << *(it);
    }
    cout << endl << endl;

    // <==============> Deletion on Vector <==============>
    sample.pop_back();  // abcdf

    // Deleting element 'f'
    sample.erase(find(sample.begin(), sample.end(), 'f'));  // abcd

    for (const auto c : sample)
        cout << c;
    cout << endl << endl;

    cout << sample.empty() << endl;

    return 0;
}