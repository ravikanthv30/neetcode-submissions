class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
if (board.empty() || board[0].empty() || word.empty()) return false;

        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int idx)
    {
        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[idx]) {
            return false;
        }
        if (idx == static_cast<int>(word.size()) - 1) {
            return true;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark visited in-place

        bool found = backtrack(board, word, r + 1, c, idx + 1) ||
                     backtrack(board, word, r - 1, c, idx + 1) ||
                     backtrack(board, word, r, c + 1, idx + 1) ||
                     backtrack(board, word, r, c - 1, idx + 1);

        board[r][c] = temp; // Backtrack: restore cell
        return found;


    }

};
