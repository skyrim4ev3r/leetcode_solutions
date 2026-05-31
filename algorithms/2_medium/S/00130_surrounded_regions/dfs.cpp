constexpr char ATTACKER = 'X';
constexpr char DEFENDER = 'O';
constexpr char DEFENDER_MARKED = '+';

class Solution {
    static void dfs_mark_defender(
        vector<vector<char>>& board,
        const ptrdiff_t rows,
        const ptrdiff_t cols,
        const ptrdiff_t i,
        const ptrdiff_t j
    ) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != DEFENDER) {
            return;
        }

        board[i][j] = DEFENDER_MARKED;

        const static ptrdiff_t DIRECTIONS[4][2] = {{0 , 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto[dx, dy] : DIRECTIONS) {
            dfs_mark_defender(board, rows, cols, i + dx, j + dy);
        }
    }

    static void mark_defenders_at_edges(vector<vector<char>>& board, const ptrdiff_t rows, const ptrdiff_t cols) {
        for (ptrdiff_t i = 0; i < rows; ++i) {
            dfs_mark_defender(board, rows, cols, i, 0);
            dfs_mark_defender(board, rows, cols, i, cols - 1);
        }

        for (ptrdiff_t j = 0; j < cols; ++j) {
            dfs_mark_defender(board, rows, cols, 0, j);
            dfs_mark_defender(board, rows, cols, rows - 1, j);
        }
    }

public:
    static void solve(vector<vector<char>>& board) {
        const ptrdiff_t rows = board.size();
        const ptrdiff_t cols = board[0].size();

        mark_defenders_at_edges(board, rows, cols);

        for (ptrdiff_t i = 0; i < rows; i += 1) {
            for (ptrdiff_t j = 0; j < cols; j += 1) {
                if (board[i][j] == DEFENDER_MARKED) {
                    board[i][j] = DEFENDER;
                } else if (board[i][j] == DEFENDER) {
                    board[i][j] = ATTACKER;
                }
            }
        }
    }
};
