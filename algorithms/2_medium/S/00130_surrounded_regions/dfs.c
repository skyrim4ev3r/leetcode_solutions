#define DIR_ROWS 4
#define DIR_COLS 2
#define ATTACKER 'X'
#define DEFENDER 'O'
#define DEFENDER_MARKED '+'

const static ptrdiff_t DIRECTIONS[DIR_ROWS][DIR_COLS] = {
    {0 , 1}, {0, -1}, {1, 0}, {-1, 0}
};

static void dfs_mark_defender(char** board, const ptrdiff_t rows, const ptrdiff_t cols,
                              const ptrdiff_t i, const ptrdiff_t j)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != DEFENDER) {
        return;
    }

    board[i][j] = DEFENDER_MARKED;

    for (ptrdiff_t idx = 0; idx < DIR_ROWS; idx += 1) {
        dfs_mark_defender(board, rows, cols, i + DIRECTIONS[idx][0], j + DIRECTIONS[idx][1]);
    }
}

static void mark_defenders_at_edges(char** board, const ptrdiff_t rows, const ptrdiff_t cols)
{
    for (ptrdiff_t i = 0; i < rows; i += 1) {
        dfs_mark_defender(board, rows, cols, i, 0);
        dfs_mark_defender(board, rows, cols, i, cols - 1);
    }

    for (ptrdiff_t j = 0; j < cols; j += 1) {
        dfs_mark_defender(board, rows, cols, 0, j);
        dfs_mark_defender(board, rows, cols, rows - 1, j);
    }
}

void solve(char** board, int boardSize, int* boardColSize)
{
    const ptrdiff_t rows = boardSize;
    const ptrdiff_t cols = boardColSize[0];

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
