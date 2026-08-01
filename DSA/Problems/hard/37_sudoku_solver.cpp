#include <array>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        initilizeBoard(board);
        backTracking(board, 0, 0);
    }

   private:
    array<array<bool, 9>, 9> colUsed {};
    array<array<bool, 9>, 9> rowUsed {};
    array<array<bool, 9>, 9> boxUsed {};

    void initilizeBoard(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    int digit = board[row][col] - '0';
                    placeNumber(digit, row, col);
                }
            }
        }
    }

    int getBoxIdx(int row, int col) { return (row / 3) * 3 + (col / 3); }

    bool isSafe(int digit, int row, int col) {
        return !colUsed[col][digit - 1] && !rowUsed[row][digit - 1] &&
               !boxUsed[getBoxIdx(row, col)][digit - 1];
    }

    void placeNumber(int digit, int row, int col) {
        colUsed[col][digit - 1]                 = true;
        rowUsed[row][digit - 1]                 = true;
        boxUsed[getBoxIdx(row, col)][digit - 1] = true;
    }

    void removeNumber(int digit, int row, int col) {
        colUsed[col][digit - 1]                 = false;
        rowUsed[row][digit - 1]                 = false;
        boxUsed[getBoxIdx(row, col)][digit - 1] = false;
    }

    bool backTracking(vector<vector<char>>& board, int row, int col) {
        // End further backTracking, if row become greater than 9
        if (row > 8) {
            return true;
        }

        // Start for next row, if col become greater than 9
        if (col > 8) {
            return backTracking(board, row + 1, 0);
        }

        // Skip, if col already have digit.
        if (board[row][col] != '.') {
            return backTracking(board, row, col + 1);
        }

        for (int digit = 1; digit < 10; digit++) {
            if (!isSafe(digit, row, col)) {
                continue;
            }

            placeNumber(digit, row, col);
            board[row][col] = static_cast<char>('0' + digit);

            const bool isFound = backTracking(board, row, col + 1);
            if (!isFound) {
                removeNumber(digit, row, col);
                board[row][col] = '.';
            } else {
                return true;
            }
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
    print(board, "Final Completed Sudoku Board: ");

    return 0;
}
