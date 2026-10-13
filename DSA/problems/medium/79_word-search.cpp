#include <cstddef>
#include <utility>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

class Solution {
   public:
    bool exist(const vector<vector<char>>& board, const string& word) {
        foundChars = 0;
        placedBoard.clear();
        maxRow = board.size();
        maxCol = board[0].size();
        placedBoard.reserve(board.size());

        initializePlacedBoard(board.size(), board[0].size());
        return backTracking(board, word, 0, 0);
    }

   private:
    size_t               maxRow;
    size_t               maxCol;
    size_t               foundChars;
    vector<vector<bool>> placedBoard;

    void initializePlacedBoard(size_t row, size_t col) {
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                placedBoard[i][j] = false;
            }
        }
    }

    vector<std::pair<std::size_t, std::size_t>> getPossiblePaths(size_t row, size_t col,
                                                                 const string& word) {
        vector<std::pair<std::size_t, std::size_t>> possiblePaths;

        // Checking is path is possible to go towards TOP
        if (row > 0) {
            if (!placedBoard[row - 1][col] && placedBoard[row - 1][col] == word[foundChars]) {
                possiblePaths.push_back(std::make_pair(row - 1, col));
            }
        }

        // Checking is path is possible to go towards BOTTOM
        if (row < maxRow - 1) {
            if (!placedBoard[row + 1][col] && placedBoard[row + 1][col] == word[foundChars]) {
                possiblePaths.push_back(std::make_pair(row + 1, col));
            }
        }

        // Checking is path is possible to go towards LEFT
        if (col > 0) {
            if (!placedBoard[row][col - 1] && placedBoard[row][col - 1] == word[foundChars]) {
                possiblePaths.push_back(std::make_pair(row, col - 1));
            }
        }

        // Checking is path is possible to go towards RIGHT
        if (col < maxCol - 1) {
            if (!placedBoard[row][col + 1] && placedBoard[row][col + 1] == word[foundChars]) {
                possiblePaths.push_back(std::make_pair(row, col + 1));
            }
        }

        return possiblePaths;
    }

    bool backTracking(const vector<vector<char>>& board, const string& word, size_t row,
                      size_t col) {
        if (foundChars == word.size()) {
            return true;
        }

        if (row >= maxRow) {
            return false;
        }

        if (col >= maxCol) {
            return backTracking(board, word, row + 1, 0);
        }

        for (size_t i = 0; i < maxCol; ++i) {
            vector<std::pair<std::size_t, std::size_t>> possiblePaths =
                getPossiblePaths(row, i, word);

            for (const auto& path : possiblePaths) {
                foundChars += 1;
                placedBoard[path.first][path.second] = true;

                const bool isFound = backTracking(board, word, path.first, path.second);
                if (isFound) {
                    return true;
                }

                foundChars -= 1;
                placedBoard[path.first][path.second] = false;
            }
        }

        return false;
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
