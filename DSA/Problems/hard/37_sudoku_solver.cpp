#include <array>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int digit = board[r][c] - '0';
                    placeNumber(digit, r, c);
                }
            }
        }
        backTracking(board, 0, 0);
    }

   private:
    array<array<bool, 10>, 9> rowUsed {};
    array<array<bool, 10>, 9> colUsed {};
    array<array<bool, 10>, 9> boxUsed {};

    int getBoxIndex(int row, int col) { return (row / 3) * 3 + (col / 3); }

    bool isSafe(int digit, int row, int col) {
        int boxIdx = getBoxIndex(row, col);
        return !rowUsed[row][digit] && !colUsed[col][digit] && !boxUsed[boxIdx][digit];
    }

    void placeNumber(int digit, int row, int col) {
        rowUsed[row][digit]                   = true;
        colUsed[col][digit]                   = true;
        boxUsed[getBoxIndex(row, col)][digit] = true;
    }

    void removeNumber(int digit, int row, int col) {
        rowUsed[row][digit]                   = false;
        colUsed[col][digit]                   = false;
        boxUsed[getBoxIndex(row, col)][digit] = false;
    }

    bool backTracking(vector<vector<char>>& board, int row, int col) {
        // basecase if row or col become 9
        if (row == 9) {
            return true;
        }

        if (col == 9) {
            return backTracking(board, row + 1, 0);
        }

        // skip, for already placed number
        if ((board[row][col]) != '.') {
            return backTracking(board, row, col + 1);
        }

        for (int num = 1; num < 10; num++) {
            char charNum = static_cast<char>('0' + num);

            // skip current num, if isn't safe
            if (!isSafe(num, row, col)) {
                continue;
            }

            board[row][col] = charNum;
            placeNumber(num, row, col);
            bool found = backTracking(board, row, col + 1);
            if (found)
                return true;
            board[row][col] = '.';
            removeNumber(num, row, col);
        }

        return false;
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
    print(board, "Completed Sudoku board");

    return 0;
}
