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

    bool isSafe(int row, int col) {
        for (int prevRow = 0; prevRow < row; prevRow++) {
            int prevCol = queenCol[prevRow];

            // check 1: same column, it will tell us because "prevCol" tells about the column where queen is placed.
            if (prevCol == col) {
                return false;
            }

            // The Idea to check whether something is there on diagonal or not is by checking the difference between "prevRow" and "row".
            // If something is there on diagonal mean the different between "prevRow" and "row" will be the same of "prevCol" and "col".
            // Example:
            //          [
            //              0, 0, 0, Q
            //              0, 0, 0, 0
            //              0, C, 0, 0
            //              0, 0, 0, 0
            //          ]
            // there a queen placed, on row 0 and col 3
            // and we are trying to place queen at row 2 and col 1, let's check something on diagonal or not.
            // start from row 0, abs(prevRow - row) = (2 - 0) = 2, and abs(prevCol - col) = (3 - 1) = 2, 2 == 2 mean something is already placed on diagonal.
            // * NOTE: HOW ITS WORKING, THE DISTANCE BETWEEN CURRENT ROW AND COL IS EQUAL TO abs(prevRow - row) == abs(prevCol - col)
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
