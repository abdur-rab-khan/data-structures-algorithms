#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::next_permutation;
using std::prev_permutation;
using std::sort;
using std::vector;

vector<int> nums = {1, 2, 3};

// 👉 next_permutation: It's directly modify the origin "data-structure" and does all the possible permutation until it give false.
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
void usingNextPermutation() {
    cout << "--> Using next permutation: " << endl;

    do {
        cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
    } while (next_permutation(nums.begin(), nums.end()));
}

// 👉 prev_permutation: It's similar to "next_permutation", but this one goes in reverse order
void usingPrevPermutation() {
    cout << endl << "--> Using prev permutation: " << endl;

    do {
        cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
    } while (prev_permutation(nums.begin(), nums.end()));
}

int main() {
    usingNextPermutation();
    usingPrevPermutation();
}