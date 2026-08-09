#include <cstdlib>
#include <string>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

/*
 * Before looking at the code, you need to understand the rules to place the "queen" on the board.
 * To place the "queen" we usually have three rules:
 *  1. Only one queen per row.
 *  2. Only one queen per column.
 *  3. No multiple queens on the same diagonal.
 *
 * So the solution is go for each combination, mean go deeper and deeper to pick the correct solution.
*/
class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTracking(board, n, 0);
        return result;
    }

   private:
    vector<int>            queenCol;
    vector<vector<string>> result;

    // So, the idea is I know that there will be "n" queens that will going to place into the board to make checking more easier.
    // To make checking easier, we'll create an extra array size n, where we only store the queen once we got it means for row 0
    // I'll push the position of "row 0" queen, by using this we can easily check whether it's safe to place or not.
    bool isSafe(int row, int col) {
        for (int prevRow = 0; prevRow < row; prevRow++) {
            int prevCol = queenCol[prevRow];

            // check 1: same column, it will tell us because "prevCol" tells about the column where queen is placed.
            if (prevCol == col) {
                return false;
            }

            // check 2: same diagonal
            if (abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }

    void placeQueen(vector<string>& board, int row, int col) {
        board[row][col] = 'Q';
        queenCol.push_back(col);
    }

    void removeQueen(vector<string>& board, int row, int col) {
        board[row][col] = '.';
        queenCol.pop_back();
    }

    void backTracking(vector<string>& board, int n, int row) {
        // placing the current board result into the result;
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            // check whether it's safe to place the queen, means queen isn't already place at prevous same "column" and previous "diagonals"
            if (!isSafe(row, i))
                continue;

            placeQueen(board, row, i);
            backTracking(board, n, row + 1);
            removeQueen(board, row, i);
        }
    }
};

int main() {
    Solution sol;
    print(sol.solveNQueens(4));
    return 0;
}
