struct vector3d_char {
    char*** res;
    size_t capacity;
    size_t len;
};

static inline struct vector3d_char* vector3d_char_init()
{
    struct vector3d_char* init_vec = (struct vector3d_char*) malloc(sizeof(struct vector3d_char));
    init_vec->res = NULL;
    init_vec->capacity = 0;
    init_vec->len = 0;
    return init_vec;
}

static inline void vector3d_char_into_owned(struct vector3d_char* vec, char****  res,
                                            int* returnSize, int** returnColumnSizes, int n)
{
    vec->res = (char***) realloc(vec->res, vec->len * sizeof(char**));
    *res = vec->res;
    *returnSize = vec->len;
    *returnColumnSizes = (int*) malloc(vec->len * sizeof(int));
    for (size_t i = 0; i < vec->len; i += 1) {
        (*returnColumnSizes)[i] = n;
    }
    vec->res = NULL;
    vec->len = 0;
    vec->capacity = 0;
}

static inline void vector3d_char_auto_increase_cap(struct vector3d_char* vec)
{
    size_t new_capacity = (vec->capacity) * 2;
    if (new_capacity == 0) {
        new_capacity = 1;
    }
    vec->res = (char***) realloc(vec->res, new_capacity * sizeof(char**));
    vec->capacity = new_capacity;
}

static inline void vector3d_char_push(struct vector3d_char* vec, char** new_board)
{
    if (vec->len == vec->capacity) {
        vector3d_char_auto_increase_cap(vec);
    }
    vec->res[vec->len] = new_board;
    vec->len += 1;
}

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

void backtrack(struct vector3d_char* vec, char** board, const size_t len, const size_t curr_row)
{
    if (curr_row == len) {
        char** curr_board = (char**) malloc(len * sizeof(char*));
        for (size_t row = 0; row < len; row += 1) {
            curr_board[row] = (char*) malloc((len + 1) * sizeof(char));
            memcpy(curr_board[row], board[row], len);
            curr_board[row][len] = '\0';
        }
        vector3d_char_push(vec, curr_board);
        return;
    }

    for (size_t col = 0; col < len; col += 1) {
        if (is_safe(board, len, curr_row, col)) {
            board[curr_row][col] = 'Q';
            backtrack(vec, board, len, curr_row + 1);
            board[curr_row][col] = '.';
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    const size_t len = n;
    struct vector3d_char* vec3d = vector3d_char_init(); 
    char** board = (char**) malloc(len * sizeof(char*));
    for (size_t i = 0; i < len; i += 1) {
        board[i] = (char*) malloc(len * sizeof(char));
        for (size_t j = 0; j < len; j += 1) {
            board[i][j] = '.';
        }
    }

    backtrack(vec3d, board, len, 0);

    char*** res = NULL;
    vector3d_char_into_owned(vec3d, &res, returnSize, returnColumnSizes, n);
    for (size_t i = 0; i < len; i += 1) {
        free(board[i]);
    }
    free(board);

    return res;
}
