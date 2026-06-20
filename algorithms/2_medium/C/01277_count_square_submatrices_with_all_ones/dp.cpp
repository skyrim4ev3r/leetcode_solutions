typedef ptrdiff_t isize;

class Solution {
public:
    static int countSquares(const vector<vector<int>>& matrix) {
        const isize rows = matrix.size();
        const isize cols = matrix[0].size();
        const isize dp_rows = rows + 1;
        const isize dp_cols = cols + 1;
        auto dp = vector<int>(dp_rows * dp_cols, 0);
        int count = 0 ;

        for (isize i = rows - 1; i >= 0; i -= 1) {
            for (isize j = cols - 1; j >= 0; j -= 1) {
                if (matrix[i][j] == 1) {
                    const int r = dp[i * dp_cols + j + 1];
                    const int d = dp[(i + 1) * dp_cols + j];
                    const int rd = dp[(i + 1) * dp_cols + j + 1];

                    dp[i * dp_cols + j] = 1 + std::min(r, std::min(d, rd));
                    count += dp[i * dp_cols + j];
                }
            }
        }

        return count;
    }
};
