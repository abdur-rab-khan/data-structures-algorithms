#include <array>
#include <cstdint>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

static constexpr uint8_t BOARD_SIZE = 9;
using BoardT                        = vector<vector<char>>;

class Solution {
   public:
    void solveSudoku(BoardT& board) {
        initializeBoard(board);
        backTracking(board, 0, 0);
    }

   private:
    array<array<bool, BOARD_SIZE>, BOARD_SIZE> rowUsed {};
    array<array<bool, BOARD_SIZE>, BOARD_SIZE> colUsed {};
    array<array<bool, BOARD_SIZE>, BOARD_SIZE> boxUsed {};

    void initializeBoard(const BoardT& board) {
        for (uint8_t row = 0; row < BOARD_SIZE; ++row) {
            for (uint8_t col = 0; col < BOARD_SIZE; ++col) {
                if (board[row][col] != '.') {
                    placeNumber((board[row][col] - '0'), row, col);
                }
            }
        }
    }

    int getBoxIdx(int row, int col) { return (row / 3) * 3 + col / 3; }

    bool isSafe(int digit, int row, int col) {
        int digitIdx = digit - 1;
        return !rowUsed[row][digitIdx] && !colUsed[col][digitIdx] &&
               !boxUsed[getBoxIdx(row, col)][digitIdx];
    }

    void placeNumber(int digit, int row, int col) {
        int digitIdx = digit - 1;

        rowUsed[row][digitIdx]                 = true;
        colUsed[col][digitIdx]                 = true;
        boxUsed[getBoxIdx(row, col)][digitIdx] = true;
    }

    void removeNumber(int digit, int row, int col) {
        int digitIdx = digit - 1;

        rowUsed[row][digitIdx]                 = false;
        colUsed[col][digitIdx]                 = false;
        boxUsed[getBoxIdx(row, col)][digitIdx] = false;
    }

    bool backTracking(BoardT& board, int row, int col) {
        if (row >= BOARD_SIZE) {
            return true;
        }

        if (col >= BOARD_SIZE) {
            return backTracking(board, row + 1, 0);
        }

        if (board[row][col] != '.') {
            return backTracking(board, row, col + 1);
        }

        for (int digit = 1; digit <= BOARD_SIZE; digit++) {
            if (!isSafe(digit, row, col)) {
                continue;
            }

            placeNumber(digit, row, col);
            board[row][col] = '0' + digit;

            bool isFound = backTracking(board, row, col + 1);
            if (isFound) {
                return true;
            }

            removeNumber(digit, row, col);
            board[row][col] = '.';
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
