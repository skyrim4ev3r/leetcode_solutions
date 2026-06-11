constexpr ptrdiff_t dirs_rows = 8;
constexpr ptrdiff_t dirs_cols = 2;

constexpr ptrdiff_t directions[dirs_rows][dirs_cols] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        assert(board.size() > 0 && board[0].size() > 0);
        const ptrdiff_t rows = board.size();
        const ptrdiff_t cols = board[0].size();

        auto life_state = vector<int>(rows * cols, 0);

        for (ptrdiff_t i = 0; i < rows; i += 1) {
            for (ptrdiff_t j = 0; j < cols; j += 1) {
                int count = 0;

                for (const auto [dx, dy] : directions) {
                    const ptrdiff_t ni = i + dx;
                    const ptrdiff_t nj = j + dy;

                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && board[ni][nj] == 1) {
                        count += 1;
                    }
                }

                const ptrdiff_t idx_life_state = (i * cols) + j;

                if (count > 3) {
                    life_state[idx_life_state] = false;
                } else if (count == 3) {
                    life_state[idx_life_state] = true;
                } else if (count == 2) {
                    if (board[i][j] == 1) {
                        life_state[idx_life_state] = true;
                    } else {
                        life_state[idx_life_state] = false;
                    }
                } else {
                    life_state[idx_life_state] = false;
                }
            }
        }

        for (ptrdiff_t i = 0; i < rows; i += 1) {
            for (ptrdiff_t j = 0; j < cols; j += 1) {
                const ptrdiff_t idx_life_state = (i * cols) + j;

                if (life_state[idx_life_state]) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
