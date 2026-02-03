#include <bits/stdc++.h>
using namespace std;

/*
    <======================> JUGGLING ALGORITHM <======================>
    ◉ So the idea behind this algorithm is to rotate array elements by using cycles (find using
   gcd).
    ◉ GCD helps to find greater number that is divisible by both of them.
    ◉ Each cycle starts from "i" and go (currIdx + d) % n till when (currIdx + d) % n reach "i".
    ◉ And Each time we exchange the currIdx to nextIdx we will in details ⬇️.

    <======================> HOW GCD WORKS <======================>
    arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12] k = 4
    ◉ Suppose we have circular game board with 12 spaces, numbered from 1 to 12;
    ◉ We will decide to move exactly 4 spaces for each turn.
    ◉ Our Task is to visit all piece forward. So write down how many turn it will take to visit all
   the pieces.

    ◉ Start Visiting.

    Turn 0:
            ( 0 + 4 ) % 12 = 4 , arr[4] = 4;
            ( 4 + 4 ) % 12 = 8 , arr[8] = 8;
            ( 8 + 4 ) % 12 = 0, arr[0]  = 0;

        At first turn we get {0, 4, 8}

    Turn 1:
            ( 1 + 4 ) % 12 = 5;
            ( 5 + 4 ) % 12 = 9;
            ( 9 + 4 ) % 13 = 1;

        At second turn we get {1, 5, 9}

    Turn 2:
            ( 2 + 4 ) % 12 = 6;
            ( 6 + 4 ) % 12 = 10;
            ( 10 + 4 ) % 12 = 2;

        At third turn we get {6, 10 , 2}

    Turn 3:
            ( 3 + 4 ) % 12 = 7;
            ( 7 + 4 ) % 12 = 11;
            ( 11 + 4 ) % 12 = 3;

        At forth turn we get {7, 11, 3}

    Total = [{0, 4, 8}, {5, 9, 1}, {6, 10, 2}, {7, 11, 3}]

    ==> IMPORTENT: To guess how many turn i will take to visit all pieces of game by forwarding
   toward right 4.
   ==> For this situation "GCD" shines we helps us to find greater common divisor that divide both
   of them into 4 pieces.


   <==================> Example 2 <=======================>
   arr = [0, 1, 2, 3, 4], k = 2, gcd = 1 (How many turn it will take to visit all elements).

   Turn 0:
            ( 0 + 1 ) % 5 = 1;
            ( 1 + 1 ) % 5 = 2;
            ( 2 + 1 ) % 5 = 3;
            ( 3 + 1 ) % 5 = 4;
            ( 4 + 1 ) % 5 = 0;

        arr = {0, 1, 2, 3, 4} Visit all elements.
*/

void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();

    d %= n;  // Handle cases where d > size of array

    int cycles = __gcd(n, d);

    for (int i = 0; i < cycles; i++) {
        int temp = arr[i];
        int currIdx = i, nextIdx;

        while (true) {
            nextIdx = (currIdx + d) % n;

            if (nextIdx == i)
                break;

            arr[currIdx] = arr[nextIdx];
            currIdx = nextIdx;
        }

        arr[currIdx] = temp;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int d = 2;

    rotateArr(arr, d);

    for (const int n : arr)
        cout << n << " ";

    return 0;
}