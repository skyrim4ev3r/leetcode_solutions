static inline size_t matrix_row_upper_bound(const int** mat, const size_t rows, const int target)
{
    size_t low = 0;
    size_t high = rows - 1;

    while (low <= high && high < rows) {
        const size_t mid = low + (high - low) / 2;
        if (mat[mid][0] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return high;
}

static inline bool binary_search(const int* arr, const size_t len, const int target)
{
    size_t left = 0;
    size_t right = len - 1;

    while (left <= right && right < len) {
        const size_t mid = left + (right - left) / 2;
        if (arr[mid] > target) {
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

static inline bool custom_matrix_binary_search(const int** mat, const size_t rows,
                                               const size_t cols, const int target)
{
    const size_t selected_row = matrix_row_upper_bound(mat, rows, target);
    if (selected_row >= rows) {
        return false;
    }

    return binary_search(mat[selected_row], cols, target);
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    return custom_matrix_binary_search((const int**)matrix, matrixSize, matrixColSize[0], target);
}
