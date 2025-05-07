#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> m = {{1, "Dog, Cat"}, {2, "Goat, Sheep"}};

    // m.insert({2, "Tiger Lion"});

    // m[2] = "Panda, Koala";

    // // Assessing Elements
    // cout << m.at(2) << endl;
    // cout << m[1] << endl;

    // m.at(1) = "Cow, Goat";
    // m[2] = "Tiger, Lion";

    // // Assessing Element based on key

    // auto it = m.find(2);

    // if (it != m.end()) {
    //     cout << "Element is found " << "Key is: " << it->first << " Value is " << it->second
    //          << endl;
    // } else {
    //     cout << "Error: Element is not found" << endl;
    // }

    // auto it2 = m.find(55);

    // if (it2 != m.end()) {
    //     cout << "Element is found " << "Key is: " << it->first << " Value is " << it->second
    //          << endl;
    // } else {
    //     cout << "Error: Element is not found" << endl;
    // }

    // cout << endl << endl;
    // for (auto& value : m) {
    //     cout << "Value is  " << value.first << " " << value.second << endl;
    // }

    // for (auto it = m.begin(); it != m.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }

    cout << m.begin()->first << " " << m.begin()->second << endl;
    cout << next(m.begin(), 2)->second << endl;

    return 0;
}