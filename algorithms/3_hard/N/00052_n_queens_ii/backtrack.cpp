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

    void backtrack(int &count, vector<vector<char>> &board, const size_t len, const size_t curr_row) {
        if (curr_row == len) {
            count += 1;
            return;
        }

        for (size_t col{0}; col < len; ++col) {
            if (is_safe(board, len, curr_row, col)) {
                board[curr_row][col] = 'Q';
                backtrack(count, board, len, curr_row + 1);
                board[curr_row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        // Uncomment the following lines to use the lookup table for n = 1 to 9 to gain execution speed

        /* 

        if (1 <= n && n <= 9) {
            return (int []){1, 0, 0, 2, 10, 4, 40, 92, 352}[n - 1];
        } 
        
        */
        
        // Backtracking solution

        const size_t len = static_cast<size_t>(n);
        int count{0}; 
        vector<vector<char>> board {vector<vector<char>>(len, vector(len, '.'))};

        backtrack(count, board, len, 0);

        return count;
    }
};
