#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string firstName = "Abdur Rab ";
    string lastName;

    lastName.push_back('K');
    lastName.push_back('H');
    lastName.push_back('A');
    lastName.push_back('N');

    cout << firstName;
    cout << lastName << endl;

    // Access Element using INDEX
    cout << firstName[0] << firstName[1] << firstName[2] << firstName[3] << firstName[4] << endl;

    // Tokenizing String
    string line = "Abdur Rab Khan";
    stringstream ss(line);
    string token;

    while (getline(ss, token, ' ')) {
        cout << token << endl;
    }

    return 0;
}