#include <iostream>
using namespace std;

// int guessDiesOpp(int n) {
//     int guess;

//     switch (n) {
//         case 1:
//             guess = 4;
//             break;
//         case 2:
//             guess = 5;
//             break;
//         case 3:
//             guess = 6;
//             break;
//         case 4:
//             guess = 1;
//             break;
//         case 5:
//             guess = 2;
//             break;
//         case 6:
//             guess = 3;
//             break;
//         default:
//             break;
//     }

//     return guess;
// }

int guessDiesOpp(int n) {
    if (n < 1 || n > 6) {
        std::invalid_argument("Invalid argument should be between 1 to 6");
    }

    return 7 - n;
}

int main() {
    int choice = 6;
    int oppFace = guessDiesOpp(choice);

    cout << "The Opposite of " << choice << " is " << oppFace;
    return 0;
}