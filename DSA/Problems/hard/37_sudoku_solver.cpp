#include <cctype>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) { backTracking(board, 0, 0); }

   private:
    bool isSafe(vector<vector<char>>& board, char n, int row, int col) {
        // 1. Check current row and column;
        for (int i = 0; i < 9; i++) {
            // check the column
            if (board[row][i] == n)
                return false;

            // check the row
            if (board[i][col] == n)
                return false;
        }

        // 3. Check current box;
        int rowStart    = (row / 3) * 3;
        int columnStart = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[rowStart + i][columnStart + j] == n)
                    return false;
            }
        }

        return true;
    }

    void backTracking(vector<vector<char>>& board, int row, int col) {
        // basecase to stop further backtracking
        if (row == 9) {
            return;
        }

        // case for calling for next row
        if (col == 9) {
            return backTracking(board, row + 1, 0);
        }

        // skip, don't update already placed number
        if (isalnum(board[row][col])) {
            return backTracking(board, row, col + 1);
        }

        for (int num = 1; num < 10; num++) {
            char charNum = static_cast<char>('0' + num);

            // skip current num, if isn't safe
            if (!isSafe(board, charNum, row, col)) {
                continue;
            }

            board[row][col] = charNum;
            backTracking(board, row, col + 1);
            board[row][col] = '.';
        }
    }
};

int main() {
    Solution             sol;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    sol.solveSudoku(board);
    // print(board, "Completed Sudoku board");

    return 0;
}
