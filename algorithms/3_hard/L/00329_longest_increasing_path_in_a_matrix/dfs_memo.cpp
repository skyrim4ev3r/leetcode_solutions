constexpr ptrdiff_t DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
    static int dfs(
        const vector<vector<int>>& matrix,
        vector<int>& memo,
        const ptrdiff_t i,
        const ptrdiff_t j,
        const ptrdiff_t rows,
        const ptrdiff_t cols
    ) {
        if (memo[i * cols + j] != -1) {
            return memo[i * cols + j];
        }

        const int cell_val = matrix[i][j];
        int curr = 1;

        for (const auto [dx, dy] : DIRECTIONS) {
            const ptrdiff_t ni = i + dx;
            const ptrdiff_t nj = j + dy;
            if (ni < 0 || nj < 0 || ni >= rows || nj >= cols || matrix[ni][nj] <= cell_val) {
                continue;
            }
            curr = std::max(curr, 1 + dfs(matrix, memo, ni, nj, rows, cols));
        }

        memo[i * cols + j] = curr;
        return curr;
    }

public:
    static int longestIncreasingPath(const vector<vector<int>>& matrix) {
        assert(std::ssize(matrix) > 0 && std::ssize(matrix[0]) > 0);
        const ptrdiff_t rows = std::ssize(matrix);
        const ptrdiff_t cols = std::ssize(matrix[0]);
        auto memo = vector<int>(rows * cols, - 1);
        int max = 0;

        for (ptrdiff_t i = 0; i < rows; ++i) {
            for (ptrdiff_t j = 0; j < cols; ++j) {
                max = std::max(max, dfs(matrix, memo, i, j, rows, cols));
            }
        }

        return max;
    }
};
