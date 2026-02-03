#include <bits/stdc++.h>
using namespace std;

int main() {
    string day = "Tuesday";


    switch (day[0]) {
        case 'M':
            cout << "It's Monday!" << endl;
            break;
        case 'T':
            if (day == "Tuesday") {
                cout << "It's Tuesday!" << endl;
            } else {
                cout << "It's Thursday!" << endl;
            }
            break;
        case 'W':
            cout << "It's Wednesday!" << endl;
            break;
        case 'F':
            cout << "It's Friday!" << endl;
            break;
        case 'S':
            if (day == "Saturday") {
                cout << "It's Saturday!" << endl;
            } else {
                cout << "It's Sunday!" << endl;
            }
            break;
        default:
            cout << "Invalid day!" << endl;
    }
    

    return 0;
}