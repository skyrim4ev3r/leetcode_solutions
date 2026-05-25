static inline bool is_safe(char** board, const size_t len, const size_t i, const size_t j)
{
    for (size_t ofs = 0; ofs <= i; ofs += 1) {
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

void backtrack(char** board, const size_t len, const size_t curr_row, int* count)
{
    if (curr_row == len) {
        *count += 1;
        return;
    }

    for (size_t col = 0; col < len; col += 1) {
        if (is_safe(board, len, curr_row, col)) {
            board[curr_row][col] = 'Q';
            backtrack(board, len, curr_row + 1, count);
            board[curr_row][col] = '.';
        }
    }
}

int totalNQueens(int n)
{
    const size_t len = n;
    int count = 0;
    char** board = (char**) malloc(len * sizeof(char*));
    for (size_t i = 0; i < len; i += 1) {
        board[i] = (char*) malloc(len * sizeof(char));
        for (size_t j = 0; j < len; j += 1) {
            board[i][j] = '.';
        }
    }

    backtrack(board, len, 0, &count);

    for (size_t i = 0; i < len; i += 1) {
        free(board[i]);
    }
    free(board);

    return count;
}
