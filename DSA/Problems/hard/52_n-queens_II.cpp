#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    Solution() : totalNQueensBoard(0) {}

    int totalNQueens(int n) {
        backTracking(n, 0);
        return totalNQueensBoard;
    }

   private:
    vector<int> queenCol;
    int         totalNQueensBoard;

    bool isSafe(int row, int col) {
        for (int prevRow = 0; prevRow < row; prevRow++) {
            int prevCol = queenCol[prevRow];

            // check 1: same column?
            if (prevCol == col)
                return false;

            // check 2: same diagonal
            // To understand how actually this formula works to find whether something already there on diagonal or not:
            //      1. Suppose we have this board:
            //              Q...
            //              .Q..
            //              ..Q..
            //      * Look everything is at diagonal, and if you look at the pattern the difference between where "queen" is placed on a row at diagonal is the "distance between", "current row - that row" == "current column - that column"
            //      * At 0th row queen is placed at 0, and at 3 it placed at 3, means it's at diagonal how, "abs(prevRow - row) == abs(prevCol - col)" = "abs(0 - 3)" == abs(0 - 3) = 3 == 3.
            if (abs(prevRow - row) == abs(prevCol - col))
                return false;
        }
        return true;
    }

    void placeQueen(int col) { queenCol.push_back(col); }

    void removeQueen() { queenCol.pop_back(); }

    void backTracking(int n, int row) {
        // placing the current board result into the result;
        if (row == n) {
            totalNQueensBoard += 1;
            return;
        }

        for (int i = 0; i < n; i++) {
            // check whether it's safe to place the queen, means queen isn't already place at prevous same "column" and previous "diagonals"
            if (!isSafe(row, i))
                continue;

            placeQueen(i);
            backTracking(n, row + 1);
            removeQueen();
        }
    }
};

int main() {
    Solution sol;
    print(sol.totalNQueens(4), "Total n queens are: ");

    return 0;
}
