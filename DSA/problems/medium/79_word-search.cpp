#include <array>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    bool exist(const vector<vector<char>>& board, const string& word) {
        size_t row = board.size();
        size_t col = board[0].size();

        vector<vector<bool>> visitedPaths(row, vector<bool>(col, false));
        for (size_t currRow = 0; currRow < row; ++currRow) {
            for (size_t currCol = 0; currCol < col; ++currCol) {
                if (backTracking(board, word, visitedPaths, currRow, currCol, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

   private:
    array<std::pair<int, int>, 4> kDirections {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

    bool isSafe(const vector<vector<char>>& board, const string& targetWord,
                vector<vector<bool>>& isVisited, size_t row, size_t col, size_t idx) const {
        const bool isInsideBoard =
            row >= 0 && col >= 0 && row < board.size() && col < board[0].size();
        return isInsideBoard && !isVisited[row][col] && board[row][col] == targetWord[idx];
    }

    bool backTracking(const vector<vector<char>>& board, const string& targetWord,
                      vector<vector<bool>>& visitedPaths, size_t currRow, size_t currCol,
                      size_t idx) {
        if (idx == targetWord.size()) {
            return true;
        }

        if (!isSafe(board, targetWord, visitedPaths, currRow, currCol, idx)) {
            return false;
        }

        visitedPaths[currRow][currCol] = true;

        bool isFound = false;
        for (const auto [rowOffset, colOffset] : kDirections) {
            if (backTracking(board, targetWord, visitedPaths, currRow + rowOffset,
                             currCol + colOffset, idx + 1)) {
                isFound = true;
                break;
            }
        }

        visitedPaths[currRow][currCol] = false;

        return isFound;
    }
};

int main() {
    Solution sol;

    std::vector<std::vector<char>> board1 = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    print(sol.exist(board1, "ABCCED"));
    print(sol.exist(board1, "SEE"));
    print(sol.exist(board1, "ABCB"));

    return 0;
}
