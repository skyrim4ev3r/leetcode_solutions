#define DIRS_ROWS 8
#define DIRS_COLS 2

const ptrdiff_t directions[DIRS_ROWS][DIRS_COLS] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

void gameOfLife(int** board, int board_size, int* board_col_size)
{
    assert(board != NULL && board_col_size != NULL && board_size > 0 && board_col_size[0] > 0);
    const ptrdiff_t rows = board_size;
    const ptrdiff_t cols = board_col_size[0];

    bool* life_state = malloc((size_t) (rows * cols) * sizeof(*life_state));

    for (ptrdiff_t i = 0; i < rows; i += 1) {
        for (ptrdiff_t j = 0; j < cols; j += 1) {
            int count = 0;

            for (size_t idx_dir = 0; idx_dir < DIRS_ROWS; idx_dir += 1) {
                const ptrdiff_t ni = i + directions[idx_dir][0];
                const ptrdiff_t nj = j + directions[idx_dir][1];

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
