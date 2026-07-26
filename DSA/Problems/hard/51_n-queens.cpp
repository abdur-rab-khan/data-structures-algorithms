#include <cstdlib>
#include <string>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

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

            // check 1: same column?
            if (prevCol == col)
                return false;

            // check 2: same diagonal
            if (abs(prevRow - row) == abs(prevCol - col))
                return false;
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
