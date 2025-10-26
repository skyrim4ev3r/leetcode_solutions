class Solution {
    inline bool __attribute__((always_inline)) is_safe(const vector<vector<char>> &board, const size_t &len, const size_t &i, const size_t &j) {

        for (size_t ofs{0}; ofs < len; ++ofs) {
            if (i < ofs) {
                break;
            }

            if (board[i - ofs][j] == 'Q') {
                return false;
            }

            if (j >= ofs && board[i - ofs][j - ofs] == 'Q') {
                return false;
            }

            if ((j + ofs) < len && board[i - ofs][j + ofs] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<vector<string>> &res, vector<vector<char>> &board, const size_t len, const size_t curr_row) {
        if (curr_row == len) {
            vector<string> curr_board_as_string{};
            curr_board_as_string.reserve(len);

            for (vector<char> &row: board) {
               curr_board_as_string.push_back(string(row.begin(), row.end()));
            }

            res.emplace_back(std::move(curr_board_as_string));
            return;
        }

        for (size_t col{0}; col < len; ++col) {
            if (is_safe(board, len, curr_row, col)) {
                board[curr_row][col] = 'Q';
                backtrack(res, board, len, curr_row + 1);
                board[curr_row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        const size_t len = static_cast<size_t>(n);
        vector<vector<string>> res {}; 
        vector<vector<char>> board {vector<vector<char>>(len, vector(len, '.'))};

        backtrack(res, board, len, 0);

        return res;
    }
};
