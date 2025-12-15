class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{0 , 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& board, const size_t m, const size_t n, const size_t i, const size_t j) {
        if (i >= m || j >= n || board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'W';

        for (const auto&[dx, dy] : DIRECTIONS) {
            const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

            dfs(board, m, n, new_i, new_j);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        const size_t m{board.size()};
        const size_t n{board[0].size()};

        for (size_t j{0}; j < n; ++j) {
            dfs(board, m, n, 0, j);
            dfs(board, m, n, m - 1, j);
        }

        for (size_t i{0}; i < m; ++i) {
            dfs(board, m, n, i, 0);
            dfs(board, m, n, i, n - 1);
        }

        for (size_t j{0}; j < n; ++j) {
            for (size_t i{0}; i < m; ++i) {
                if (board[i][j] == 'W') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
