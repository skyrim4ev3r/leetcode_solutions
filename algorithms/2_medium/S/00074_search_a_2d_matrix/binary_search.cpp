class Solution {
    static inline size_t matrix_row_upper_bound(const vector<vector<int>>& mat, const int target) {
        const size_t rows = mat.size();
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
public:
    static bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        const size_t selected_row = matrix_row_upper_bound(matrix, target);
        return selected_row < matrix.size() && binary_search(matrix[selected_row].cbegin(), matrix[selected_row].cend(), target);
    }
};
