#include <bits/stdc++.h>
using namespace std;

/*
     <====================> Pattern Searching <===================>

     ◉ Pattern Searching is an algorithm that involves searching for pattern on "string", "word",
        "images" etc.
     ◉ There are certain algorithm that are used to perform search operation, and the complexity of
        algorithm varies from algorithm to algorithm.
     ◉ These algorithms are very useful to perform search operation in database. The Pattern
        Searching Algorithm is useful for finding pattern in substrings of large string.

     ◉ NATIVE PATTERN SEARCHING ALGORITHM:
        ◉ The native pattern searching algorithm is the simplest algorithm among other algorithms.
             It check all character of main string to the pattern.
        ◉ It does not need any pre-process phases. We can find the sub-string by checking once for
             the string.
        ◉ It does not occupy any extra-space to perform the operation.


     <====================> Example <===================>

     text = "AABAACAADAABAAABAA";
     pattern = "AABA"
      0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
     [A, A, B, A, A, C, A, A, D, A, A, B, A, A, A, B, A, A]

     ◉ We can see the pattern at these indices.
      0                              9               13
     [| A, A, B, A, | A, C, A, A, D, | A, A, B, A, | | A, A, B, A, | A]
*/

void searchPtr(char* str, char* ptr) {
    int N = strlen(str);
    int M = strlen(ptr);

    // A Loop that slide pat[] one by one
    for (int i = 0; i < N; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < M; j++) {
            if (str[i + j] != ptr[j])
                break;
        }

        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";

    // Function call
    searchPtr(txt, pat);

    return 0;
}