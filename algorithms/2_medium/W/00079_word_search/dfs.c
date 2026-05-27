#define DIR_ROWS 4
#define DIR_COLS 2

static const ssize_t DIRECTIONS[DIR_ROWS][DIR_COLS] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

static void dfs(const char** board, const size_t rows, const size_t cols,
                const size_t i, const size_t j, bool* is_visited, 
                const char* word, const size_t word_idx, bool* is_find)
{
    if (*is_find) { return; }

    if (word[word_idx] == '\0') {
        *is_find = true;
        return;
    }

    if (i >= rows || j >= cols ||is_visited[(i * cols) + j] || board[i][j] != word[word_idx]) {
        return;
    }

    is_visited[(i * cols) + j] = true;

    for (size_t dir_idx = 0; dir_idx < DIR_ROWS; dir_idx += 1) {
        const size_t new_i = (ssize_t) i + DIRECTIONS[dir_idx][0];
        const size_t new_j = (ssize_t) j + DIRECTIONS[dir_idx][1];
        dfs(board, rows, cols, new_i, new_j, is_visited, word, word_idx + 1, is_find);
    }

    is_visited[(i * cols) + j] = false;
}

void clean_is_visited(void* p) 
{
    void* ptr = *(void **) p;
    free(ptr);
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    const size_t rows = boardSize;
    const size_t cols = boardColSize[0];
    const size_t word_idx = 0;
    const size_t is_visited_len = rows * cols;
    bool *is_visited __attribute__((cleanup(clean_is_visited))) = (bool *) malloc(is_visited_len * sizeof(*is_visited));
    memset(is_visited, 0, is_visited_len * sizeof(*is_visited));
    bool is_find = false;

    for (size_t i = 0; i < rows; i += 1) {
        for (size_t j = 0; j < cols; j += 1) {
            dfs((const char**) board, rows, cols, i, j, is_visited, word, word_idx, &is_find);

            if(is_find) {
                return true;
            }
        }
    }

    return false;
}